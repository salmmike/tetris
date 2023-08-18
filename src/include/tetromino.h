#ifndef TETROMINO_H
#define TETROMINO_H

#include <vector>
#include <memory>
#include <random>

#include "block.h"
#include "grid.h"

class Tetromino {
public:
    Tetromino(Grid* grid, std::mt19937* generator, std::vector<Position> blocks);

    ~Tetromino();

    /// @brief move tetromino down
    /// @return true if the tetromino was able to move
    bool move_d();

    /// @brief move tetromino to left
    /// @return true if the tetromino was able to move
    bool move_l();

    /// @brief move tetromino to right
    /// @return true if the tetromino was able to move
    bool move_r();

    /// @brief rotate tetromino clockwise
    /// @return true if the tetromino was able to rotate
    bool rotate_c();

    /// @brief rotate tetromino counterclockwise
    /// @return true if the tetromino was able to rotate
    bool rotate_cc();

    /// @brief set the position of the tetromino center
    /// @details clears the old blocks and sets the new position blocks visible
    /// @param pos New center of the tetromino
    void set_position(Position pos);

protected:
    /// @brief Center of the tetromino
    Position _center {5, 0};
    sf::Color _color;
    Grid* _grid;
    std::mt19937* _generator;
    std::uniform_int_distribution<> _distr;
    /// @brief Position of each block relative to the center
    std::vector<Position> _blocks;

    std::vector<Block*> _get_blocks_in_grid();
    bool _try_move(Position new_center);
    bool _try_rotate(std::vector<Position> new_blocks);
    sf::Color _get_random_color();

    std::vector<std::vector<Position>> _block_arrangements;
    int _current_blocks {0};
};

class IPiece : public Tetromino
{
public:
    IPiece(Grid* grid, std::mt19937* generator);
};

class OPiece : public Tetromino
{
public:
    OPiece(Grid* grid, std::mt19937* generator);
};

class ZPiece : public Tetromino
{
public:
    ZPiece(Grid* grid, std::mt19937* generator);
};

class TPiece : public Tetromino
{
public:
    TPiece(Grid* grid, std::mt19937* generator);
};

#endif /* TETROMINO_H */
