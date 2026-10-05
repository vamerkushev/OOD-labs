#include "Circle.h"

Circle::Circle(const CPoint& center, double radius)
    : ShapeAdapter<sf::CircleShape>(Config::TYPE_CIRCLE), m_center(center), m_radius(radius) 
{
    m_sfmlShape.setRadius(static_cast<float>(radius));
    m_sfmlShape.setPosition({ static_cast<float>(center.x - radius), static_cast<float>(center.y - radius) });
    m_sfmlShape.setFillColor(sf::Color::White);
    m_sfmlShape.setOutlineColor(sf::Color::Black);
    m_sfmlShape.setOutlineThickness(2.f);
}

double Circle::GetArea() const 
{
    return Config::PI * m_radius * m_radius;
}

double Circle::GetPerimeter() const 
{
    return Config::TWO_FOR_PERIMETER * Config::PI * m_radius;
}

void Circle::Accept(IShapeVisitor& visitor) const 
{
    visitor.Visit(*this);
}