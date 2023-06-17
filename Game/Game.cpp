#include "Game.hpp"
#include <algorithm>


Game::Game(void) {
    //instanciation des 16 cases du plateau   
    for(int y=0;y<16;y++)
    {
        for(int x=0; x<16;x++)
        {            
            plateau[x][y] = Case();
        }
    }
}

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
    plateau[p.getX()][p.getY()].setRobot(z);
    return z; 
}

Robot* Game::findRobot(string color){
    if (color == "RED" ||color =="red" ||color == "ROUGE"||color == "rouge") return robots[0];
    else if (color == "BLUE" ||color == "blue" ||color == "BLEU" ||color == "bleu") return robots[1];
    else if (color == "YELLOW" ||color == "yellow" ||color == "JAUNE" ||color == "jaune") return robots[2];
    else if (color == "GREEN" ||color == "green" ||color == "VERT" ||color == "vert") return robots[3];
}

Direction Game::findPosition (string direction){
    if (direction == "UP" ||direction == "up"  ||direction == "HAUT" ||direction == "haut") return UP; 
    else if (direction == "DOWN" ||direction == "down" ||direction == "BAS" ||direction == "bas") return DOWN;
    else if (direction == "LEFT" ||direction == "left" ||direction == "GAUCHE" ||direction == "gauche") return LEFT;
    else if (direction == "RIGHT" ||direction == "right" ||direction == "DROITE" ||direction == "droite") return RIGHT;
}

void Game::iniGame(){
    plateauInit();
    genererTargets();
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
    // cout << "couleur du robot 1 : " << robots[1]->getColor() <<", position en x : " <<  robots[1]->getPosition().getX() << " et position en y : " << robots[1]->getPosition().getY() << endl; 
    robots.push_back(createRobot(YELLOW));
    // cout << "couleur du robot 2 : " << robots[2]->getColor() <<", position en x : " <<  robots[2]->getPosition().getX() << " et position en y : " << robots[2]->getPosition().getY() << endl; 
    robots.push_back(createRobot(GREEN));
    // cout << "couleur du robot 3 : " << robots[3]->getColor() <<", position en x : " <<  robots[3]->getPosition().getX() << " et position en y : " << robots[3]->getPosition().getY() << endl; 
    cout << "fin initialisation, la partie peut commencer"<< endl;
}

