#pragma once 
#include "string"
#include "stdlib.h"
#include "../Position/Position.hpp"
#include "../util.hpp"

class Target {
private:
    Color color;
    Symbol symbol;
    Position position;

public:
    Target(Color _color, Symbol _symbol, Position _position);

    Color getColor() const;

    Symbol getSymbol() const;

    Position getPosition() const;

    std::string getCaracteresTarget();
};