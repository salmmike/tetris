#include "block.h"
#include <iostream>

Block::Block()
{
    _shape.setOutlineColor(sf::Color::White);
    _shape.setOutlineThickness(1.0F);
}

Block::~Block()
{
}

void Block::set_pos(Position pos)
{
    _pos = pos;
    _shape.setPosition(sf::Vector2f(pos.x * _width, pos.y * _width));
}

void Block::set_color(const sf::Color &color)
{
    _color = color;
    _shape.setFillColor(color);
}

void Block::set_width(float width)
{
    _width = width;
    _shape.setSize(sf::Vector2f(width, width));
}

void Block::set_visible(bool visible)
{
    _visible = visible;
}

bool Block::is_occupied() const
{
    return _visible;
}

void Block::draw(sf::RenderWindow &window)
{
    if (!_visible) {
        _shape.setFillColor(sf::Color::Black);
    }
    window.draw(_shape);
}

sf::Color Block::get_color()
{
    return _color;
}

bool Block::get_visible()
{
    return _visible;
}
