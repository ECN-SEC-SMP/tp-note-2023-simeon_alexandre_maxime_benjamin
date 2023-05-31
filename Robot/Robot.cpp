#include "Robot.hpp"


Robot::Robot(Color color, Position position) : color(color), position(position) {}

Color Robot::getColor() const {
    return color;
}

Position Robot::getPosition() const {
    return position;
}

void Robot::setPosition(Position newPosition) {
    position = newPosition;
}
