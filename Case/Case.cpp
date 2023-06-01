#include "Case.hpp"

// Getteurs
bool Case::getMurH() const{ return murH; }
bool Case::getMurD() const{ return murD; }
bool Case::getMurB() const{ return murB; }
bool Case::getMurG() const{ return murG; }
bool Case::getOccupe() const{ return occupe; }

Target Case::getCible() const{ return cible; }

//Setteurs
void Case::setMurH(bool mur){ murH = mur; }
void Case::setMurD(bool mur){ murD = mur; }
void Case::setMurB(bool mur){ murB = mur; }
void Case::setMurG(bool mur){ murG = mur; }
void Case::setOccupe(bool occ){ occupe = occ; }

void Case::getCible(Target target){ cible = target; }