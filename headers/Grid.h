#ifndef GAME_2048_GRID_H
#define GAME_2048_GRID_H

#include <vector>
#include "SFML/Graphics.hpp"
#include "Tile.h"

class Grid {
    enum Directions {
        North,
        East,
        South,
        West
    };

public:
    std::vector<std::vector<Tile>> grid;
    sf::Vector2f position;
    sf::RectangleShape shape;

    Grid();

    void squash(Directions direction);
    void set_tile(int value, int row, int col);
    void draw(sf::RenderWindow &window);
};


#endif //GAME_2048_GRID_H
