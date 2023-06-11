/**
*@file Player.hpp
*@author Benjamin Siméon Maxime Alexandre
*@date 2023  
*/
#pragma once
#include "string"
#include "stdlib.h"
using namespace std;

class Player {
private:
    string name;
    unsigned char score;

public:
    Player(string _name);
    void addPoint(void);
    string getName(void) const;
    unsigned char getScore(void) const;
};