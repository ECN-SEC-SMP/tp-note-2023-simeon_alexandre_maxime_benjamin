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
    // créer une attente pour assurer le changement de seed pour srand
    //srand( time( 0) );
    int id = 0;
    for(int i = 0;i < 10000000;i++){}   
    
    id  = rand() % 4;

    switch(id){
        case 0 :
            this->angle = HD;
            this->murG = 0;
            this->murH = 1; 
            this->murD = 1;
            this->murB = 0;            
        break;
        case 1 : 
            this->angle = BD;
            this->murG = 0;
            this->murH = 0; 
            this->murD = 1;
            this->murB = 1;             
        break;
        case 2:
            this->angle = BG;
            this->murG = 1;
            this->murH = 0; 
            this->murD = 0;
            this->murB = 1;             
        break;
        case 3:
            this->angle = HG;
            this->murG = 1;
            this->murH = 1; 
            this->murD = 0;
            this->murB = 0;             
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
    
    
    c[7][7]->murG = 1;
    c[7][7]->murH = 1;

    c[8][7]->murG = 1;
    c[8][7]->murB = 1;

    c[7][8]->murH = 1;
    c[7][8]->murD = 1;

    c[8][8]->murD = 1;
    c[8][8]->murB = 1; 
 

    for(int i=0;i<16;i++)
    {
          c[i][0]->murG = 1; 
          c[15][i]->murB = 1;
    }  
       
    if((this->murG == 0 && this->murB == 1) || (y<14 && this->murG == 0 &&  c[y+1][x]->getMurH()== 1))
    {
        if(this->target == nullptr && this->robot != nullptr)
        {
            cout << ":" << this->robot->getCaractereColorRobot() << "";
        }
        else if(this->target != nullptr)
        {
            cout << ":_" << this->target->getCaracteresTarget() << "_";
            
        }
        else
        {
            cout << ":____";
        }
        
    }
    else if((this->murG == 1 && this->murB == 0) || (x>0 && c[y][x-1]->getMurD() == 1 && this->murB == 0))
    {
        if(this->target == nullptr && this->robot != nullptr)
        {
            cout << "|" << this->robot->getCaractereColorRobot() << "";
        }
       else if(this->target != nullptr)
        {
            cout << "|." << this->target->getCaracteresTarget() << ".";
            
        }        
        else
        {        
            cout << "|....";
        }
    }
    else if((this->murG == 1 && this->murB == 1))
    {
        if(this->target == nullptr && this->robot != nullptr) 
        {
            cout << "|" << this->robot->getCaractereColorRobot() << "";
        }
       else if(this->target != nullptr)
        {
            cout << "|_" << this->target->getCaracteresTarget() << "_";
            
        }        
        else
        {        
            cout << "|____";
        }    
    }
    else
    {
        if(this->robot != nullptr)
        {
            cout << ":" << this->robot->getCaractereColorRobot() << "";
        }
       else if(this->target != nullptr)
        {
            cout << ":." << this->target->getCaracteresTarget() << ".";
        }
        else if(this->robot == nullptr || this->robot->getPosition().getX() != y || this->robot->getPosition().getY() != x)
        {        
            cout << ":....";
        }    
    }
                   
    
}