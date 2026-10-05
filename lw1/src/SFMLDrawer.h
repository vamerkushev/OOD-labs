#pragma once
#include "IShapeVisitor.h"
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

class Circle;
class Rectangle;
class Triangle;
class IShape;

class SFMLDrawer : public IShapeVisitor {
public:
    explicit SFMLDrawer(sf::RenderWindow& window);

    void Visit(const Circle& shape);
    void Visit(const Rectangle& shape);
    void Visit(const Triangle& shape);

    void Render(const std::vector<std::unique_ptr<IShape>>& shapes);

private:
    sf::RenderWindow& m_window;
};