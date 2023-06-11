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
            else nbok = true; 
        }
        int nb = atoi(nbc.c_str()); // conversion en entier
        for (unsigned i =0;i<nbmvt.size(); i++){
            if (nb >=nbmvt[i]){
               nbmvt.insert(nbmvt.begin()+i, nb);
               ordrePlayer.insert(ordrePlayer.begin()+i, temp);
            }
        } 
        nbval++; 
    }
    // while (! target reached)
    cout << "realisation des tours"<< joueurs.size()<< endl; 
    for (unsigned i=0; i<joueurs.size();i++){ // laisser les joueurs réaliser leurs essais 
        cout<< "entree for : " << joueurs[i]<< "nbmvt : " << nbmvt[i] <<  endl;
        for (unsigned u =0; u<nbmvt[i]; u++){ //le joueur va réaliser les n mvt qu'il a indiqué 
            cout << "couleur robot : "; 
            cin >> color; 
            while (color != "RED" || "red" || "ROUGE"|| "rouge" ||"BLUE" || "blue" || "BLEU" || "bleu" || "YELLOW" || "yellow" || "JAUNE" || "jaune" || "GREEN" || "green" || "VERT" || "vert"){
                cout << "mauvaise couleur, recommencez : "; 
                cin >> color; 
            }
            Robot* robotTours = findRobot(color); 
            cout << "mouvent (haut, bas, droite, gauche) : "; 
            cin >> mvt; 
            while (mvt != "UP" || "up"  || "HAUT" || "haut" || "DOWN" || "down" || "BAS" || "bas" || "LEFT" || "left" || "GAUCHE" || "gauche" || "RIGHT" || "right" || "DROITE" || "droite"){
                cout << "pas un mouvement, recommencez : "; 
                cin >> mvt; 
            }
            direction = findPosition(mvt);
            // Robot& test = findRobot(color); 
            // moveRobot(findRobot(color) , direction);

        }
        // isTargetReached test target 
    }
    // } fin while

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
            else if(plateau[robot.getPosition().getX()][robot.getPosition().getY()-1].getRobot()!=nullptr){ // teste s'il y a un robot
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
            else if(plateau[robot.getPosition().getX()][robot.getPosition().getY()+1].getRobot()!=nullptr){ // teste s'il y a un robot
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
            else if(plateau[robot.getPosition().getX()-1][robot.getPosition().getY()].getRobot()!=nullptr){ // teste s'il y a un robot
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
            else if(plateau[robot.getPosition().getX()+1][robot.getPosition().getY()].getRobot()!=nullptr){ // teste s'il y a un robot
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

Case* Game::creerPlateau(Case* c[16][16])
{ 
    //instanciation des 16 cases du plateau   
    for(int y=0;y<16;y++)
    {
        for(int x=0; x<16;x++)
        {            
            c[y][x] = new Case();                 
          
        }
    }

    return c[16][16]; //retourne le plateau
}

void Game::afficher_plateau(Case* c[16][16])//affiche les 16 cases du plateau
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
            c[y][x]->affichage_case(c,x,y);
            
        }
        cout << "|" << endl;//affiche le bord droit
        
    }
}


void Game::plateauInit(Case* plateau[16][16])
{
    //generer mur exterieur pour les 4 quart du plateau
   for(int quart_plateau = premier_quart;quart_plateau <= quatrieme_quart; quart_plateau++)
   {
        Position premier_quart_horiz = mur_exterieur_horizontale(quart_plateau);//genere coodonnees mur exterieur vertical 
        for(int i = 0;i < 1000000000;i++){}
        Position premier_quart_vert = mur_exterieur_vertical(quart_plateau);//genere coordonnees mur ext vertical

        plateau[premier_quart_horiz.getX()][premier_quart_horiz.getY()]->setMurG(1);//cree mur ext
        plateau[premier_quart_vert.getX()][premier_quart_vert.getY()]->setMurB(1);//cree mur int
   }  

   //generer mur interieur et leur cible pour chaque quart
    for(int quart_plateau = premier_quart;quart_plateau<=quatrieme_quart;quart_plateau++)
    {
        Symbol symbolTarget;

        for(int i = 0;i<4;i++)//gener quatre mur interieur
        {
            //une forme par quart
            if(i == 0)
            {
                symbolTarget  = TRIANGLE;
            }
            else if(i == 1)
            {
                symbolTarget  = CIRCLE;
            } 
            else if(i == 2)
            {
                symbolTarget  = SQUARE;
            }   
            else if(i == 3)
            {
                symbolTarget  = DIAMOND;
            }    

            for(int i = 0;i < 100000000;i++){}
            murInterieur(plateau,quart_plateau,symbolTarget);//cree le mur interieur          
        }        
        cout << endl;
    } 

}

void Game::murInterieur(Case* plateau[16][16], int quart_plateau,Symbol symbolTarget)//genere mur interieur avec ca cible
{
    //genrre couleur aleatoire pour target
   int c = 0;
   Color couleur;
    c = rand() % 5;// 5 choix de couleur entre 0 et 4
    switch(c){
        case 0:
            couleur = RED;
        break;
        case 1:
            couleur = YELLOW;
        break;  
        case 2:
            couleur = BLUE;
        break;
        case 3:
            couleur = GREEN;
        break;  
        default :
            couleur  = MULTICOLOR;            
    } 

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
    if(plateau[p.getY()][p.getX()]->getAngle() == NONE
    
        && plateau[p.getY()-1][p.getX()-1]->getAngle() == NONE && plateau[p.getY()-1][p.getX()+1]->getAngle() == NONE //pas d'angle diagonal bas gauche et bas droit
        && plateau[p.getY()+1][p.getX()+1]->getAngle() == NONE && plateau[p.getY()+1][p.getX()-1]->getAngle() == NONE //pas d'angle diagonal haut gauche et bas droit
        && plateau[p.getY()][p.getX()+1]->getAngle() == NONE && plateau[p.getY()][p.getX()-1]->getAngle() == NONE//pas d'angle a droite ni a gauche
        && plateau[p.getY()-1][p.getX()]->getAngle() == NONE && plateau[p.getY()+1][p.getX()]->getAngle() == NONE// pas d'angle ni en haut ni en bas     

        && plateau[p.getY()][p.getX()]->getAngle() == NONE)//verifie que la case n'a pas deja un angle
    {
        plateau[p.getY()][p.getX()]->setAngle();// cree un angle dan la case 
        Target* newTarget = new Target(couleur,symbolTarget,p); 
        plateau[p.getY()][p.getX()]->setTarget(newTarget);//cree une cible dans la case            
    }
    else
    {
        murInterieur(plateau,quart_plateau,symbolTarget);//si il y a un angle trop proche, rappel de la fonction

    }      

}

