/**
*@file Target.hpp
*@author Benjamin Siméon Maxime Alexandre
*@date 2023  
*/
#pragma once 
#include "string"
#include "stdlib.h"
#include "../Position/Position.hpp"
#include "../util.hpp"
#include "../Position/Position.hpp"

class Target {
private:
    Color color;
    Symbol symbol;
    Position position;

public:
    Target(Color _color, Symbol _symbol, Position _position);

    // Getters
    Color getColor() const;

    Symbol getSymbol() const;
    Position getPosition() const;

    std::string getCaracteresTarget();

};