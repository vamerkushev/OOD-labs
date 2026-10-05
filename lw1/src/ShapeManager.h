#pragma once
#include <vector>
#include <memory>
#include <string>
#include "IShape.h"

class ShapeManager {
public:
    bool LoadFromFile(const std::string& filename);
    void SaveToFile(const std::string& filename) const;
    void PrintToConsole() const;
    const std::vector<std::unique_ptr<IShape>>& GetShapes() const;

private:
    std::vector<std::unique_ptr<IShape>> shapes_;
};