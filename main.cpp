#include <iostream>
#include "Game/Game.hpp"
#include "Position/Position.hpp"
#include "Robot/Robot.hpp"
#include "Target/Target.hpp"
#include "util.hpp" // test

using namespace std;

int main() { 
    cout << "Hello everybody!\n"; 

    // Instanciation
    // Position pos1(10, 5);
    // Robot robot1(BLUE, pos1);
    // Target t(RED, CIRCLE);
    // Game g( Robot& robots, Target& targets);
    // g.iniGame(); 
    // cout << "Couleur du robot : " << robot1.getColor() << endl;
    std::vector<Robot> robots; // Create a vector of Robot objects
    std::vector<Target> targets; // Create a vector of Target objects

    // Add Robot and Target objects to the vectors (example)
    // robots.push_back(Robot(/* arguments for Robot constructor */));
    // targets.push_back(Target(/* arguments for Target constructor */));

    Game g;
    g.iniGame(); // Instantiate the Game object with the vectors of robots and targets
    // g.iniGame();
    // for (int i =  0, i = Color.getvalue())
    
     
}