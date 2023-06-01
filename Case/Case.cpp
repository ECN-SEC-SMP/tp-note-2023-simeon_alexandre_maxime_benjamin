#include "Case.hpp"

Case::Case() : murH(false), murD(false), murB(false), murG(false) {}

// Getteurs
bool Case::getMurH() const{ return murH; }
bool Case::getMurD() const{ return murD; }
bool Case::getMurB() const{ return murB; }
bool Case::getMurG() const{ return murG; }

Robot Case::getRobot() const{ return robot; }
Target Case::getTarget() const{ return target; }

//Setteurs
void Case::setMurH(bool mur){ murH = mur; }
void Case::setMurD(bool mur){ murD = mur; }
void Case::setMurB(bool mur){ murB = mur; }
void Case::setMurG(bool mur){ murG = mur; }

void Case::setRobot(Robot newRobot) { robot=newRobot; }
void Case::setTarget(Target newTarget) { target = newTarget; }
