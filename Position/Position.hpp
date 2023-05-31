#pragma once 
#include "string.h"
#include "stdlib.h"

class Position {
private:
    int x;
    int y;

public:
    Position(int x, int y);

    int getX() const;
    int getY() const;

    void setX(int newX);
    void setY(int newY);
};

enum Color {
    RED,
    YELLOW,
    BLUE,
    GREEN
};

enum Symbol {
    CIRCLE,
    SQUARE,
    TRIANGLE,
    DIAMOND,
    MULTICOLOR
};

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};