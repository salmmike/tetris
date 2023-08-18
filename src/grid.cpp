#include "grid.h"

Grid::Grid(float block_size)
{
    for (int i = 0; i < _width * _height; ++i) {
        _blocks.push_back(std::make_unique<Block>());
    }

    for (int y = 0; y < _height; ++y) {
        for (int x = 0; x < _width; ++x) {
            Block* block = get_block({x, y});
            block->set_width(block_size);
            block->set_pos({x, y});
        }
    }
}

Grid::~Grid()
{
}

Block *Grid::get_block(Position pos) const
{
    if (pos.x > _width || pos.y > _height) {
        return nullptr;
    }

    size_t index = pos.y * _width + pos.x;
    return _blocks[index].get();
}

bool Grid::in_grid(Position pos, bool allow_on_top) const
{
    return pos.x >= 0 && (pos.y >= 0 || allow_on_top) && pos.x < _width && pos.y < _height;
}

bool Grid::is_occupied(Position pos) const
{
    if (!in_grid(pos)) {
        return false;
    }
    return get_block(pos)->is_occupied();
}

void Grid::draw(sf::RenderWindow &window)
{
    for (const auto &block : _blocks) {
        block.get()->draw(window);
    }
}

bool Grid::check_row(int row)
{
    for (int x = 0; x < _width; ++x) {
        if (!is_occupied({x, row})) {
            return false;
        }
    }
    return true;
}

std::vector<int> Grid::check_rows()
{
    std::vector<int> cleared;
    for (int row = 0; row < _height; ++ row) {
        if (check_row(row)) {
            cleared.push_back(row);
        }
    }
    return cleared;
}

void Grid::clear_row(int row)
{
    for (auto block : get_row(row)) {
        block->set_visible(false);        
    }

    for (int i = row; i > 0; --i) {
        auto row_above = get_row(i - 1);
        auto row_to_drop_to = get_row(i);

        for (size_t k = 0; k < row_above.size(); ++k) {
            row_to_drop_to[k]->set_color(row_above[k]->get_color());
            row_to_drop_to[k]->set_visible(row_above[k]->get_visible());
        }
    }
}

std::vector<Block *> Grid::get_row(int row)
{
    std::vector<Block *> blocks;
    for (int i = 0; i < _width; ++i) {
        blocks.push_back(get_block({i, row}));
    }
    return blocks;
}
