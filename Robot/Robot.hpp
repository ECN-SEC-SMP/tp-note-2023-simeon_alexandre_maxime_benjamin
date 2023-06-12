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
    Color color;/*!<couleur du robot de type Couleur*/
    Position position;/*!<position du robot, utilise la classe Positionr*/
    Position prevPosition;/*!<position du robot prévu du robot,utilise la classe Position */

public:

     /*!
      permet d'instancier un joueur avec une couleur et une psoition
    */
    Robot(Color _color, Position _position);


    /**
     * @brief permet de récupérer la couleur du robot
     * @return [Color] retourne la couleur du robot 
    */
    Color getColor() const;

    /**
     * @brief permet de récupérer la position du robot
     * @return [Color] retourne la popsition du robot 
    */
    Position getPosition() const;
    
        /**
     * @brief permet de récupérer la prev positon du robot
     * @return [Color] retourne la prev position du robot 
    */
    Position getPrevPosition()const;
    
    /**
     * @brief permet de modifier la position du robot
     * @param newPosition [Position] 
    */    
    void setPosition(Position newPosition);

    /**
     * @brief permet de modifier la position du robot
     * @param newPosition [Position] 
    */
    void setPrevPosition(Position newPosition);

    /**
     * @brief permet de récupérer initiale robot  
     * @return [string] return une chaine de caractères  : la lettre "R" pour "Robot" + première lettre couleur pour afficher dans les case
    */
    string getCaractereColorRobot()const;
};

/*! \class Game  Game.hpp "Game/Game.hpp"
* \brief classe Game qui permet d'enregistrer un robot.
*
*/