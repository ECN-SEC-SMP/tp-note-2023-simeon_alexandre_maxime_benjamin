#pragma once 
#include <iostream>
#include <vector>
#include "string"
#include "stdlib.h"

#include "../util.hpp"
#include "../Robot/Robot.hpp"
#include "../Target/Target.hpp"
#include "../Player/Player.hpp"
using namespace std;

class Game {
private:
    vector<Robot> robots;
    vector<Target> targets;
    vector<Player*> joueurs;

public:
    Game(const vector<Robot>& robots, const vector<Target>& targets);

    void iniGame();

    void playTurn();

    void moveRobot(Robot& robot, Direction direction);

    bool isTargetReached(const Target& target) const;
    
};