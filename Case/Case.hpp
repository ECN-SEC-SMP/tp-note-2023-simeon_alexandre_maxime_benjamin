#pragma once
#include "string"
#include "stdlib.h"

#include "../Robot/Robot.hpp"
#include "../Target/Target.hpp"

class Case {
private:
    bool murH;
    bool murD;
    bool murB;
    bool murG;
    Robot robot;
    Target target;

public:
    Case(void);
    void setMurH(void);
    void setMurD(void);
    void setMurB(void);
    void setMurG(void);

    bool getMurH(void) const;
    bool getMurD(void) const;
    bool getMurB(void) const;
    bool getMurG(void) const;

    void setRobot(Robot newRobot);
    Robot getRobot(void);

    void setTarget(Target newTarget);
    Target getTarget(void);
};