#pragma once
#include "string"
#include "stdlib.h"

#include "../Robot/Robot.hpp"
#include "../Target/Target.hpp"

enum Angle {
    HD,
    BD,
    BG,
    HG,
    NONE
};

class Case {
private:
    bool murH, murD, murB, murG;
    Angle angle;
    Robot* robot;
    Target* target;

public:
    Case(void);

    // Setteurs
    void setMurH(bool mur);
    void setMurD(bool mur);
    void setMurB(bool mur);
    void setMurG(bool mur);

    void setAngle(Angle newAngle);

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
};