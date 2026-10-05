#pragma once
#include "ShapeAdapter.h"
#include "CPoint.h"

class Triangle : public ShapeAdapter<sf::ConvexShape>
{
public:
	Triangle(const CPoint& p1, const CPoint& p2, const CPoint& p3);
	double GetArea() const;
	double GetPerimeter() const;
	void Accept(IShapeVisitor& visitor) const;

private:
	CPoint m_p1, m_p2, m_p3;
};