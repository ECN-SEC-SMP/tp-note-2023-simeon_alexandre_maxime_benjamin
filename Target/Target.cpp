#include "Target.hpp"


Target::Target(Color color, Symbol symbol) : color(color), symbol(symbol) {}

Color Target::getColor() const {
    return color;
}

Symbol Target::getSymbol() const {
    return symbol;
}