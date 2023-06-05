#pragma once 
#include <iostream>
#include <vector>
#include "string"
#include "stdlib.h"

#include "../util.hpp"
#include "../Robot/Robot.hpp"
#include "../Target/Target.hpp"
#include "../Player/Player.hpp"

class Game {
private:
    std::vector<Robot> robots;
    std::vector<Target> targets;

public:
    Game(const std::vector<Robot>& robots, const std::vector<Target>& targets);

    void iniGame();

    void playTurn();

    void moveRobot(Robot& robot, Direction direction);

    bool isTargetReached(const Target& target) const;
};