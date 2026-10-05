#include "ShapeFormatter.h"
#include "Config.h"
#include <sstream>
#include <iomanip>

std::string ShapeFormatter::Format(const IShape& shape) 
{
    std::ostringstream oss;
    oss << shape.GetName()
        << Config::OUTPUT_SEPARATOR
        << Config::PERIMETER_PREFIX << FormatNumber(shape.GetPerimeter())
        << Config::VALUES_SEPARATOR
        << Config::AREA_PREFIX << FormatNumber(shape.GetArea());
    return oss.str();
}

std::string ShapeFormatter::FormatNumber(double value) 
{
    if (value == static_cast<int>(value)) 
    {
        return std::to_string(static_cast<int>(value));
    }
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << value;
    return oss.str();
}