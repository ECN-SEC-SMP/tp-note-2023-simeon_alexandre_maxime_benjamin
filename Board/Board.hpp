#pragma once 
#include <iostream>
#include <vector>
#include "string.h"
#include "stdlib.h"

#include "../Position/Position.hpp"

class Board {
private:
    int size;
    std::vector<std::vector<bool>> walls;

public:
    Board(int size);

    int getSize() const;

    bool isWall(int x, int y) const;

    void setWall(int x, int y, bool hasWall);
};