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
    Game g;
    g.iniGame(); // Instantiate the Game object with the vectors of robots and targets
    for(int turn=0;turn<=17;turn++){
        g.playTurn(g.getTargetVector()[turn]);
    }
    for(int i; i<g.getPlayerVector().size(); i++){
        cout << "Score de " << g.getPlayerVector()[i]->getName() << " : " << g.getPlayerVector()[i]->getScore() << endl;
    }
}