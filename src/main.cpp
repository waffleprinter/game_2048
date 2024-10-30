#include <Tile.h>
#include <SFML/Graphics.hpp>


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event{};

    Tile tile = Tile(10, sf::Vector2f(200, 100));

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        tile.draw(window);

        window.display();
    }
}
