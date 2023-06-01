#include "Game.hpp"


Game::Game(const Board& board, const std::vector<Robot>& robots, const std::vector<Target>& targets) : board(board), robots(robots), targets(targets) {}

void Game::playTurn() {

};

void Game::moveRobot(Robot& robot, Direction direction){
    
};

bool Game::isTargetReached(const Target& target) const{
    return true;
};