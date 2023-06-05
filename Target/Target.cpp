#include "Target.hpp"


Target::Target(Color _color, Symbol _symbol, Position _position) : color(_color), symbol(_symbol), position(_position) {}

Color Target::getColor() const {
    return color;
}

Symbol Target::getSymbol() const {
    return symbol;
}