bool Game::playTurn(Target* target) {
    unsigned nbval = 0; 
    string nom; 
    string nbc; 
    bool J =false; 
    bool nbok = false;
    vector<Player*> ordrePlayer;
    vector<int> nbmvt;
    Player* temp; 
    string color;  
    string mvt; 
    Direction direction; 
    afficher_plateau(target);
    while (nbval != joueurs.size()){
        cout << "entree while"<<endl; 
        cout << "nom joueur :" ;
        cin >> nom;
        while (J == false){
            for (unsigned i = 0; i <joueurs.size(); i++){ //on test que le joueur existe et récupère son numéro 
                cout << "entree for"<< joueurs[i] << endl; 
                if (nom ==  joueurs[i]->getName()) {                     
                    temp= joueurs[i];
                    J = true; // on trouve le joueur
                }
            }
            if (J== false){
                cout << "fin test joueur"<< endl; 
                cout << "joueur inexistant, recommencez : ";
                cin >> nom; //On demande un nouveau nombre
            }                       
        }
        
        cout << "nombre d'actions :" ;
        cin >> nbc;
        while (nbok == false){
            istringstream iss(nbc);
            double number;
            if(!(iss >> number) && !(iss.eof()) )  //Si ce n'est pas un chiffre
            {
                cout << "pas un nombre, recommencez : ";
                cin >> nbc;             //On demande un nouveau nombre
            }
            else if (nbc =="0" || nbc == "1" || nbc == "2"){ // si nombre vérifier si >2
                cout << "inferieur ou egale a 2, recommencez : ";
                cin >> nbc; 
            }  
            else nbok = true; 
        }
        int nb = atoi(nbc.c_str()); // conversion en entier
        if (nbmvt.size() == 0) {
            nbmvt.push_back(nb);
            ordrePlayer.push_back(temp);
        }
        else{
            bool inserted = false; 
            for (unsigned i =0;i<nbmvt.size(); i++){
                cout << "entree for nbmvt"<< endl; 
                if (nb >=nbmvt[i]){
                    cout << "nbmvt : "<< nbmvt[i]<< endl; 
                    nbmvt.insert(nbmvt.begin()+i, nb);
                    ordrePlayer.insert(ordrePlayer.begin()+i, temp);
                    inserted = true;
                    break;
                    cout << "fin insert"<<endl;
                }
                cout << "fin test" << endl;
            } 
            if (!inserted){
                nbmvt.push_back(nb); 
                ordrePlayer.push_back(temp); 
            }
        }
        nbval++; 
    }
    // while (! target reached)
    cout << "realisation des tours, nbmvt = "<<  endl; 
    for (unsigned i=joueurs.size()-1; i>0 ;i--){ // laisser les joueurs réaliser leurs essais 
        cout<< "entree for : " << joueurs[i]->getName()<< " nbmvt : " << nbmvt[i] <<  endl;
        for (unsigned u =0; u<nbmvt[i]; u++){ //le joueur va réaliser les n mvt qu'il a indiqué 
            cout << "couleur robot : "; 
            cin >> color; 
            while (color != "RED" &&color != "red" &&color != "ROUGE" && color != "rouge" && color !="BLUE" &&color != "blue" &&color != "BLEU" &&color != "bleu" &&color != "YELLOW" &&color != "yellow" &&color != "JAUNE" &&color != "jaune" &&color != "GREEN" &&color != "green" &&color != "VERT" &&color != "vert"){
                cout << "mauvaise couleur, recommencez : "; 
                cin >> color; 
            }
            Robot* robotTours = findRobot(color); 
            cout << "mouvent (haut, bas, droite, gauche) : "; 
            cin >> mvt; 
            while (mvt != "UP" &&mvt != "up"  &&mvt != "HAUT" &&mvt != "haut" &&mvt != "DOWN" &&mvt != "down" &&mvt != "BAS" &&mvt != "bas" &&mvt != "LEFT" &&mvt != "left" &&mvt != "GAUCHE" &&mvt != "gauche" &&mvt != "RIGHT" &&mvt != "right" &&mvt != "DROITE" &&mvt != "droite"){
                cout << "pas un mouvement, recommencez : "; 
                cin >> mvt; 
            }
            direction = findPosition(mvt);
            // Robot& test = findRobot(color); 
            moveRobot(findRobot(color) , direction);
            afficher_plateau(target);
        }
        cout << "fin tour"<< endl; 
        if (isTargetReached(target)){
            cout << "test reached" << endl; 
            for(int i=0;i<=4;i++){
                robots[i]->setPrevPosition(robots[i]->getPosition()); // sauvegarde position
            }
            joueurs[i]->addPoint(); // ajoute un point au joueur qui a réussi
            return true; 
        }
        for(int i=0;i<=4;i++){
            plateau[robots[i]->getPosition().getX()][robots[i]->getPosition().getY()].setRobot(nullptr);
            robots[i]->setPosition(robots[i]->getPrevPosition()); // replace les robots
            plateau[robots[i]->getPosition().getX()][robots[i]->getPosition().getY()].setRobot(robots[i]);
        }
    }
    return false; 

}

