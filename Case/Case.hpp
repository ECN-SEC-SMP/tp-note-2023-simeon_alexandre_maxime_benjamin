/**
*@file Case.hpp
*@author Benjamin Siméon Maxime Alexandre
*@date 2023  
*/
#pragma once
#include "string"
#include "stdlib.h"

#include "../util.hpp"
#include "../Robot/Robot.hpp"
#include "../Target/Target.hpp"

class Case {
private:

    bool murH/*!<mur haut de la case*/, murD/**mur droit de la case*/, murB/**mur bas de la case*/, murG/**mur gauche de la case*/;                                
    Angle angle;/*!<angle d'une case de la classe Angle*/
    Robot* robot;/*!<utilise la classe Robot*/
    Target* target;/*!<utilise la classe Target*/

public:

    // Setteurs
    /**
    *@brief modifie l'attribue murH 
    *@param[out]  mur  [Bool]
    */
    void setMurH(bool mur);

    /**
    *@brief modifie l'attribue murD 
    *@param[out]  mur [Bool]
    */  
    void setMurD(bool mur);


    /**
    *@brief modifie l'attribue murB 
    *@param[out]  bool mur
    */  
    void setMurB(bool mur);


    /**
    *@brief modifie l'attribue murG 
    *@param[out]  bool mur
    */  
    void setMurG(bool mur);


    /**
    *@brief modifie l'attribue angle aléatoirement composé de 2 murs 
    *@details détermine un chiffre aléatoire entre de 0 à 3  pour déterminer l'angle correspondant
    *@details 0 -> angle haut droit
    *@details 1 -> angle bas droit
    *@details 2 -> angle bas gauche
    *@details 3 -> angle haut gauche
    */ 
    void setAngle();

    // Getteurs
     /**
     *@brief détermine si il y a un mur haut ou non 
    *@return[bool] retourne la valueur de murH : True = il y a un mur
    */
    bool getMurH(void) const;

     /**
      *@brief détermine si il y a un mur droit ou non 
    *@return[bool] retourne la valueur de murD : True = il y a un mur
    */   
    bool getMurD(void) const;

     /**
      *@brief détermine si il y a un mur bas ou non 
    *@return[bool] retourne la valueur de murB : True = il y a un mur
    */
    bool getMurB(void) const;

     /**
       *@brief détermine si il y a un mur gauche ou non
    *@return[bool] retourne la valueur de murG : True = il y a un mur
    */ 
    bool getMurG(void) const;

     /**
      *@brief retourne l'angle de class Angle 
    *@return[Angle] retourne l'angle
    */
    Angle getAngle(void) const;

    // Robot
    /**
    *@brief crée un nouveau robot
    *@param[out] newRobot [Robot*] nouveau robot
    */    
    void setRobot(Robot* newRobot);

     /**
      *@brief retourne le robot 
    *@return[Angle*] retourne le robot
    */ 
    Robot* getRobot(void) const;

    // Target
    /**
    *@brief crée une nouvelle target 
    *@param[out] newTarget [Target*] nouvelle target
    */    
    void setTarget(Target* newTarget);
    
  /**
      *@brief retourne la target 
    *@return [Target*] retourne la target
    */    
    Target* getTarget(void) const;

    //constructeur
    //constructeur de case 
    /*!
      permet d'instancier une case vide
    */
    Case();
};

/*! \class Game  Game.hpp "Game/Game.hpp"
* \brief classe Game qui permet de crée une case.
*
*/