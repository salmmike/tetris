#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "block.h"

#define GRID_WIDTH 10
#define GRID_HEIGHT 20

class Grid {
public:
    Grid(float block_size);
    ~Grid();

    /// @brief Set a block state in position
    /// @param pos Position of the block
    /// @param color sf::Color color of the block
    /// @param filled boolean value if the space is occupied or empty
    void set_block(Position pos, const sf::Color &color, bool filled);

    /// @brief Return block at index x, y
    /// @param pos Position of the block
    /// @return pointer to Block in x, y
    Block* get_block(Position pos) const;

    /// @brief Check if the position is in grid
    /// @param pos Position of the block
    /// @return 
    [[nodiscard]] bool in_grid(Position pos, bool allow_on_top=false) const;

    /// @brief check if the position is occupied.
    /// @param pos Position to check
    /// @return True if block in grid is filled.
    [[nodiscard]] bool is_occupied(Position pos) const;

    void draw(sf::RenderWindow& window);

    /// @brief Check if row is filled and should be cleared
    /// @param row the row to check
    /// @return True if row is full
    [[nodiscard]] bool check_row(int row);

    
    /// @brief checks all rows for filled rows and removes them
    /// @return number of rows cleared.
    std::vector<int> check_rows();

    /// @brief Clears row, drops every block above it by one.
    /// @param row the row to clear.
    void clear_row(int row);

    std::vector<Block*> get_row(int row);

private:
    std::vector<std::unique_ptr<Block>> _blocks;
    int _width {GRID_WIDTH};
    int _height {GRID_HEIGHT};
    int _block_side;

};

#endif /* GRID_H */
