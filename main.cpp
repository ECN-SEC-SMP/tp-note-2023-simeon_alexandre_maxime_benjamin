/**
 * @defgroup main main.cpp
 * projet pricpila
 * @image{inline} html Capture.PNG "use case"
* 
*/

#include <iostream>
#include "Game/Game.hpp"
#include "Position/Position.hpp"
#include "Robot/Robot.hpp"
#include "Target/Target.hpp"

#include "Case/Case.hpp"
#include "util.hpp" // test

using namespace std;



int main() { 



    srand( time( NULL ) );  
    Case* plateau[16][16] = {nullptr}; 
    Game g;
    g.iniGame(); // Instantiate the Game object with the vectors of robots and targets
    g.playTurn();
    //g.iniGame();
    //for (int i =  0, i = Color.getvalue());

    // g.creerPlateau(plateau);
    // g.plateauInit(plateau);
    // g.afficher_plateau(plateau);

     
}