#pragma once
#include <string>
#include "IShapeVisitor.h"

class IShape 
{
public:
    virtual ~IShape() = default;

    virtual double GetArea() const = 0;
    virtual double GetPerimeter() const = 0;
    virtual std::string GetName() const = 0;

    virtual void Accept(IShapeVisitor& visitor) const = 0;
};