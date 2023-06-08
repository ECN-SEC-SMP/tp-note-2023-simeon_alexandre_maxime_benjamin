#include <iostream>
#include "Game/Game.hpp"
#include "Position/Position.hpp"
#include "Robot/Robot.hpp"
#include "Target/Target.hpp"
#include "Case/Case.hpp"
#include "utilitaires/utilitaires.hpp"

using namespace std;

int main() { 

    Case* plateau[16][16] = {nullptr};

    // Robot* r_red;
    // Robot* r_blue;
    // Robot* r_yellow;
    // Robot* r_green;

    // Target* target;

    creerPlateau(plateau);

    //target
    //target = new Target(YELLOW,DIAMOND,Position(4,4));

    //mise en place robot

    // r_red = new Robot(RED,Position(9,6));
    // r_blue = new Robot(BLUE,Position(9,7));
    // r_yellow = new Robot(YELLOW,Position(9,8));
    // r_green = new Robot(GREEN,Position(9,9));    
    
    // plateau[r_red->getPosition().getX()][r_red->getPosition().getY()]->setRobot(r_red);
    // plateau[r_blue->getPosition().getX()][r_blue->getPosition().getY()]->setRobot(r_blue);
    // plateau[r_yellow->getPosition().getX()][r_yellow->getPosition().getY()]->setRobot(r_yellow);
    // plateau[r_green->getPosition().getX()][r_green->getPosition().getY()]->setRobot(r_green);

    //mi enplace angle
    for(int i = 0;i<4;i++)
    {
        for(int i = 0;i < 100000000;i++){}
        angleAleatoire(plateau,premier_quart);
        for(int i = 0;i < 100000000;i++){}
        angleAleatoire(plateau,deuxieme_quart);
        for(int i = 0;i < 100000000;i++){}
        angleAleatoire(plateau,troisieme_quart);
        for(int i = 0;i < 100000000;i++){}
        angleAleatoire(plateau,quatrieme_quart);
        for(int i = 0;i < 100000000;i++){}
    }

    




    //mise en place mur aleatoire
    // mur_aleatoire(plateau);
    // angleAleatoire(plateau,premier_quart);
     
    // plateau[4][4]->setAngle();
    // plateau[4][4]->setTarget(target);
    //afficher plateau
    afficher_plateau(plateau);
     
}