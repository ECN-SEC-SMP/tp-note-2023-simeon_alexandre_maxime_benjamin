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
    vector<Robot*> robots;/*!<vecteur qui contient les quatre robots qui ont été crées*/
    vector<Target*> targets;/*!<vecteur qui contient les cibles du plateau*/
    vector<Player*> joueurs;/*!<vecteur qui contient les joueur dansla partie*/

    /**
     * @brief creer les robot du plateau
     * @details la fonction détermine aléatoirement la position d'un robot pour ensuite le créer dans la case correspondnate
     * @param[in] color [Color] couleur du robot
     * @return Robot* retourne le robot crée
    */
    Robot* createRobot(Color color);

    /**
     * @brief détermine le mouvement à réaliser
     * @details la fonction détermine le mouvement à réaliser en fonction de la saisie au clavier du joueur
     * @param[in] direction [string] direction du joueur (haut,bas,gauche,droite)
     * @return[Direction] retourn la direction du joueur (UP,DOWN,LEFT,RIGHT)
    */
    Direction findPosition (string direction); 
    array<array<Case,16>,16> plateau;

    /**
     * @brief détermine le robot choisi par l'utilisateur
     * @details la fonction détermine le robot choisi par le joueur lors de la saisie au clavier de la couleur.
     * En fonction de la couleur, la fonction va trouver le robot dans le vecteur Robot 
     * @param[in] color [string] couleur du robot (GREEN,RED,YELLOW,BLUE)
     * @return[Direction] retourn la direction du joueur (UP,DOWN,LEFT,RIGHT)
    */
    Robot* findRobot(string color); 

        /**
     * @brief génere les targets
     * @details la fonction crée les targets et les place dans le vecteur Target.Elle crée toutes les combinaisons possibles entre les formes et les couleurs.
     * Une fois les targets crées, elles sont mélangées pour les placer aléatoirement sur les angles.
     * Pour finir les targets sont associées à la case correspondante
    */ 
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
    void affichage_case(Target* target, int x, int y);

public:
    /*!
      permet d'instancier le jeu
    */
    Game(void);
    /**
     * @brief permet d'initialiser le jeu
     * @details la fonction initialise le plateau de jeu. La fonction génère les targets.
     * Elle récupère le nombre de joeur et leur nom saisie au clavier.
     * Pour finir elle cree les robots
    */
    void iniGame();
    /**
     * @brief permet de jour une fois l'initialisation réalisé
     * @details En premier la focntion affiche le plateau. Ensuite elle récupère la valeur 
     * saisie au clavier de l'action à réaliser, le nombre de déplacements pour un joueur
     * @param target [Target*] cible 
     * @return [bool] retourne vrai si le joeur rentre un deplacement et une action valide.
    */
    bool playTurn(Target* target);

    /**
     * @brief permet de déplacer un robort sur le plateau
     * @details la focntion permet de dépalcer un robot en focntion du mouvmeent saisie au clavier par le joueur.
     * La focntion vérifie également si le robot rencontre un autre robot ou test si il y a un mur
     * @param direction [Direction] direction saisie au clavier par le joueur
     * @param robt [Robot*] robot jouer par le joueur 
    */
    void moveRobot(Robot* robot, Direction direction);

    /**
     * @brief vérifie si le robot à atteint la cible
     * @param target [const Target* target]
    */
    bool isTargetReached(const Target* target) const;

    /**
     *@brief génère une postion aléatoire pour créer un mur exterieur horizontale
     *@param quart_plateau [int] le quart du plateau où placer le mur exterieur : 
    *  premier_quart (haut gauche), deuxieme_quart(haut droit), troisieme_quart(bas droit), quatrieme_quart(bas gauche)
    * @return [Position] retour la position du mur 
    */
    Position mur_exterieur_horizontale(int quart_plateau);

    /**
     *@brief génère une postion aléatoire pour créer un mur exterieur vertical
     *@param quart_plateau [int] le quart du plateau où placer le mur exterieur : 
    *  premier_quart (haut gauche), deuxieme_quart(haut droit), troisieme_quart(bas droit), quatrieme_quart(bas gauche)
    * @return [Position] retour la position du mur 
    */
    Position mur_exterieur_vertical(int quart_plateau);

    /**
     * @brief affiche le plateau entier
     * @details cette fonction fait une boucle de la fonction afficher case afficher_case() afin de génerer l'affichage complet dur le terminal
     * @param target [Target*] cilbe sur le carre centrale  
    */
    void afficher_plateau(Target* target);
    /**
     * @brief cette fonction initialise le plateaude jeu
     * @details pour les 4 quarts du plateau, elle crée les mur exterieur (2 par quarts),
     *elle génère les angles, et elle génères la 17ème target 
    */
    void plateauInit(void);

  /**
   * @brief permet de géneré un angle pour l'un des quarts du plateau
   * @details la fonction génèrer une position aleatoire pour un angle en fonction du quart du plateau 
   * Si l'angle est trop proche d'un autre ou il y a un deja un angle dan sla case on rappelle la fonction.
   * Enfin on crée l'angle dans la case correspondante à la position
   * @param quart_plateau [int]
   * premier_quart (haut gauche), deuxieme_quart(haut droit), troisieme_quart(bas droit), quatrieme_quart(bas gauche)
   */  
    void murInterieur(int quart_plateau);

    /**
     * @brief génération de la 17eme target aleatoirement 
     * @details cette foncntion permet de générer la position aleatoiement de la target et de créer un angle au même endroit
    */
    void generer17emeTarget(void);

    /**
     * @brief permet de retourn une cible du vecteur Target
     * @return [vector<Target*>] retiourne une cible
    */
    vector<Target*> getTargetVector(void);

    /**
     * @brief permet de retourn un joueur du vecteur Player
     * @return [vector<Player*>] retiourne une cible
    */
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


/*! \class Game  Game.hpp "Game/Game.hpp"
* \brief classe Game qui permet le déroulement de partie de jeu.
*
*/