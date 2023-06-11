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

    bool murH/*!<mur haut*/, murD/**mur droit*/, murB/**mur bas*/, murG/**gauche*/;                                
    Angle angle;/*!<utilise la classe Angle*/
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
    *@details détermine un chiffre aléatoire entre de 0 à 3  
    *@details 0 -> angle haut droit
    *@details 1 -> angle bas droit
    *@details 2 -> angle bas gauche
    *@details 3 -> angle haut gauche
    */ 
    void setAngle();

    // Getteurs
     /**
     *@brief retourne la valueur de murH 
    *@return[bool] retourne la valueur de murH
    */
    bool getMurH(void) const;

     /**
      *@brief retourne la valueur de murD 
    *@return[bool] retourne la valueur de murD
    */   
    bool getMurD(void) const;

     /**
      *@brief retourne la valueur de murB 
    *@return[bool] retourne la valueur de murB
    */
    bool getMurB(void) const;

     /**
       *@brief retourne la valueur de murG
    *@return[bool] retourne la valueur de murG
    */ 
    bool getMurG(void) const;

     /**
      *@brief retourne l'angle 
    *@return[Angle] retourne l'angle
    */
    Angle getAngle(void) const;

    // Robot
    /**
    *@brief crée un nouveau robot
    *@param[out] Robot* nouveau robot
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
    *@param[out] Target* nouvelle target
    */    
    void setTarget(Target* newTarget);
    
  /**
      *@brief retourne la target 
    *@return[Target*] retourne la target
    */    
    Target* getTarget(void) const;

    //constructeur
    //constructeur de case 
    /*!
      permet d'instancier une case vide
    */
    Case();
};