void Game::moveRobot(Robot* robot, Direction direction){
    bool blocked=false;
    while(!blocked){
        switch (direction)
        {
        case UP:
            if(plateau[robot->getPosition().getX()][robot->getPosition().getY()].getMurH()){ // teste le mur
                blocked=true;
            }
            else if(plateau[robot->getPosition().getX()][robot->getPosition().getY()-1].getRobot()!=nullptr){ // teste s'il y a un robot
                blocked=true;
            }
            else{
                plateau[robot->getPosition().getX()][robot->getPosition().getY()].setRobot(nullptr);
                robot->setPosition(Position(robot->getPosition().getX(), robot->getPosition().getY()-1)); // déplace le robot en haut
                plateau[robot->getPosition().getX()][robot->getPosition().getY()].setRobot(robot);
            }
            break;

        case DOWN:
            if(plateau[robot->getPosition().getX()][robot->getPosition().getY()].getMurB()){ // teste le mur
                blocked=true;
            }
            else if(plateau[robot->getPosition().getX()][robot->getPosition().getY()+1].getRobot()!=nullptr){ // teste s'il y a un robot
                blocked=true;
            }
            else{
                plateau[robot->getPosition().getX()][robot->getPosition().getY()].setRobot(nullptr);
                robot->setPosition(Position(robot->getPosition().getX(), robot->getPosition().getY()+1)); // déplace le robot en bas
                plateau[robot->getPosition().getX()][robot->getPosition().getY()].setRobot(robot);
            }
            break;

        case LEFT:
            if(plateau[robot->getPosition().getX()][robot->getPosition().getY()].getMurG()){ // teste le mur
                blocked=true;
            }
            else if(plateau[robot->getPosition().getX()-1][robot->getPosition().getY()].getRobot()!=nullptr){ // teste s'il y a un robot
                blocked=true;
            }
            else{
                plateau[robot->getPosition().getX()][robot->getPosition().getY()].setRobot(nullptr);
                robot->setPosition(Position(robot->getPosition().getX()-1, robot->getPosition().getY())); // déplace le robot à gauche
                plateau[robot->getPosition().getX()][robot->getPosition().getY()].setRobot(robot);
            }
            break;

        default:
            if(plateau[robot->getPosition().getX()][robot->getPosition().getY()].getMurD()){ // teste le mur
                blocked=true;
            }
            else if(plateau[robot->getPosition().getX()+1][robot->getPosition().getY()].getRobot()!=nullptr){ // teste s'il y a un robot
                blocked=true;
            }
            else{
                plateau[robot->getPosition().getX()][robot->getPosition().getY()].setRobot(nullptr);
                robot->setPosition(Position(robot->getPosition().getX()+1, robot->getPosition().getY())); // déplace le robot à droite
                plateau[robot->getPosition().getX()][robot->getPosition().getY()].setRobot(robot);
            }
            break;
        }
    }
}

// Did the robot reach the target?
bool Game::isTargetReached(const Target* target) const{
    int8_t x, y;
    x = target->getPosition().getX();
    y = target->getPosition().getY();

    if((plateau[x][y].getRobot()->getColor() == target->getColor()) || (plateau[x][y].getRobot() && target->getColor() == MULTICOLOR)){
        return true;
    }
    return false;
}

Position Game::mur_exterieur_horizontale(int quart_plateau)//genere aleatoirement un mur exterieur horizontale
{

    
    for(int i = 0;i < 100000000;i++){}// créer une attente avant de gerner un autre nombre aleatoire
    
    Position mur_hor(0,0);//init coordonnee du mur

    switch(quart_plateau){
    case premier_quart: //premier quart haut gauche      
        srand( time( NULL ) );
        mur_hor.setX(0); //x =0
        mur_hor.setY(0);
        mur_hor.setY(1 + rand() % 7);// y doit etre compris entre 1 et 7 
    break;
    case deuxieme_quart:// deuxieme quart haut droit
        srand( time( NULL ) );
        mur_hor.setX(15); //x =15
        mur_hor.setY(0);
        mur_hor.setY(1 + rand() % 7);   // y doit etre compris entre 1 et 7 
    break;
    case troisieme_quart: //troisieme quart bas droit
        srand( time( NULL ) );
        mur_hor.setX(15); //x = 15
        mur_hor.setY(0);
        mur_hor.setY(rand() % 7 + 8);  //y doit etre compris entre   8 et 14
    break;
    case quatrieme_quart:
        srand( time( NULL ) );
        mur_hor.setX(0); //x = 0
        mur_hor.setY(0);
        mur_hor.setY(rand() % 7 + 8);  //y doit etre compris entre 8 et 14
    break;

    default:
        mur_hor.setX(0);
        mur_hor.setY(0);            
  }  
   
   return mur_hor;
}

