#include "Robot.hpp"

using namespace std;

Robot::Robot(Color color, Position position) : color(color), position(position), prevPosition(position) {}

Color Robot::getColor() const {
    return color;
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
    }

    return 0;
}
