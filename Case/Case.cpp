#include "Case.hpp"
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include "../util.hpp"


using namespace std;

Case::Case() : murH(false), murD(false), murB(false), murG(false), angle(NONE), robot(nullptr), target(nullptr) {}

// Getteurs
bool Case::getMurH() const{ return murH; }
bool Case::getMurD() const{ return murD; }
bool Case::getMurB() const{ return murB; }
bool Case::getMurG() const{ return murG; }

Angle Case::getAngle() const{ return angle; }

Robot* Case::getRobot() const{ return robot; }
Target* Case::getTarget() const{ return target; }

//Setteurs
void Case::setMurH(bool mur){ murH = mur; }
void Case::setMurD(bool mur){ murD = mur; }
void Case::setMurB(bool mur){ murB = mur; }
void Case::setMurG(bool mur){ murG = mur; }

void Case::setAngle()
{
 
    int id = 0;
    for(int i = 0;i < 10000000;i++){}//boucle d'attente pour generer un nombre aleatoire   
    
    id  = rand() % 4;//chiffre aleatoire entre 0 et 3

    switch(id){
        case 0 : // angle haut droit
            this->angle = HD;
            this->murG = 0;
            this->murH = 1; 
            this->murD = 1;
            this->murB = 0;            
        break;
        case 1 : //angle bas droit 
            this->angle = BD;
            this->murG = 0;
            this->murH = 0; 
            this->murD = 1;
            this->murB = 1;             
        break;
        case 2: //angle bas gauche
            this->angle = BG;
            this->murG = 1;
            this->murH = 0; 
            this->murD = 0;
            this->murB = 1;             
        break;
        case 3: //angle haut gauche
            this->angle = HG;
            this->murG = 1;
            this->murH = 1; 
            this->murD = 0;
            this->murB = 0;             
        break;
        default : //pa defaut aucun angle
            this->angle = NONE;
            this->murG = 0;
            this->murH = 0; 
            this->murD = 0;
            this->murB = 0;             
    } 
     
}

void Case::setRobot(Robot* newRobot) { robot=newRobot; }
void Case::setTarget(Target* newTarget) { target = newTarget; }