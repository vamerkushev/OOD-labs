#pragma once
#include "ShapeAdapter.h"
#include "CPoint.h"

class Rectangle : public ShapeAdapter<sf::RectangleShape> 
{
public:
    Rectangle(const CPoint& p1, const CPoint& p2);
    double GetArea() const;
    double GetPerimeter() const;
    void Accept(IShapeVisitor& visitor) const;

private:
    CPoint m_p1, m_p2;
};