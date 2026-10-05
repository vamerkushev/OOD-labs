#pragma once
#include "ShapeAdapter.h"
#include "CPoint.h"

class Circle : public ShapeAdapter<sf::CircleShape> 
{
public:
    Circle(const CPoint& center, double radius);
    double GetArea() const;
    double GetPerimeter() const;
    void Accept(IShapeVisitor& visitor) const;

private:
    CPoint m_center;
    double m_radius;
};