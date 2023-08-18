#include "tetromino.h"

OPiece::OPiece(Grid *grid, std::mt19937 *generator): Tetromino(grid, generator)
{
    _block_arrangements = {
        {{1, 1}, {0,1}, {1, 0}, {0, 0}}
    };
    _blocks = _block_arrangements[0];
    set_position(_center);
}

IPiece::IPiece(Grid *grid, std::mt19937 *generator): Tetromino(grid, generator)
{
    constexpr int i_beam[4][4] = {
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0}
    };

    constexpr int on_side[4][4] = {
        {0, 0, 0, 0},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    _block_arrangements = {
        _visual_grid_to_pos_vec(i_beam),
        _visual_grid_to_pos_vec(on_side),
    };

    _blocks = _block_arrangements[0];
    set_position(_center);
}

ZPiece::ZPiece(Grid *grid, std::mt19937 *generator): Tetromino(grid, generator)
{
    constexpr int default_orientation[4][4] = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 0}
    };

    constexpr int flipped[4][4] = {
        {0, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0}
    };

    _block_arrangements = {
        _visual_grid_to_pos_vec(default_orientation),
        _visual_grid_to_pos_vec(flipped),
    };

    _blocks = _block_arrangements[0];
    set_position(_center);
}

RZPiece::RZPiece(Grid *grid, std::mt19937 *generator): Tetromino(grid, generator)
{
    constexpr int default_orientation[4][4] = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 0}
    };

    constexpr int flipped[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 1, 0, 0}
    };

    _block_arrangements = {
        _visual_grid_to_pos_vec(default_orientation),
        _visual_grid_to_pos_vec(flipped),
    };

    _blocks = _block_arrangements[0];
    set_position(_center);
}


TPiece::TPiece(Grid *grid, std::mt19937 *generator): Tetromino(grid, generator)
{
    constexpr int default_orientation[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 1, 1, 1},
        {0, 0, 0, 0}
    };

    constexpr int to_right[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 1, 0}
    };

    constexpr int flipped[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 1},
        {0, 0, 1, 0}
    };

    constexpr int to_left[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 0}
    };

    _block_arrangements = {
        _visual_grid_to_pos_vec(default_orientation),
        _visual_grid_to_pos_vec(to_right),
        _visual_grid_to_pos_vec(flipped),
        _visual_grid_to_pos_vec(to_left),

    };
    _blocks = _block_arrangements[0];
    set_position(_center);
}


LPiece::LPiece(Grid *grid, std::mt19937 *generator): Tetromino(grid, generator)
{
    constexpr int default_orientation[4][4] = {
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 0}
    };

    constexpr int to_right[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 0}
    };

    constexpr int flipped[4][4] = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };

    constexpr int to_left[4][4] = {
        {0, 0, 0, 0},
        {0, 1, 1, 1},
        {0, 1, 0, 0},
        {0, 0, 0, 0}
    };

    _block_arrangements = {
        _visual_grid_to_pos_vec(default_orientation),
        _visual_grid_to_pos_vec(to_right),
        _visual_grid_to_pos_vec(flipped),
        _visual_grid_to_pos_vec(to_left),

    };
    _blocks = _block_arrangements[0];
    set_position(_center);
}

