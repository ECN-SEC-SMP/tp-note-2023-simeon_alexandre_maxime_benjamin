#include "Case.hpp"
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <iostream>

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
    // créer une attente pour assurer le changement de seed pour srand
    srand( time( 0) );
    int id = 0;
    for(int i = 0;i < 10000000;i++){}   
    
    id  = rand() % 4;

    switch(id){
        case 0 :
            this->angle = HG;
            this->murG = 1;
            this->murH = 1; 
            this->murD = 0;
            this->murB = 0;            
        break;
        case 1 : 
            this->angle = HD;
            this->murG = 0;
            this->murH = 1; 
            this->murD = 1;
            this->murB = 0;             
        break;
        case 2:
            this->angle = BD;
            this->murG = 0;
            this->murH = 0; 
            this->murD = 1;
            this->murB = 1;             
        break;
        case 3:
            this->angle = BG;
            this->murG = 1;
            this->murH = 0; 
            this->murD = 0;
            this->murB = 1;             
        break;
        default :
            this->angle = NONE;
            this->murG = 0;
            this->murH = 0; 
            this->murD = 0;
            this->murB = 0;             
    } 
     
}

void Case::setRobot(Robot* newRobot) { robot=newRobot; }
void Case::setTarget(Target* newTarget) { target = newTarget; }

void Case::affichage_case(Case* c[16][16], int x, int y)
{
    //cout << y;

    if((this->murG == 0 && this->murB == 1) || (this->murG == 0 &&  c[x][y+1]->getMurH()== 1))
    {
        cout << "|...";
    }
    else if((this->murG == 1 && this->murB == 0) || (x>0 && c[x-1][y]->getMurD() == 1 && this->murB == 0))
    {
        cout << ":___";
    }
    else if((this->murG == 1 && this->murB == 1))
    {
        cout << ":...";
    }
    else if (x == 15 && y == 15)
    {
        cout << "___|";
    }
    else
    {
        cout << "|___";
    }
                   
    
}
