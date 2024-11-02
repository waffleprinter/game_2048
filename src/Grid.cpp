#include "Grid.h"

Grid::Grid() {
    float width = Constants::COLS * (Constants::TILE_SIZE + Constants::TILE_PADDING) + Constants::TILE_PADDING;
    float height = Constants::ROWS * (Constants::TILE_SIZE + Constants::TILE_PADDING) + Constants::TILE_PADDING;
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color(205, 192, 180));

    for (int i = 0; i < 10; i++) {
        add_random_tile();
    }
}

void Grid::squash(Grid::Directions direction) {

}

void Grid::set_tile(int value, int row, int col) {
    if (grid[row][col] != nullptr) {
        grid[row][col]->value = value;
    } else {
        grid[row][col] = std::make_unique<Tile>(value);
    }
}

void Grid::update() {
    shape.setPosition(position);

    for (const std::array<std::unique_ptr<Tile>, Constants::COLS> &row : grid) {
        for (const std::unique_ptr<Tile> &tile : row) {
            if (tile != nullptr) tile->update();
        }
    }
}

void Grid::draw(sf::RenderWindow &window) {
    window.draw(shape);

    for (const std::array<std::unique_ptr<Tile>, Constants::COLS> &row : grid) {
        for (const std::unique_ptr<Tile> &tile : row) {
            if (tile != nullptr) tile->draw(window);
        }
    }
}

std::pair<int, int> Grid::get_random_empty_coords() {
    std::vector<std::pair<int, int>> coord_candidates;

    for (int row = 0; row < Constants::ROWS; row++) {
        for (int col = 0; col < Constants::COLS; col++) {
            if (grid[row][col] == nullptr) {
                coord_candidates.emplace_back(row, col);
            }
        }
    }

    return coord_candidates[std::rand() % coord_candidates.size()]; // rand() because it doesn't matter at all
}

void Grid::add_random_tile() {
    std::pair<int, int> random_empty_coords = get_random_empty_coords();
    int row = random_empty_coords.first;
    int col = random_empty_coords.second;

    grid[row][col] = std::make_unique<Tile>(2);

    int x = col * (Constants::TILE_SIZE + Constants::TILE_PADDING) + Constants::TILE_PADDING;
    int y = row * (Constants::TILE_SIZE + Constants::TILE_PADDING) + Constants::TILE_PADDING;
    grid[row][col]->position = sf::Vector2f(x, y);
}

