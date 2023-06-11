/**
*@file Position.hpp
*@author Benjamin Siméon Maxime Alexandre
*@date 2023  
*/

#pragma once 
#include "string"
#include "stdlib.h"

class Position {
private:
    int x;
    int y;

public:
    Position(int _x, int _y);

    int getX() const;
    int getY() const;

    void setX(int newX);
    void setY(int newY);
};