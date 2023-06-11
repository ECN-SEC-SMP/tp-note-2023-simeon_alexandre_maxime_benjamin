/**
*@file Game.hpp
*@author Benjamin Siméon Maxime Alexandre
*@date 2023  
*/
#pragma once 
#include <iostream>
#include <vector>
#include <array>
#include <sstream>
#include "string"
#include "stdlib.h"
#include <time.h>
#include <cstdlib>

#include "../util.hpp"
#include "../Robot/Robot.hpp"
#include "../Target/Target.hpp"
#include "../Player/Player.hpp"
#include "../Case/Case.hpp"
using namespace std;

class Game {
private:
    vector<Robot*> robots;
    vector<Target*> targets;
    vector<Player*> joueurs;
    Robot* createRobot(Color color);
    Direction findPosition (string direction); 
    array<array<Case,16>,16> plateau;
    Robot* findRobot(string color);  
    void genererTargets(void);
    /**
    *@brief affiche une case, côté gauche et bas
    *@details Cette fonction crée le carré centrale et les bord du plateau.
    * Elle affiche le côté gauche et bas de la case en fonction des mur intérieur.
    * Elle affiche les initales du robot si il ya un robot sur la case
    * Elle affiche les initiales e la cible si l y en une sur la case
    *@param[in] int x valeur dans la boucle qui va parcourir les x dans l'affchage du plateau
    *@param[in] int x valeur dans la boucle qui va parcourir les y dans l'affchage du plateau
    */
    void affichage_case(int x, int y);

public:
    Game(void);

    void iniGame();

    bool playTurn(const Target* target);

    void moveRobot(Robot* robot, Direction direction);

    bool isTargetReached(const Target* target) const;

    Position mur_exterieur_horizontale(int quart_plateau);

    Position mur_exterieur_vertical(int quart_plateau);

    void afficher_plateau(void);

    void plateauInit(void);
    
    void murInterieur(int quart_plateau);

    void genererRobot(Color _color);

    void generer17emeTarget(void);
    
    vector<Target*> getTargetVector(void);

    vector<Player*> getPlayerVector(void);
    
};

// Utilisation du plateau ArrayxArray
/*
// Accès aux éléments du plateau
    plateau[0][0] = 1;    // Premier élément
    plateau[0][1] = 2;    // Deuxième élément
    // ...

// Parcourir le plateau
for (int i = 0; i < 16; ++i) {
    for (int j = 0; j < 16; ++j) {
        // Accès à chaque élément
        int element = plateau[i][j];
        // Utiliser l'élément
        // ...
    }
}
*/