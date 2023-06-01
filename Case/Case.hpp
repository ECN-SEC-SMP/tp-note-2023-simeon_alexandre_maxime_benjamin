#pragma once 
#include <iostream>

#include "../Position/Position.hpp"
#include "../Robot/Robot.hpp"
#include "../Target/Target.hpp"

class Case {
private:
    bool murH, murD, murB, murG, occupe;
    Target cible;

public:
    // Getteurs
    bool getMurH() const;
    bool getMurD() const;
    bool getMurB() const;
    bool getMurG() const;
    bool getOccupe() const;

    Target getCible() const;

    //Setteurs
    void setMurH(bool mur);
    void setMurD(bool mur);
    void setMurB(bool mur);
    void setMurG(bool mur);
    void setOccupe(bool occ);

    void getCible(Target target);
};