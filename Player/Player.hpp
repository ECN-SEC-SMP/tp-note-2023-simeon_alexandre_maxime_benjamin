/**
*@file Player.hpp
*@author Benjamin Siméon Maxime Alexandre
*@date 2023  
*/
#pragma once
#include "string"
#include "stdlib.h"
using namespace std;

class Player {
private:
    string name;/*!<nom du joueur*/
    unsigned char score;/*!<score du joueur*/

public:
     /*!
      permet d'instancier un joueur avec un nom
    */
    Player(string _name);

    /**
     * @brief permet d'ajouter un point au joueur 
    */
    void addPoint(void);

    /**
     * @brief permet de récupérer le nom du joueur
     * @return [string] retourn le nom du joueur
    */
    string getName(void) const;

    /**
     * @brief permet de récupérer le score du joueur
     * @return [unsigned char] retourne le score du joueur
    */
    unsigned char getScore(void) const;
};

/*! \class Player  Player.hpp "Player/Player.hpp"
* \brief classe Player qui permet de créer un joueur.
*
*/