JPiece::JPiece(Grid *grid, std::mt19937 *generator): Tetromino(grid, generator)
{
    constexpr int default_orientation[4][4] = {
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    constexpr int to_right[4][4] = {
        {0, 0, 0, 0},
        {0, 1, 1, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    constexpr int flipped[4][4] = {
        {0, 0, 1, 1},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };

    constexpr int to_left[4][4] = {
        {0, 1, 0, 0},
        {0, 1, 1, 1},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };

    _block_arrangements = {
        _visual_grid_to_pos_vec(default_orientation),
        _visual_grid_to_pos_vec(to_right),
        _visual_grid_to_pos_vec(flipped),
        _visual_grid_to_pos_vec(to_left),

    };
    _blocks = _block_arrangements[0];
    set_position(_center);
}

Tetromino::Tetromino(Grid *grid, std::mt19937* generator):
                    _grid(grid), _generator(generator)
{
    _distr = std::uniform_int_distribution<>(0, 3);
    _color = _get_random_color();
    set_position(_center);
}

Tetromino::~Tetromino()
{
}

bool Tetromino::move_d()
{
    Position new_center = {_center.x, _center.y + 1};
    return _try_move(new_center);
}

bool Tetromino::move_l()
{
    Position new_center = {_center.x - 1, _center.y};
    return _try_move(new_center);
}

bool Tetromino::move_r()
{
    Position new_center = {_center.x + 1, _center.y};
    return _try_move(new_center);
}

bool Tetromino::rotate_c()
{
    std::cout << "rotate c\n";
    std::vector<Position> new_blocks;
    int next_block_pos = _current_blocks + 1;
    if (static_cast<size_t>(next_block_pos) >= _block_arrangements.size()) {
        next_block_pos = 0;
    }

    if (_try_rotate(_block_arrangements[next_block_pos])) {
        _current_blocks = next_block_pos;
        return true;
    }
    return false;
}

bool Tetromino::rotate_cc()
{
    std::cout << "rotate cc\n";
    std::vector<Position> new_blocks;
    int next_block_pos = _current_blocks - 1;

    if (next_block_pos < 0) {
        next_block_pos = _block_arrangements.size() - 1;
    }

    if (_try_rotate(_block_arrangements[next_block_pos])) {
        _current_blocks = next_block_pos;
        return true;
    }
    return false;
}

void Tetromino::set_position(Position pos)
{
    for (const auto block : _get_blocks_in_grid()) {
        block->set_visible(false);
    }
    _center = pos;

    for (const auto block : _get_blocks_in_grid()) {
        block->set_visible(true);
        block->set_color(_color);
    }
}

std::vector<Block *> Tetromino::_get_blocks_in_grid()
{
    std::vector<Block *> blocks;
    for (const auto block : _blocks) {
        Position block_pos = {_center.x + block.x, _center.y + block.y};
        if (_grid->in_grid(block_pos)) {
            blocks.push_back(_grid->get_block(block_pos));
        }
    }
    return blocks;
}

bool Tetromino::_try_move(Position new_center)
{
    for (const auto block : _get_blocks_in_grid()) {
        block->set_visible(false);
    }

    for (const Position pos : _blocks) {
        Position new_pos = {pos.x + new_center.x, new_center.y + pos.y};
        if (!_grid->in_grid(new_pos, true) || _grid->is_occupied(new_pos)) {
            for (const auto block : _get_blocks_in_grid()) {
                block->set_visible(true);
            }
            return false;
        }
    }
    set_position(new_center);
    return true;
}

bool Tetromino::_try_rotate(std::vector<Position> new_blocks)
{
    for (const auto block : _get_blocks_in_grid()) {
        block->set_visible(false);
    }

    for (const auto pos : new_blocks) {
        Position new_pos = {_center.x + pos.x, _center.y + pos.y};
        if (!_grid->in_grid(new_pos, true) || _grid->is_occupied(new_pos)) {
            for (const auto block : _get_blocks_in_grid()) {
                std::cout << "set visible\n";
                block->set_visible(true);
            }
            return false;
        }
    }
    _blocks = new_blocks;
    set_position(_center);
    return true;
}

sf::Color Tetromino::_get_random_color()
{
    int val = _distr(*_generator);
    std::cout << "val: " << val << "\n";

    switch (val)
    {
    case 0:
        return sf::Color::Blue;
        break;
    case 1:
        return sf::Color::Green;
        break;
    
    case 2:
        return sf::Color::Red;
        break;

    case 3:
        return sf::Color::Yellow;
        break;
    
    default:
        return sf::Color::Blue;
        break;
    }
}

std::vector<Position> Tetromino::_visual_grid_to_pos_vec(const int visual_blocks[4][4])
{
    std::vector<Position> positions;

    for (int row = 0; row < 4; ++row) {
        for (int column = 0; column < 4; ++column) {
            if (visual_blocks[row][column]) {
                positions.push_back(Position{-2 + column, -2 + row});
            }
        }
    }
    return positions;
}
