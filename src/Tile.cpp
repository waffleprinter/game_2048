#include "Tile.h"

Tile::Tile(int value, sf::Vector2f position) {
    this->value = value;
    this->position = position;

    this->shape.setSize(sf::Vector2f(100, 100));
    this->shape.setPosition(this->position);
    this->shape.setOutlineThickness(5.0f);
    this->shape.setOutlineColor(sf::Color::Red);
}

void Tile::draw(sf::RenderWindow &window) {
    window.draw(this->shape);
}
