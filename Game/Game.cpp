#include "Game.hpp"

Game::Game(void) {}

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
    // vector<Player*> joueurs(nbjoueurs, nullptr);
    for (unsigned i = 0 ; i < nbjoueurs ; i++ ) 
    {        
        bool nomsok = false; // vérifié que les prénoms ne sont pas en double
        cout << "nom du joueur "<< (i+1)<< " : ";
        cin >> nom;
        while (nomsok == false){ // tant qu'il y a des problèmes ...
            bool doublon = false; //variable qui vérifié la présence de doublons 
            for (unsigned u = 0; u < i && doublon == false ; u++ ){ //on test pour tous les noms jusqu'à trouver une erreur ou avoir fini
                if (nom ==  joueurs[u]->getName()) doublon = true; // si on trouve un doublon on le signal et arrête de test
            }
            if (doublon == true){ // cas où il existe un doublon 
                cout << "nom deja utiliser"<< endl; 
                cout << "nom du joueur "<< (i+1)<< " : ";
                cin >> nom; // on récupère le nouveau nom 
            } // une fois fini la boucle recommance au début pour tester chaques noms à nouveau 
            
            else { // cas pas ou plus de doublons 
                nomsok = true; // on signal la non présence de doublons et on stoppe la boucle 
                }    
        } 
        cout << "le nom retenu pour joueur " << i+1 << " est : " << nom<< endl;  
        Player* z = new Player(nom); // on créer un nouveau joueur 
        // cout << "après z " <<  endl;
        joueurs.push_back(z) ; // on ajouter l'adresse du nouveau joueur au vecteur 
        // cout << "après joueurs " << endl;
    }
    cout << "fin initialisation, la partie peut commencer"<< endl; 
}

void Game::playTurn() {
    // int nbjoueurs = 3; // pour test
    // int nbval = 0; 
    // while (nbval != nbjoueurs){
    //     cout << "nom joueur :" ;
    //     cin << 
    // }
}

void Game::moveRobot(Robot& robot, Direction direction){
    bool blocked=false;
    while(!blocked){
        switch (direction)
        {
        case UP:
            if(plateau[robot.getPosition().getX()][robot.getPosition().getY()].getMurH()){ // teste le mur
                blocked=true;
            }
            else{
                robot.setPosition(Position(robot.getPosition().getX(), robot.getPosition().getY()-1)); // déplace le robot en haut
            }
            break;

        case DOWN:
            if(plateau[robot.getPosition().getX()][robot.getPosition().getY()].getMurB()){ // teste le mur
                blocked=true;
            }
            else{
                robot.setPosition(Position(robot.getPosition().getX(), robot.getPosition().getY()+1)); // déplace le robot en bas
            }
            break;

        case LEFT:
            if(plateau[robot.getPosition().getX()][robot.getPosition().getY()].getMurG()){ // teste le mur
                blocked=true;
            }
            else{
                robot.setPosition(Position(robot.getPosition().getX()-1, robot.getPosition().getY())); // déplace le robot à gauche
            }
            break;

        default:
            if(plateau[robot.getPosition().getX()][robot.getPosition().getY()].getMurD()){ // teste le mur
                blocked=true;
            }
            else{
                robot.setPosition(Position(robot.getPosition().getX()+1, robot.getPosition().getY())); // déplace le robot à droite
            }
            break;
        }
    }
}

// Did the robot reach the target?
bool Game::isTargetReached(const Target& target) const{
    int8_t x, y;
    x = target.getPosition().getX();
    y = target.getPosition().getY();

    if(plateau[x][y].getRobot()->getColor() == target.getColor()){
        return true;
    }
    return false;
}