Position Game::mur_exterieur_vertical(int quart_plateau)//genere aleatoirement un mur exterieur vertical
{
    
    for(int i = 0;i < 10000000;i++){}// créer une attente pour assurer le changement de seed pour srand
    Position mur(0,0);

    switch(quart_plateau){
    case premier_quart: //quart haut gauche        
        srand( time( NULL ) );
        mur.setY(0); //y = 0
        mur.setX(0);
        mur.setX(1 + rand() % 7); //x doit etre compris entre 1 et 7
    break;
    case deuxieme_quart: //quart haut droit
        srand( time( NULL ) );
        mur.setY(0); // y = 0
        mur.setX(0);
        mur.setX(rand() % 7 + 8);    //x doit etre compris entre 8 et 14
    break;
    case troisieme_quart:
        srand( time( NULL ) );
        mur.setY(15); // y = 15
        mur.setX(0);
        mur.setX(rand() % 7 + 8);  // x dot etre entre 8 et 14  
    break;
    case quatrieme_quart:// quart bas gauche
        srand( time( NULL ) );
        mur.setY(15); //y = 15
        mur.setX(0);
        mur.setX(1 + rand() % 7);  //x doit etre compris 1 et 7  
    break;  
    default:
        mur.setX(0);
        mur.setY(0);     

  }  

  return mur; 
}


void Game::afficher_plateau(Target* target)//affiche les 16 cases du plateau
{
    //genere la ligne du bord haut
    for(int i=0;i<16;i++)
    {
        cout << " ____";
    }
    cout << endl;

    //affiche le plateau avec les 16 cases
   for(int y=0;y<16;y++)
    {
        for(int x=0; x<16;x++)
        {  
            affichage_case(target,x,y);
        }
        cout << "|" << endl;//affiche le bord droit
        
    }
}

void Game::plateauInit()
{  

    //generer mur exterieur pour les 4 quart du plateau
   for(int quart_plateau = premier_quart;quart_plateau <= quatrieme_quart; quart_plateau++)
   {
        Position premier_quart_horiz = mur_exterieur_horizontale(quart_plateau);//genere coodonnees mur exterieur vertical 
        for(int i = 0;i < 1000000000;i++){}
        Position premier_quart_vert = mur_exterieur_vertical(quart_plateau);//genere coordonnees mur ext vertical

        plateau[premier_quart_horiz.getX()][premier_quart_horiz.getY()].setMurB(1);//cree mur ext
        plateau[premier_quart_horiz.getX()][premier_quart_horiz.getY()+1].setMurH(1);//cree mur ext
        plateau[premier_quart_vert.getX()][premier_quart_vert.getY()].setMurG(1);//cree mur ext
        plateau[premier_quart_vert.getX()-1][premier_quart_vert.getY()].setMurD(1);//cree mur ext
   }  

   //generer mur interieur 
    for(int quart_plateau = premier_quart;quart_plateau<=quatrieme_quart;quart_plateau++)
    {
        for(int i = 0;i<4;i++)//gener quatre mur interieur
        {
            for(int i = 0;i < 100000000;i++){}
            murInterieur(quart_plateau);//cree le mur interieur                               
         }        
         cout << endl;
//             
    } 

    generer17emeTarget();

}

