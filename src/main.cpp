#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Grid.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 960), "2048", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event{};

    Grid grid = Grid();

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


    }
}
