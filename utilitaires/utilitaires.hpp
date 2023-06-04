#include "../Case/Case.hpp"

struct coordonnees_mur_aleatoire{
    int x;
    int y;
};

enum quart{
    premier_quart,
    deuxieme_quart,
    troisieme_quart,
    quatrieme_quart    
};

coordonnees_mur_aleatoire mur_horizontale(quart cote);
coordonnees_mur_aleatoire mur_vertical(int cote);
void afficher_plateau(Case* c[16][16]);
Case *creerPlateau(Case* c[16][16]);
void mur_aleatoire(Case* plateau[16][16]);