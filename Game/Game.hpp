#pragma once 
#include <iostream>
#include <vector>
#include <array>
#include <sstream>
#include "string"
#include "stdlib.h"
#include <time.h>
#include <cstdlib>

#include "../util.hpp"
#include "../Robot/Robot.hpp"
#include "../Target/Target.hpp"
#include "../Player/Player.hpp"
#include "../Case/Case.hpp"
using namespace std;

class Game {
private:
    vector<Robot*> robots;
    vector<Target> targets;
    vector<Player*> joueurs;
    Robot* createRobot(Color color);
    array<array<Case,16>,16> plateau;  

public:
    Game(void);

    void iniGame();

    void playTurn();

    void moveRobot(Robot& robot, Direction direction);

    bool isTargetReached(const Target& target) const;
    
};

// Utilisation du plateau ArrayxArray
/*
// Accès aux éléments du plateau
    plateau[0][0] = 1;    // Premier élément
    plateau[0][1] = 2;    // Deuxième élément
    // ...

// Parcourir le plateau
for (int i = 0; i < 16; ++i) {
    for (int j = 0; j < 16; ++j) {
        // Accès à chaque élément
        int element = plateau[i][j];
        // Utiliser l'élément
        // ...
    }
}
*/