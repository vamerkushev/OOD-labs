#pragma once

class Circle;
class Rectangle;
class Triangle;

class IShapeVisitor 
{
public:
    virtual ~IShapeVisitor() = default;
    virtual void Visit(const Circle& shape) = 0;
    virtual void Visit(const Rectangle& shape) = 0;
    virtual void Visit(const Triangle& shape) = 0;
};