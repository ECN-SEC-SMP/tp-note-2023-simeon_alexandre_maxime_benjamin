#include "Board.hpp"


Board::Board(int size) : size(size) {
    walls.resize(size, std::vector<bool>(size, false));
}

int Board::getSize() const {
    return size;
}

bool Board::isWall(int x, int y) const {
    if (x < 0 || x >= size || y < 0 || y >= size) {
        return true; // Consider out-of-bounds as wall
    }
    return walls[x][y];
}

void Board::setWall(int x, int y, bool hasWall) {
    if (x >= 0 && x < size && y >= 0 && y < size) {
        walls[x][y] = hasWall;
    }
}
