#include "Game.hpp"

Game::Game(void) {}

Robot* Game::createRobot(Color color){
    bool posok = false;
    Position p(0, 0);
    srand(time(NULL));
    while (posok == false){
        // cout<< "entree test position"<<endl;
        bool doublons = false;
        int x = rand()%16;
        int y = rand()%16;
        while (x == 7 || x == 8){
            x = rand()%16;
        }
        while (y == 7 || y == 8){
            y = rand()%16;
        }
        // cout<< "sortie test centre"<<endl;
        p.setX(x);
        p.setY(y);
        // cout<< "entree test superposition"<<endl;
        for (unsigned i = 0; i < robots.size() ;i++){
            if (p.getX() == robots[i]->getPosition().getX()) {
                if (p.getY() == robots[i]->getPosition().getY()) doublons = true; 
            } 
        }
        // cout<< "sortie superposition"<<endl;
        if (doublons == false) posok = true; 
    }
    // cout<< "creation pointeur de robot"<<endl;
    Robot* z = new Robot (color, p);
    return z; 
}

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
    robots.push_back(createRobot(RED)); 
    // cout << "couleur du robot 0 : " << robots[0]->getColor() <<", position en x : " <<  robots[0]->getPosition().getX() << " et position en y : " << robots[0]->getPosition().getY() << endl; 
    robots.push_back(createRobot(BLUE));
    // cout << "couleur du robot 0 : " << robots[1]->getColor() <<", position en x : " <<  robots[1]->getPosition().getX() << " et position en y : " << robots[1]->getPosition().getY() << endl; 
    robots.push_back(createRobot(YELLOW));
    // cout << "couleur du robot 0 : " << robots[2]->getColor() <<", position en x : " <<  robots[2]->getPosition().getX() << " et position en y : " << robots[2]->getPosition().getY() << endl; 
    robots.push_back(createRobot(GREEN));
    // cout << "couleur du robot 0 : " << robots[3]->getColor() <<", position en x : " <<  robots[3]->getPosition().getX() << " et position en y : " << robots[3]->getPosition().getY() << endl; 
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
    
}

bool Game::isTargetReached(const Target& target) const{
    return true;
}