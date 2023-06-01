#include "Case.hpp"

Case::Case() : murH(false), murD(false), murB(false), murG(false) {}

void Case::setMurH(){
    murH=true;
}

void Case::setMurD(){
    murD=true;
}

void Case::setMurB(){
    murB=true;
}

void Case::setMurG(){
    murG=true;
}

bool Case::getMurH() const{
    return murH;
}

bool Case::getMurD() const{
    return murD;
}

bool Case::getMurB() const{
    return murB;
}

bool Case::getMurG() const{
    return murG;
}

void Case::setRobot(Robot newRobot){
    robot=newRobot;
}

Robot Case::getRobot(){
    return robot;
}

void Case::setTarget(Target newTarget){
    target=newTarget;
}

Target Case::getTarget(){
    return target;
}