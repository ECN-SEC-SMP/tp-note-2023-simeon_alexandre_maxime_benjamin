#include "Player.hpp"

Player::Player(std::string name) : name(name), score(0) {}

void Player::addPoint(){
    score++;
}

std::string Player::getName() const {
    return name;
}

unsigned char Player::getScore() const {
    return score;
}