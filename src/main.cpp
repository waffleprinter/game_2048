#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Grid.h"


int main() {
    float width = Constants::COLS * (Constants::TILE_SIZE + Constants::TILE_PADDING) + Constants::TILE_PADDING;
    float height = Constants::ROWS * (Constants::TILE_SIZE + Constants::TILE_PADDING) + Constants::TILE_PADDING;
    sf::RenderWindow window(sf::VideoMode(width, height), "2048", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event{};

    Grid grid = Grid();
    grid.position = sf::Vector2f(0, 0);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        grid.update();

        window.clear(sf::Color(200, 200, 200));

        grid.draw(window);

        window.display();
    }
}
