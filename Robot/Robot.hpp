#pragma once 
#include "string"
#include "stdlib.h"

#include "../util.hpp"
#include "../Position/Position.hpp"


class Robot {
private:
    Color color;
    Position position;
    Position prevPosition;

public:
    Robot(Color _color, Position _position);

    Color getColor() const;

    Position getPosition() const;

    Position getPrevPosition() const;

    void setPosition(Position newPosition);

    void setPrevPosition(Position newPosition);
};
