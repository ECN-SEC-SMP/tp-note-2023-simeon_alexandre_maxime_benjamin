#pragma once 
#include "string"
#include "stdlib.h"
#include "../Position/Position.hpp"

using namespace std;


class Robot {
private:
    Color color;
    Position position;
    Position prevPosition;

public:
    Robot(Color color, Position position);

    Color getColor() const;

    Position getPosition() const;

    void setPosition(Position newPosition);

    void setPrevPosition(Position newPosition);

    string getCaractereColorRobot()const;
};
