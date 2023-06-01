#pragma once 
#include "string"
#include "stdlib.h"

#include "../Position/Position.hpp"

class Target {
private:
    Color color;
    Symbol symbol;

public:
    Target(Color color, Symbol symbol);

    Color getColor() const;

    Symbol getSymbol() const;
};