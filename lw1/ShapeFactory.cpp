#include "ShapeFactory.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

std::unique_ptr<IShape> ShapeFactory::Create(const ShapeParser::ParsedData& data) 
{
    if (data.type == Config::TYPE_TRIANGLE && data.points.size() == 3) 
    {
        return std::make_unique<Triangle>(data.points[0], data.points[1], data.points[2]);
    }
    if (data.type == Config::TYPE_RECTANGLE && data.points.size() == 2) 
    {
        return std::make_unique<Rectangle>(data.points[0], data.points[1]);
    }
    if (data.type == Config::TYPE_CIRCLE && data.points.size() == 1) 
    {
        return std::make_unique<Circle>(data.points[0], data.radius);
    }

    return nullptr;
}