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

Position Game::mur_exterieur_horizontale(int quart_plateau)
{

    
    for(int i = 0;i < 100000000;i++){}// créer une attente pour assurer le changement de seed pour srand
    
    Position mur_hor(0,0);
    switch(quart_plateau){
    case 0:         
        srand( time( NULL ) );
        mur_hor.setX(0);
        mur_hor.setY(0);
        mur_hor.setY(1 + rand() % 6);
    break;
    case 1:
        srand( time( NULL ) );
        mur_hor.setX(15);
        mur_hor.setY(0);
        mur_hor.setY(1 + rand() % 6);    
    break;
    case 2:
        srand( time( NULL ) );
        mur_hor.setX(15);
        mur_hor.setY(0);
        mur_hor.setY(rand() % 9 + 6);    
    break;
    case 3:
        srand( time( NULL ) );
        mur_hor.setX(0);
        mur_hor.setY(0);
        mur_hor.setY(rand() % 9 + 6);    
    break;

    default:
        mur_hor.setX(0);
        mur_hor.setY(0);            
  }  
   
   return mur_hor;
}

Position Game::mur_exterieur_vertical(int quart_plateau)
{
    
    for(int i = 0;i < 10000000;i++){}// créer une attente pour assurer le changement de seed pour srand
    Position mur(0,0);
    switch(quart_plateau){
    case premier_quart:         
        srand( time( NULL ) );
        mur.setY(0);
        mur.setX(0);
        mur.setX(1 + rand() % 7);
    break;
    case deuxieme_quart:
        srand( time( NULL ) );
        mur.setY(0);
        mur.setX(0);
        mur.setX(rand() % 9 + 7);    
    break;
    case troisieme_quart:
        srand( time( NULL ) );
        mur.setY(15);
        mur.setX(0);
        mur.setX(rand() % 9 + 7);    
    break;
    case quatrieme_quart:
        srand( time( NULL ) );
        mur.setY(15);
        mur.setX(0);
        mur.setX(1 + rand() % 7);    
    break;  
    default:
        mur.setX(0);
        mur.setY(0);     

  }  

  return mur; 
}

Case* Game::creerPlateau(Case* c[16][16])
{    
    for(int i=0;i<16;i++)
    {
        for(int j=0; j<16;j++)
        {            
            c[i][j] = new Case();                 
          
        }
    }

    return c[16][16];
}

void Game::afficher_plateau(Case* c[16][16])
{
    for(int i=0;i<16;i++)
    {
        cout << " ____";
    }
    cout << endl;

   for(int y=0;y<16;y++)
    {
        for(int x=0; x<16;x++)
        {  
            c[y][x]->affichage_case(c,x,y);
            
        }
        cout << "|" << endl;
        
    }
}


void Game::plateauInit(Case* plateau[16][16])
{
    //generer mur exterieur
   for(int quart_plateau = premier_quart;quart_plateau <= quatrieme_quart; quart_plateau++)
   {
        Position premier_quart_horiz = mur_exterieur_horizontale(quart_plateau);
        for(int i = 0;i < 1000000000;i++){}
        Position premier_quart_vert = mur_exterieur_vertical(quart_plateau);

        plateau[premier_quart_horiz.getX()][premier_quart_horiz.getY()]->setMurG(1);
        plateau[premier_quart_vert.getX()][premier_quart_vert.getY()]->setMurB(1);
   }  

   //generer mur interieur et leur cible
    for(int quart_plateau = premier_quart;quart_plateau<=quatrieme_quart;quart_plateau++)
    {
        Symbol symbolTarget;
        for(int i = 0;i<4;i++)
        {
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
            murInterieur(plateau,quart_plateau,symbolTarget);          
        }        
        cout << endl;
    } 

            //generer robot
        genererRobot(plateau,RED);
        genererRobot(plateau,BLUE);
        genererRobot(plateau,YELLOW);
        genererRobot(plateau,GREEN);
    
}

void Game::murInterieur(Case* plateau[16][16], int quart_plateau,Symbol symbolTarget)
{
    //Target
   int c = 0;
    Color couleur;
    c = rand() % 5;
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

    //mur interieur    
    for(int i = 0;i < 10000000;i++){}// créer une attente pour assurer le changement de seed pour srand
    Position p(0,0);
    switch(quart_plateau){
    case premier_quart:         

        p.setX(2 + rand() % 5);
        for(int i = 0;i < 1000000;i++){}
        p.setY(2 + rand() % 5);
    break;
    case deuxieme_quart:
        
        p.setX(rand() % 6 + 9);
        for(int i = 0;i < 1000000;i++){}
        p.setY(2 + rand() % 5); 

    break;
    case troisieme_quart:
        p.setX(rand() % 5 + 10);
        for(int i = 0;i < 1000000;i++){}
        p.setY(rand() % 5 + 9); 
          
    break;
    case quatrieme_quart:
        p.setX(2 + rand() % 5);
        for(int i = 0;i < 1000000;i++){}
        p.setY(rand() % 5 + 9); 
          
    break;  
    default:
        p.setX(0);
        p.setY(0);  
    }     

    if(plateau[p.getY()][p.getX()]->getAngle() == NONE
    
        && plateau[p.getY()-1][p.getX()-1]->getAngle() == NONE && plateau[p.getY()-1][p.getX()+1]->getAngle() == NONE
        && plateau[p.getY()+1][p.getX()+1]->getAngle() == NONE && plateau[p.getY()+1][p.getX()-1]->getAngle() == NONE
        && plateau[p.getY()][p.getX()+1]->getAngle() == NONE && plateau[p.getY()][p.getX()-1]->getAngle() == NONE
        && plateau[p.getY()-1][p.getX()]->getAngle() == NONE && plateau[p.getY()+1][p.getX()]->getAngle() == NONE

        && plateau[p.getY()][p.getX()-1]->getAngle() == NONE && plateau[p.getY()][p.getX()+1]->getAngle() == NONE
        && plateau[p.getY()+1][p.getX()]->getAngle() == NONE && plateau[p.getY()-1][p.getX()]->getAngle() == NONE     

        && plateau[p.getY()][p.getX()]->getAngle() == NONE)
    {
        plateau[p.getY()][p.getX()]->setAngle();
        Target* newTarget = new Target(couleur,symbolTarget,p); 
        plateau[p.getY()][p.getX()]->setTarget(newTarget);            
    }
    else
    {
        murInterieur(plateau,quart_plateau,symbolTarget);

    }      

}

void Game::genererRobot(Case* plateau[16][16],Color _color)
{
    Position p(0,0);
    p.setX(rand() % 15);
    p.setY(rand() % 15);

    if((p.getX()==7 && p.getX()==7) || (p.getX()==7 && p.getX()==8) || (p.getX()==8 && p.getX()==8) || (p.getX()==8 && p.getX()==7))
    {
        genererRobot(plateau,_color);
    }
    else{
        Robot* r = new Robot(_color,p);
        plateau[p.getY()][p.getX()]->setRobot(r);
    }
}