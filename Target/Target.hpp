#pragma once 
#include "string.h"
#include "stdlib.h"

#include "../Position/Position.hpp"

class Target {
private:
    Color color;
    Symbol symbol;
    Position position;

public:
    Target(Color color, Symbol symbol, Position position);

    Color getColor() const;

    Symbol getSymbol() const;

    Position getPosition() const;
};