void Game::murInterieur(int quart_plateau)//genere mur interieur avec ca cible
{

    //genere position aleatoire mur interieur    
    for(int i = 0;i < 10000000;i++){}
    
    Position p(0,0);

    switch(quart_plateau){
    case premier_quart:// quart haut gauche         

        p.setX(2 + rand() % 5); // x entre 2 et 6 pour ne pas toucher mur ext ni carre centrale 
        for(int i = 0;i < 1000000;i++){}
        p.setY(2 + rand() % 5);// y entre 2 et 6 pour ne pas toucher mur ext ni carre centrale 
    break;
    case deuxieme_quart:// quart haut droit
        
        p.setX(rand() % 6 + 9);// x entre 9 et 14 pour ne pas toucher bord ni carre centrale 
        for(int i = 0;i < 1000000;i++){}
        p.setY(2 + rand() % 5); // y entre 2 et 6 pour ne pas toucher bord ni carre centrale 

    break;
    case troisieme_quart: //quart bas droit
        p.setX(rand() % 6 + 9);// x entre 9 et 14 pour ne pas toucher bord ni carre centrale 
        for(int i = 0;i < 1000000;i++){}
        p.setY(rand() % 5 + 9); // y entre 9 et 14 pour ne pas toucher bord ni carre centrale 
          
    break;
    case quatrieme_quart: //quart bas gauche
        p.setX(2 + rand() % 5);// x entre 2 et 6 pour ne pas toucher bord ni carre centrale 
        for(int i = 0;i < 1000000;i++){}
        p.setY(rand() % 5 + 9); // x entre 9 et 14 pour ne pas toucher bord ni carre centrale 
          
    break;  
    default:
        p.setX(0);
        p.setY(0);  
    }     

    //verifie qu'il ny ai pas 2 angle cote a cote
    if(plateau[p.getX()][p.getY()].getAngle() == NONE
    
        && plateau[p.getX()-1][p.getY()-1].getAngle() == NONE && plateau[p.getX()-1][p.getY()+1].getAngle() == NONE //pas d'angle diagonal bas gauche et bas droit
        && plateau[p.getX()+1][p.getY()+1].getAngle() == NONE && plateau[p.getX()+1][p.getY()-1].getAngle() == NONE //pas d'angle diagonal haut gauche et bas droit
        && plateau[p.getX()][p.getY()+1].getAngle() == NONE && plateau[p.getX()][p.getY()-1].getAngle() == NONE//pas d'angle a droite ni a gauche
        && plateau[p.getX()-1][p.getY()].getAngle() == NONE && plateau[p.getX()+1][p.getY()].getAngle() == NONE// pas d'angle ni en haut ni en bas     

        && plateau[p.getX()][p.getY()].getAngle() == NONE)//verifie que la case n'a pas deja un angle
    {
        plateau[p.getX()][p.getY()].setAngle();// cree un angle dan la case 
        //Target* newTarget = new Target(couleur,symbolTarget,p); 
        //plateau[p.getX()][p.getY()]->setTarget(newTarget);//cree une cible dans la case    
        //targets.push_back(newTarget); 

        //return newTarget;       
    }
    else
    {
        murInterieur(quart_plateau);//si il y a un angle trop proche, rappel de la fonction

    }  

}


void Game::generer17emeTarget()
{
    Position p(0,0);
    p.setX(1 + rand() % 14);
    p.setY(1 + rand() % 14);

    if((p.getX() == 7 && p.getY() == 7) || (p.getX() == 8 && p.getY() == 7) ||(p.getX() == 8 && p.getY() == 8) ||(p.getX() == 7 && p.getY() == 8) || plateau[p.getX()][p.getY()].getAngle() != NONE)
    {
        generer17emeTarget();
    }
    else
    {
        plateau[p.getX()][p.getY()].setAngle();
    }


}

void Game::genererTargets(){
    Position p(0,0); // créée une position provisoire pour la génération des cibles
    // targets rouges
    targets.push_back(new Target(RED,TRIANGLE,p));
    targets.push_back(new Target(RED,CIRCLE,p));
    targets.push_back(new Target(RED,DIAMOND,p));
    targets.push_back(new Target(RED,SQUARE,p));
    // targets jaunes
    targets.push_back(new Target(YELLOW,TRIANGLE,p));
    targets.push_back(new Target(YELLOW,CIRCLE,p));
    targets.push_back(new Target(YELLOW,DIAMOND,p));
    targets.push_back(new Target(YELLOW,SQUARE,p));    
    // targets bleues
    targets.push_back(new Target(BLUE,TRIANGLE,p));
    targets.push_back(new Target(BLUE,CIRCLE,p));
    targets.push_back(new Target(BLUE,DIAMOND,p));
    targets.push_back(new Target(BLUE,SQUARE,p));
    // targets vertes
    targets.push_back(new Target(GREEN,TRIANGLE,p));
    targets.push_back(new Target(GREEN,CIRCLE,p));
    targets.push_back(new Target(GREEN,DIAMOND,p));
    targets.push_back(new Target(GREEN,SQUARE,p));
    // target multicolore
    targets.push_back(new Target(MULTICOLOR,DIAMOND,p));

    random_shuffle(targets.begin(), targets.end()); // mélange les targets

    int cptTargets=0;
    for(int x=0;x<16;x++){
        for(int y=0;y<16;y++){
            if(plateau[x][y].getAngle()!=NONE){
                plateau[x][y].setTarget(targets[cptTargets]);
                p.setX(x);
                p.setY(y);
                targets[cptTargets]->setPosition(p);
                cptTargets++;
            }
        }
    }
}

