#include <SFML/Graphics.hpp>
#include "grid.h"
#include "tetromino.h"
#include <memory>

#include <random>

int main()
{
    Grid grid(30);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 6);

    std::unique_ptr<Tetromino> tetromino = std::make_unique<IPiece>(&grid, &gen);

    sf::RenderWindow window(sf::VideoMode(1000, 500), "Pruutsis");
    window.setFramerateLimit(60);
    size_t down_divider = 0;
    size_t down_limit = 30;

    while (window.isOpen())
    {
        ++down_divider;
        if (down_divider >= down_limit) {
            down_divider = 0;
            if (!tetromino->move_d()) {
                
                auto cleared = grid.check_rows();
                for (int row : cleared) {
                    grid.clear_row(row);
                }

                int val = distr(gen);
                switch (val)
                {
                case 0:
                    tetromino = std::make_unique<IPiece>(&grid, &gen);
                    break;
                case 1:
                    tetromino = std::make_unique<ZPiece>(&grid, &gen);
                    break;
                case 2:
                    tetromino = std::make_unique<OPiece>(&grid, &gen);
                    break;
                case 3:
                    tetromino = std::make_unique<TPiece>(&grid, &gen);
                    break;
                case 4:
                    tetromino = std::make_unique<RZPiece>(&grid, &gen);
                    break;
                case 5:
                    tetromino = std::make_unique<LPiece>(&grid, &gen);
                    break;
                case 6:
                    tetromino = std::make_unique<JPiece>(&grid, &gen);
                    break;
                default:
                    break;
                }
            }
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed) {
                switch (event.key.code)
                {
                case sf::Keyboard::Left:
                case sf::Keyboard::A:
                    tetromino->move_l();
                    break;
                case sf::Keyboard::Right:
                case sf::Keyboard::D:
                    tetromino->move_r();
                    break;
                case sf::Keyboard::Down:
                case sf::Keyboard::S:
                    tetromino->move_d();
                    break;
                case sf::Keyboard::Up:
                case sf::Keyboard::W:
                    while(tetromino->move_d()) {
                    }
                    down_divider = down_limit;
                    break;
                case sf::Keyboard::Z:
                    tetromino->rotate_cc();
                    break;
                case sf::Keyboard::X:
                    tetromino->rotate_c();
                    break;
                default:
                    break;
                }
            }
        }
        window.clear();
        grid.draw(window);
        window.display();
    }

    return 0;
}