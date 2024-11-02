#ifndef GAME_2048_GRID_H
#define GAME_2048_GRID_H

#include <memory>
#include <array>
#include <random>

#include "SFML/Graphics.hpp"
#include "Tile.h"
#include "Constants.h"

class Grid {
    enum Directions {
        North,
        East,
        South,
        West
    };

public:
    std::array<std::array<std::unique_ptr<Tile>, Constants::COLS>, Constants::ROWS> grid;
    sf::Vector2f position;
    sf::RectangleShape shape;

    Grid();

    void squash(Directions direction);
    void set_tile(int value, int row, int col);
    void update();
    void draw(sf::RenderWindow &window);
    std::pair<int, int> get_random_empty_coords();
    void add_random_tile();
};


#endif //GAME_2048_GRID_H
