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

void Case::affichage_case(Case* c[16][16], int x, int y)//gere l'affichage d'une seul case : murG et murB
{
    
    //carre centrale du plateau
    c[7][7]->murG = 1;
    c[7][7]->murH = 1;

    c[8][7]->murG = 1;
    c[8][7]->murB = 1;

    c[7][8]->murH = 1;
    c[7][8]->murD = 1;

    c[8][8]->murD = 1;
    c[8][8]->murB = 1; 
 

    //bord du plateaau 
    for(int i=0;i<16;i++)
    {
        c[i][0]->murG = 1; 
        c[15][i]->murB = 1;
        c[i][15]->murD = 1; 
        c[0][i]->murH = 1;          
    }

    //Si il y a un angle bas droit OU il y a un mur haut sur la case dessous   
    if((this->murG == 0 && this->murB == 1) || (y<14 && this->murG == 0 &&  c[y+1][x]->getMurH()== 1))
    {
        if(this->target == nullptr && this->robot != nullptr)
        {
            cout << ":" << this->robot->getCaractereColorRobot() << "";//affiche dans la case initiales robot si il y en a un
        }
        else if(this->target != nullptr)
        {
            cout << ":_" << this->target->getCaracteresTarget() << "_";//affiche dans la case initiales Target si il y en a une
            
        }
        else
        {
            cout << ":____";//sinon affiche trait plein
        }
        
    }
    //angle haut gauche OU case precedente gauche a un mur droit
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
    //angle bas droit
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
    //angle haut droit OU pas d'angle
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