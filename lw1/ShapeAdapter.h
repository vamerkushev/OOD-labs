#pragma once
#include "IShape.h"
#include <SFML/Graphics.hpp>

template <typename TSfmlShape>
class ShapeAdapter : public IShape 
{
public:
    explicit ShapeAdapter(std::string name) : m_name(std::move(name)) {}

    std::string GetName() const 
    {
        return m_name;
    }

    const TSfmlShape& GetSFMLShape() const 
    {
        return m_sfmlShape;
    }

protected:
    TSfmlShape m_sfmlShape;
    std::string m_name;
};