#ifndef BLOCK_H
#define BLOCK_H

#include <cstddef>
#include <SFML/Graphics.hpp>

struct Position {
    int x;
    int y;
};

class Block {
public:
    Block();
    ~Block();

    /// @brief set the block position.
    void set_pos(Position pos);

    /// @brief set the color of the block
    void set_color(const sf::Color &color);

    /// @brief set the block width
    /// @param width 
    void set_width(float width);

    /// @brief set the block visiblity
    /// @param visible true for visible
    void set_visible(bool visible);

    /// @brief check if the block is occupied or free
    /// @return True if the block is occupied
    [[nodiscard]] bool is_occupied() const;

    /// @brief draw the block at its current position
    void draw(sf::RenderWindow &window);

    sf::Color get_color();
    bool get_visible();

private:
    Position _pos;
    float _width;
    bool _visible;
    sf::Color _color;
    sf::RectangleShape _shape;
};

#endif /* BLOCK_H */
