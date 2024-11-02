#include <iostream>
#include "Tile.h"

Tile::Tile(int val) {
    value = val;

    shape.setFillColor(get_color());
    shape.setSize(sf::Vector2f(Constants::TILE_SIZE, Constants::TILE_SIZE));

    value_font.loadFromFile("../assets/Roboto-Bold.ttf");
    value_text.setFont(value_font);
    value_text.setFillColor(sf::Color::Black);
    value_text.setCharacterSize(Constants::TILE_CHAR_SIZE);
}

void Tile::update() {
    shape.setPosition(position);

    value_text.setString(std::to_string(value));
    sf::FloatRect text_bounds = value_text.getLocalBounds();
    value_text.setOrigin(text_bounds.width / 2, text_bounds.height);
    value_text.setPosition(position.x + Constants::TILE_SIZE / 2, position.y + Constants::TILE_SIZE / 2);
}

void Tile::draw(sf::RenderWindow &window) const {
    window.draw(shape);
    window.draw(value_text);
}

sf::Color Tile::get_color() const {
    auto color_index = (int)std::log2(value) - 1;
    return sf::Color(COLORS[color_index][0], COLORS[color_index][1], COLORS[color_index][2]);
}

