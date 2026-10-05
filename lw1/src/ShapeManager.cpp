#include "ShapeParser.h"
#include "ShapeFactory.h"
#include "ShapeFormatter.h"
#include "ShapeManager.h"
#include <iostream>
#include <fstream>
#include "Config.h"

bool ShapeManager::LoadFromFile(const std::string& filename) 
{
    std::ifstream inFile(filename);
    if (!inFile.is_open()) 
    {
        std::cerr << Config::ERROR_OPEN_FILE << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(inFile, line)) 
    {
        if (!line.empty()) 
        {
            ShapeParser::ParsedData data = ShapeParser::Parse(line);
            auto shape = ShapeFactory::Create(data);
            if (shape) 
            {
                shapes_.push_back(std::move(shape));
            }
        }
    }

    if (shapes_.empty()) 
    {
        std::cerr << Config::ERROR_NO_SHAPES << std::endl;
        return false;
    }

    return true;
}

void ShapeManager::SaveToFile(const std::string& filename) const 
{
    std::ofstream outFile(filename);
    if (!outFile.is_open()) 
    {
        std::cerr << Config::ERROR_OPEN_FILE << filename << std::endl;
        return;
    }

    for (const auto& shape : shapes_) 
    {
        outFile << ShapeFormatter::Format(*shape) << "\n";
    }

    std::cout << Config::WRITE_RESULT_TO << filename << std::endl;
}

void ShapeManager::PrintToConsole() const 
{
    std::cout << Config::PROCESSED_SHAPES << shapes_.size() << "\n";
    for (const auto& shape : shapes_) 
    {
        std::cout << ShapeFormatter::Format(*shape) << "\n";
    }
}

const std::vector<std::unique_ptr<IShape>>& ShapeManager::GetShapes() const 
{
    return shapes_;
}