#include "Robot.hpp"
#include "../util.hpp"

using namespace std;

Robot::Robot(Color _color, Position _position) : color(_color), position(_position), prevPosition(_position) {}

Color Robot::getColor() const {
    return color;
}

Position Robot::getPrevPosition() const {
    return prevPosition;
}

Position Robot::getPosition() const {
    return position;
}

void Robot::setPosition(Position newPosition) {
    position = newPosition;
}

void Robot::setPrevPosition(Position newPosition) {
    prevPosition = newPosition;
}

std::string Robot::getCaractereColorRobot()const
{
    switch(this->color){
    case (RED):
        return "RR";
    break;
    case (YELLOW):
        return "RY";
    break;  
    case (BLUE):
        return "RB";
    break;  
    case (GREEN):
        return "RG";
    break;  
    case (MULTICOLOR):
        return "RM";
    break;    
    }

    return 0;
}