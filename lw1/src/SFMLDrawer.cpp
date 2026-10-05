#include "SFMLDrawer.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "IShape.h"

SFMLDrawer::SFMLDrawer(sf::RenderWindow& window) : m_window(window) {}

void SFMLDrawer::Visit(const Circle& shape)
{
    m_window.draw(shape.GetSFMLShape());
}

void SFMLDrawer::Visit(const Rectangle& shape)
{
    m_window.draw(shape.GetSFMLShape());
}

void SFMLDrawer::Visit(const Triangle& shape)
{
    m_window.draw(shape.GetSFMLShape());
}

void SFMLDrawer::Render(const std::vector<std::unique_ptr<IShape>>& shapes)
{
    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }
        }

        m_window.clear(sf::Color::White);
        for (const auto& shape : shapes)
        {
            shape->Accept(*this);
        }
        m_window.display();
    }
}