/**
*@file Target.hpp
*@author Benjamin Siméon Maxime Alexandre
*@date 2023  
*/
#pragma once 
#include "string"
#include "stdlib.h"
#include "../Position/Position.hpp"
#include "../util.hpp"
#include "../Position/Position.hpp"

class Target {
private:
    Color color;/*!<couleur de la target de type Couleur*/
    Symbol symbol;/*!<symbol de la target de type Symbol*/
    Position position;/*!<position de la taerget, utilis ela classe Position*/

public:
     /*!
      permet d'instancier une target avec une couleur, un symbol et une psoition
    */
    Target(Color _color, Symbol _symbol, Position _position);

    // Getters
    /**
     * @brief permet de récupérer la couleur de la cible
     * @return [Color] retourne la couleur du robot 
    */    
    Color getColor() const;

    /**
     * @brief permet de récupérer le symbol du robot
     * @return [Symbol] retourne le symbol du robot 
    */   
    Symbol getSymbol() const;

    /**
     * @brief permet de récupérer la positon de la target
     * @return [Position] retourne la position de la target 
    */    
    Position getPosition() const;

    /**
     * @brief permet de modifier la position du robot
     * @param p [Position] 
    */ 
    void setPosition(Position p);

    /**
     * @brief permet de récupérer initiale de la target
     * @return [string] return une chaine de caractères : la première lettre du symbol + la premiere lettre de la couleur 
    */
    std::string getCaracteresTarget();

};

/*! \class Game  Game.hpp "Game/Game.hpp"
* \brief classe Game qui permet d'enregistrer une cible.
*
*/