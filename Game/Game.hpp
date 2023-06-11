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

public:
    Game(void);

    void iniGame();

    bool playTurn(const Target* target);

    void moveRobot(Robot* robot, Direction direction);

    bool isTargetReached(const Target* target) const;

    Position mur_exterieur_horizontale(int quart_plateau);

    Position mur_exterieur_vertical(int quart_plateau);

    void afficher_plateau(Case* c[16][16]);

    Case *creerPlateau(Case* c[16][16]);

    void plateauInit(Case* plateau[16][16]);
    
    Target* murInterieur(Case* plateau[16][16], int quart_plateau,Symbol symbolTarget,vector <Color> color);

    void genererRobot(Case* plateau[16][16],Color _color);

    Color genererCouleurAleatoire(int quart, Case* plateau[16][16], vector <Color>);

    void generer17emeTarget(Case* plateau[16][16]);
    
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
