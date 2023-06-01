#include "Target.hpp"


Target::Target(Color color, Symbol symbol, Position position) : color(color), symbol(symbol), position(position) {}

Color Target::getColor() const {
    return color;
}

Symbol Target::getSymbol() const {
    return symbol;
}

Position Target::getPosition() const {
    return position;
}

void Target::setPosition(Position newPosition) {
    position = newPosition;
}

// abfdfngkjdfn