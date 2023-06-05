#include "Player.hpp"

Player::Player(std::string _name) : name(_name), score(0) {}

void Player::addPoint(){
    score++;
}

string Player::getName() const {
    return name;
}

unsigned char Player::getScore() const {
    return score;
}