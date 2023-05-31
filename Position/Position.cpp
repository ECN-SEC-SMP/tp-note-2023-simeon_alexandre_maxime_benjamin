#include "Position.hpp"

Position::Position(int x, int y) : x(x), y(y) {}

int Position::getX() const {
    return x;
}

int Position::getY() const {
    return y;
}

void Position::setX(int newX) {
    x = newX;
}

void Position::setY(int newY) {
    y = newY;
}
