#pragma once 
#include "string"
#include "stdlib.h"

#include "../util.hpp"
#include "../Position/Position.hpp"

class Target {
private:
    Color color;
    Symbol symbol;
    Position position;

public:
    Target(Color _color, Symbol _symbol, Position _position);

    Color getColor() const;

    Symbol getSymbol() const;
};