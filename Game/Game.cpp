#include "Game.hpp"


Game::Game(const std::vector<Robot>& robots, const std::vector<Target>& targets) : robots(robots), targets(targets) {}

void Game::playTurn() {

};

void Game::moveRobot(Robot& robot, Direction direction){
    
};

bool Game::isTargetReached(const Target& target) const{
    return true;
};