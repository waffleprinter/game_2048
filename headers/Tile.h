#ifndef GAME_2048_TILE_H
#define GAME_2048_TILE_H

#include <SFML/Graphics.hpp>

class Tile {
private:
    sf::RectangleShape shape;

public:
    Tile(int value, sf::Vector2f position);

    int value;
    sf::Vector2f position;

    void draw(sf::RenderWindow &window);
};


#endif //GAME_2048_TILE_H
