#pragma once
#include <sstream>
#include "IShape.h"

class ShapeFormatter 
{
public:
    static std::string Format(const IShape& shape);

private:
    static std::string FormatNumber(double value);
};