vector<Target*> Game::getTargetVector(void){
    return targets;
}

vector<Player*> Game::getPlayerVector(void){
    return joueurs;
}

void Game::affichage_case(Target* target, int x, int y)//gere l'affichage d'une seul case : murG et murB
{
    
    //carre centrale du plateau
    plateau[7][7].setMurG(true);
    plateau[7][7].setMurH(true);
    plateau[7][7].setTarget(target);

    plateau[8][7].setMurD(true);
    plateau[8][7].setMurH(true);
    plateau[8][7].setTarget(target);

    plateau[7][8].setMurB(true);
    plateau[7][8].setMurG(true);
    plateau[7][8].setTarget(target);

    plateau[8][8].setMurD(true);
    plateau[8][8].setMurB(true);
    plateau[8][8].setTarget(target);
 

    //bord du plateaau 
    for(int i=0;i<16;i++)
    {
        plateau[i][0].setMurH(true);
        plateau[15][i].setMurD(true);
        plateau[i][15].setMurB(true); 
        plateau[0][i].setMurG(true);
    }

    //Si il y a un angle bas droit OU il y a un mur haut sur la case dessous   
    if((plateau[x][y].getMurG() == false && plateau[x][y].getMurB() == true) || (y<14 && plateau[x][y].getMurG() == false &&  plateau[x][y+1].getMurH()== true))
    {
        if(plateau[x][y].getRobot() != nullptr)
        {
            cout << ":" << plateau[x][y].getRobot()->getCaractereColorRobot() << "";//affiche dans la case initiales robot si il y en a un
        }
        else if(plateau[x][y].getTarget() != nullptr)
        {
            cout << ":_" << plateau[x][y].getTarget()->getCaracteresTarget() << "_";//affiche dans la case initiales Target si il y en a une
            
        }
        else
        {
            cout << ":____";//sinon affiche trait plein
        }
        
    }
    //angle haut gauche OU case precedente gauche a un mur droit
    else if((plateau[x][y].getMurG() == true && plateau[x][y].getMurB() == false) || (x>0 && plateau[x-1][y].getMurD() == true && plateau[x][y].getMurB() == false))
    {
        if(plateau[x][y].getRobot() != nullptr)
        {
            cout << "|" << plateau[x][y].getRobot()->getCaractereColorRobot() << "";
        }
       else if(plateau[x][y].getTarget() != nullptr)
        {
            cout << "|." << plateau[x][y].getTarget()->getCaracteresTarget() << ".";
            
        }        
        else
        {        
            cout << "|....";
        }
    }
    //angle bas droit
    else if((plateau[x][y].getMurG() == true && plateau[x][y].getMurB() == true))
    {
        if(plateau[x][y].getRobot() != nullptr) 
        {
            cout << "|" << plateau[x][y].getRobot()->getCaractereColorRobot() << "";
        }
       else if(plateau[x][y].getTarget() != nullptr)
        {
            cout << "|_" << plateau[x][y].getTarget()->getCaracteresTarget() << "_";
            
        }        
        else
        {        
            cout << "|____";
        }    
    }
    //angle haut droit OU pas d'angle
    else
    {
        if(plateau[x][y].getRobot() != nullptr)
        {
            cout << ":" << plateau[x][y].getRobot()->getCaractereColorRobot() << "";
        }
       else if(plateau[x][y].getTarget() != nullptr)
        {
            cout << ":." << plateau[x][y].getTarget()->getCaracteresTarget() << ".";
        }
        else if(plateau[x][y].getRobot() == nullptr || plateau[x][y].getRobot()->getPosition().getX() != y || plateau[x][y].getRobot()->getPosition().getY() != x)
        {        
            cout << ":....";
        }    
    }
}