#include <SFML/Graphics.hpp>
#include "Tile.h"


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event{};

    Tile tile(2, sf::Vector2f(200, 200));

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color(200, 200, 200));

        tile.draw(window);

        window.display();
    }
}
