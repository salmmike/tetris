#include "tetromino.h"



OPiece::OPiece(Grid *grid, std::mt19937 *generator): Tetromino(grid, generator, {{1, 1}, {0,1}, {1, 0}, {0, 0}})
{
    _block_arrangements = {
        {{1, 1}, {0,1}, {1, 0}, {0, 0}}
    };
}

IPiece::IPiece(Grid *grid, std::mt19937 *generator): Tetromino(grid, generator, {{0, -2}, {0, -1}, {0, 0}, {0, 1}})
{
    _block_arrangements = {
        {{0, -2}, {0, -1}, {0, 0}, {0, 1}},
        {{-2, 0}, {-1,0}, {0, 0}, {1, 0}}
    };
}

ZPiece::ZPiece(Grid *grid, std::mt19937 *generator): Tetromino(grid, generator, {{0, 1}, {0,0}, {1, 0}, {1, -1}})
{
    _block_arrangements = {
        {{0, 1}, {0,0}, {1, 0}, {1, -1}},
        {{-1, 0}, {0,0}, {0, 1}, {1, 1}},
    };
}

TPiece::TPiece(Grid *grid, std::mt19937 *generator): Tetromino(grid, generator, {{-1, 0}, {0, 0}, {1, 0}, {0, 1}})
{
    _block_arrangements = {

        {{-1, 0}, {0, 0}, {1, 0}, {0, 1}},
        {{0, 0}, {0, 1}, {0, -1}, {1, 0}},
        {{-1, 0}, {0, 0}, {1, 0}, {0, -1}},
        {{0, 0}, {0, 1}, {0, -1}, {-1, 0}},
    };
}

Tetromino::Tetromino(Grid *grid, std::mt19937* generator, std::vector<Position> blocks):
                    _grid(grid), _generator(generator), _blocks(blocks)
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
