#include <iostream>
#include <ctime>
#include <cstdlib>
#include "utilitaires.hpp"
#include "../Case/Case.hpp"
#include "../Target/Target.hpp"

using namespace std;

coordonnees_mur_aleatoire mur_horizontale(quart cote)
{

    
    for(int i = 0;i < 1000000;i++){}// créer une attente pour assurer le changement de seed pour srand
    
    coordonnees_mur_aleatoire mur;
    mur.x = 0;
    mur.y = 0;
    switch(cote){
    case 0:         
        srand( time( NULL ) );
        mur.x = 0;
        mur.y =0;
        mur.y = rand() % 7;
    break;
    case 1:
        srand( time( NULL ) );
        mur.x = 15;
        mur.y =0;
        mur.y = rand() % 7;    
    break;
    case 2:
        srand( time( NULL ) );
        mur.x = 15;
        mur.y =0;
        mur.y = rand() % 9 + 7;    
    break;
    case 3:
        srand( time( NULL ) );
        mur.x = 0;
        mur.y =0;
        mur.y = rand() % 9 + 7;    
    break;

    default:
        mur.x = 0;
        mur.y = 0;            
  }  
   
   return mur;
}

coordonnees_mur_aleatoire mur_vertical(int cote)
{
    
    for(int i = 0;i < 1000000;i++){}// créer une attente pour assurer le changement de seed pour srand
    
    
    coordonnees_mur_aleatoire mur;
    mur.x = 0;
    mur.y = 0;
    switch(cote){
    case 0:         
        srand( time( NULL ) );
        mur.y = 0;
        mur.x = 0;
        mur.x = rand() % 7;
    break;
    case 1:
        srand( time( NULL ) );
        mur.y = 0;
        mur.x = 0;
        mur.x = rand() % 9 + 7;    
    break;
    case 2:
        srand( time( NULL ) );
        mur.y = 15;
        mur.x = 0;
        mur.x = rand() % 9 + 7;    
    break;
    case 3:
        srand( time( NULL ) );
        mur.y = 15;
        mur.x = 0;
        mur.x = rand() % 7;    
    break;  
    default:
        mur.x = 0;
        mur.y = 0;     

  }  

  return mur; 
}

Case *creerPlateau(Case* c[16][16])
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

void afficher_plateau(Case* c[16][16])
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


void mur_aleatoire(Case* plateau[16][16])
{
   coordonnees_mur_aleatoire mur_hor_premier_quart = mur_horizontale(premier_quart);
   coordonnees_mur_aleatoire mur_vert_premier_quart = mur_vertical(premier_quart);

   coordonnees_mur_aleatoire mur_hor_deuxieme_quart = mur_horizontale(deuxieme_quart);
   coordonnees_mur_aleatoire mur_vert_deuxieme_quart = mur_vertical(deuxieme_quart);

   coordonnees_mur_aleatoire mur_hor_troisieme_quart = mur_horizontale(troisieme_quart);
   coordonnees_mur_aleatoire mur_vert_troisieme_quart = mur_vertical(troisieme_quart);

   coordonnees_mur_aleatoire mur_hor_quatrieme_quart = mur_horizontale(quatrieme_quart);
   coordonnees_mur_aleatoire mur_vert_quatrieme_quart = mur_vertical(quatrieme_quart);   
    

    plateau[mur_hor_premier_quart.x][mur_hor_premier_quart.y]->setMurG(1);
    plateau[mur_vert_premier_quart.x][mur_vert_premier_quart.y]->setMurB(1);
        
    plateau[mur_hor_deuxieme_quart.x][mur_hor_deuxieme_quart.y]->setMurG(1);
    plateau[mur_vert_deuxieme_quart.x][mur_vert_deuxieme_quart.y]->setMurB(1);

    plateau[mur_hor_troisieme_quart.x][mur_hor_troisieme_quart.y]->setMurG(1);
    plateau[mur_vert_troisieme_quart.x][mur_vert_troisieme_quart.y]->setMurB(1);
        
    plateau[mur_hor_quatrieme_quart.x][mur_hor_quatrieme_quart.y]->setMurG(1);
    plateau[mur_vert_quatrieme_quart.x][mur_vert_quatrieme_quart.y]->setMurB(1);  
}

void angleAleatoire(Case* plateau[16][16], quart cote)
{
    for(int i = 0;i < 1000000;i++){}// créer une attente pour assurer le changement de seed pour srand

    int x = 0;
    int y = 0;
    Target* target;
    

    switch(cote){
    case premier_quart:         
        srand( time( NULL ) );
        x = 1 + rand() % 6;
        srand( time( NULL ) );
        for(int i = 0;i < 10000000;i++){}
        y = 1 + rand() % 6;
    break;
    case deuxieme_quart:
        srand( time( NULL ) );
        x = rand() % 8 + 7;
        srand( time( NULL ) );
        for(int i = 0;i < 10000000;i++){}
        y = 1 + rand() % 6;     
    break;
    case troisieme_quart:
        srand( time( NULL ) );
        x = rand() % 8 + 7;
        srand( time( NULL ) );
        for(int i = 0;i < 10000000;i++){}
        y = rand() % 8 + 7;    
    break;
    case quatrieme_quart:
        srand( time( NULL ) );
        x = 1 + rand() % 6;
        srand( time( NULL ) );
        for(int i = 0;i < 10000000;i++){}
        y = rand() % 8 + 7;    
    break;  
    default:
        x = 0;
        y = 0;  
    } 

    plateau[x][y]->setAngle();
    target = new Target(YELLOW,DIAMOND,Position(y,x));
    plateau[x][y]->setTarget(target);
}




