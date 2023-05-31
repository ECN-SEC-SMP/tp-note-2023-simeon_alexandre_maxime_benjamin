#pragma once 
#include "string.h"
#include "stdlib.h"

#include "../Position/Position.hpp"


class Robot {
private:
    Color color;
    Position position;

public:
    Robot(Color color, Position position);

    Color getColor() const;

    Position getPosition() const;

    void setPosition(Position newPosition);
};
