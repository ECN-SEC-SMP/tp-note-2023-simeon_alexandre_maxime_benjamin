#include "Robot.hpp"


Robot::Robot(Color _color, Position _position) : color(_color), position(_position), prevPosition(_position) {}

Color Robot::getColor() const {
    return color;
}

Position Robot::getPosition() const {
    return position;
}

Position Robot::getPrevPosition() const {
    return prevPosition;
}

void Robot::setPosition(Position newPosition) {
    position = newPosition;
}

void Robot::setPrevPosition(Position newPosition) {
    prevPosition = newPosition;
}
