#pragma once 
#include <iostream>
#include <vector>
#include "string.h"
#include "stdlib.h"

#include "../Position/Position.hpp"
#include "../Robot/Robot.hpp"
#include "../Target/Target.hpp"

class Game {
private:
    std::vector<Robot> robots;
    std::vector<Target> targets;

public:
    Game(const std::vector<Robot>& robots, const std::vector<Target>& targets);

    void playTurn();

    void moveRobot(Robot& robot, Direction direction);

    bool isTargetReached(const Target& target) const;
};