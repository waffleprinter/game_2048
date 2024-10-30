#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Test", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;

    sf::RectangleShape rectangle(sf::Vector2f(200, 100));
    rectangle.setPosition(100, 100);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        window.draw(rectangle);

        window.display();
    }
}
