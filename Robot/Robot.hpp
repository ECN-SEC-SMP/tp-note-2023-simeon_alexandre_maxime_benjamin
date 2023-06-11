/**
*@file Robot.hpp
*@author Benjamin Siméon Maxime Alexandre
*@date 2023  
*/

#pragma once 
#include "string"
#include "stdlib.h"
#include "../Position/Position.hpp"
#include "../util.hpp"

using namespace std;

class Robot {
private:
    Color color;
    Position position;
    Position prevPosition;

public:
    Robot(Color _color, Position _position);

    Color getColor() const;

    Position getPosition() const;
    
    Position getPrevPosition()const;
    
    void setPosition(Position newPosition);

    void setPrevPosition(Position newPosition);

    string getCaractereColorRobot()const;
};