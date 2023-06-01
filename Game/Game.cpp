#include "Game.hpp"
#include "iostream"
#include <sstream>
#include "stdlib.h"
using namespace std;

Game::Game(const std::vector<Robot>& robots, const std::vector<Target>& targets) : robots(robots), targets(targets) {}
void Game::iniGame(){
    bool nbok = false;
    string signednbjoueurs;
    string nom;
    cout << "nombre de joueurs : "; 
    cin >> signednbjoueurs;
    while (nbok == false){
        istringstream iss(signednbjoueurs);
        double number;
        if(!(iss >> number) && !(iss.eof()) )  //Si ce n'est pas un chiffre
        {
            cout << "pas un nombre, recommencez : ";
            cin >> signednbjoueurs;             //On demande un nouveau nombre
        }
        else nbok = true; 
    }
    unsigned nbjoueurs = atoi(signednbjoueurs.c_str()); // conversion string en unsigned 
    vector<Player*> joueurs(nbjoueurs, nullptr);
    for (unsigned i = 0 ; i < nbjoueurs ; i+=1 ) 
    {        
        bool nomsok = false; // vérifié que les prénoms ne sont pas en double
        cout << "nom du joueur "<< (i+1)<< " : ";
        cin >> nom;
        while (nomsok == false){ // tant qu'il y a des problèmes ...
            cout << "in while"<<endl; 
            bool doublon = false; //variable qui vérifié la présence de doublons 
            for (unsigned u = 0; u < i && doublon == false ; u++ ){ //on test pour tous les noms jusqu'à trouver une erreur ou avoir fini
                cout << "in for"<<endl;
                if (nom ==  joueurs[u]->getName()) doublon = true; // si on trouve un doublon on le signal et arrête de test 
                cout << "après if doublon vaut :" << doublon <<endl;  
            }
            cout << "test doublon"<<endl;
            if (doublon == true){ // cas où il existe un doublon 
                cout << "nom déjà utiliser"<< endl; 
                cout << "nom du joueur "<< (i+1)<< " : ";
                cin >> nom; // on récupère le nouveau nom 
                cout << "fin test"<<endl;
            } // une fois fini la boucle recommance au début pour tester chaques noms à nouveau 
            
            else { // cas pas ou plus de doublons 
                cout << "concluant"<<endl;
                nomsok = true; // on signal la non présence de doublons et on stoppe la boucle 
                }    
        } 
        cout << "le nom retenu pour joueur " << i+1 << "est :" << nom<< endl;  
        Player* z = new Player(nom); // on créer un nouveau joueur 
        joueurs[i] = z; // on ajouter l'adresse du nouveau joueur au vecteur 
    }
    cout << "fin initialisation, la partie peut commencer"<< endl; 
}

void Game::playTurn() {

}

void Game::moveRobot(Robot& robot, Direction direction){
    
}

bool Game::isTargetReached(const Target& target) const{
    return true;
}