#pragma once
#include "string"
#include "stdlib.h"

#include "../util.hpp"
#include "../Robot/Robot.hpp"
#include "../Target/Target.hpp"

enum Angle {
    HG,
    HD,
    BD,
    BG,
    NONE
};

class Case {
private:
    bool murH, murD, murB, murG;
    Angle angle;
    Robot* robot;
    Target* target;

public:

    // Setteurs
    void setMurH(bool mur);
    void setMurD(bool mur);
    void setMurB(bool mur);
    void setMurG(bool mur);

    void setAngle();

    // Getteurs
    bool getMurH(void) const;
    bool getMurD(void) const;
    bool getMurB(void) const;
    bool getMurG(void) const;

    Angle getAngle(void) const;

    // Robot
    void setRobot(Robot* newRobot);
    Robot* getRobot(void) const;

    // Target
    void setTarget(Target* newTarget);
    Target* getTarget(void) const;

    void affichage_case(Case* c[16][16],int x, int y);

    //constructeur
    Case();
};