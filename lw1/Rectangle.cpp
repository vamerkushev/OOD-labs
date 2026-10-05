#include "Rectangle.h"

Rectangle::Rectangle(const CPoint& p1, const CPoint& p2)
    : ShapeAdapter<sf::RectangleShape>(Config::TYPE_RECTANGLE), m_p1(p1), m_p2(p2) 
{
    float width = static_cast<float>(std::abs(p2.x - p1.x));
    float height = static_cast<float>(std::abs(p2.y - p1.y));

    m_sfmlShape.setSize(sf::Vector2f(width, height));
    m_sfmlShape.setPosition(static_cast<float>(std::min(p1.x, p2.x)), static_cast<float>(std::min(p1.y, p2.y)));
    m_sfmlShape.setFillColor(sf::Color::White);
    m_sfmlShape.setOutlineColor(sf::Color::Black);
    m_sfmlShape.setOutlineThickness(2.f);
}

double Rectangle::GetArea() const 
{
    return std::abs((m_p2.x - m_p1.x) * (m_p2.y - m_p1.y));
}

double Rectangle::GetPerimeter() const 
{
    double width = std::abs(m_p2.x - m_p1.x);
    double height = std::abs(m_p2.y - m_p1.y);
    return Config::TWO_FOR_PERIMETER * (width + height);
}

void Rectangle::Accept(IShapeVisitor& visitor) const 
{
    visitor.Visit(*this);
}