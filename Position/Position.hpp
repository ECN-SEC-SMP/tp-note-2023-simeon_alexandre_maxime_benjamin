/**
*@file Position.hpp
*@author Benjamin Siméon Maxime Alexandre
*@date 2023  
*/

#pragma once 
#include "string"
#include "stdlib.h"

class Position {
private:
    int x;/*!<positin en abcisse*/
    int y;/*!<position en ordonnée*/

public:
     /*!
      permet d'instancier une position en abcisse et en ordonnée
    */
    Position(int _x, int _y);

    /**
     * @brief permet de récupérerla valeur  de x
     * @return [int] retourne la valeur de x
    */
    int getX() const;

    /**
     * @brief permet de récupérerla valeur  de y
     * @return [int]retourne la valeur de y
    */    
    int getY() const;

    /**
     * @brief permet de modifier la valeur  de x
     * @param newX nouvelle valeur de x
    */
    void setX(int newX);

    /**
     * @brief permet de modifier la valeur  de y
     * @param newY nouvelle valeur de y
    */    
    void setY(int newY);
};

/*! \class Position  Positon.hpp "Position/Position.hpp"
* \brief classe Position qui permet d'enregistrer une position en x et en y.
*
*/