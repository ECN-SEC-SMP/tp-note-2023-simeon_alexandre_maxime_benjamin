#include <iostream>
#include "Board/Board.hpp"
#include "Game/Game.hpp"
#include "Position/Position.hpp"
#include "Robot/Robot.hpp"
#include "Target/Target.hpp"

using namespace std;

int main() { 
    cout << "Hello everybody!\n"; 

    // Instanciation
    Position pos1(10, 5);
    Robot robot1(BLUE, pos1);

    cout << "Couleur du robot : " << robot1.getColor() << endl;
}