#ifndef GAME_2048_TILE_H
#define GAME_2048_TILE_H

#include <array>
#include <cmath>

#include "SFML/Graphics.hpp"
#include "Constants.h"

class Tile {
    constexpr static std::array<std::array<int, 3>, 9> COLORS = {{
            {237, 229, 218},
            {238, 225, 201},
            {243, 178, 122},
            {246, 150, 101},
            {247, 124, 95},
            {247, 95, 59},
            {237, 208, 115},
            {237, 204, 99},
            {236, 202, 80},
    }};

public:
    int value;
    sf::Vector2f position;
    sf::RectangleShape shape;
    sf::Text value_text;
    sf::Font value_font;

    Tile(int val, sf::Vector2f pos);

    void draw(sf::RenderWindow& window);

private:
    sf::Color get_color() const;
};


#endif //GAME_2048_TILE_H
