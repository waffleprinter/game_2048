#include "Grid.h"

Grid::Grid() {

}

void Grid::squash(Grid::Directions direction) {

}

void Grid::set_tile(int value, int row, int col) {
    Tile& tile = grid[row][col];
    tile.value = value;
}

void Grid::draw(sf::RenderWindow &window) {
    // ADD THE SHAPE

    for (const std::vector<Tile> &row : grid) {
        for (const Tile &tile : row) {
            tile.draw(window);
        }
    }
}
