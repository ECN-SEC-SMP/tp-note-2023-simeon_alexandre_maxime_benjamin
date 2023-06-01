#pragma once
#include "string"
#include "stdlib.h"

class Player {
private:
    std::string name;
    unsigned char score;

public:
    Player(std::string name);
    void addPoint(void);
    std::string getName(void) const;
    unsigned char getScore(void) const;
};