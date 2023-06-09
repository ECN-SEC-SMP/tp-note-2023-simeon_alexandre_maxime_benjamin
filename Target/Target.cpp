#include "Target.hpp"
#include "../util.hpp"
#include "../Position/Position.hpp"


Target::Target(Color _color, Symbol _symbol, Position _position) : color(_color), symbol(_symbol), position(_position) {}

Color Target::getColor() const {
    return color;
}

Symbol Target::getSymbol() const {
    return symbol;
}

Position Target::getPosition() const {
    return position;
}

void Target::setPosition(Position p){
    position=p;
}

std::string Target::getCaracteresTarget()// retourne initial symbol + initlale couleur
{
    switch(this->symbol){

        case TRIANGLE:
            if(this->color == RED)
            {
                return "TR";
            }
            else if(this->color == BLUE)
            {
                return "TB";
            }
            else if(this->color == YELLOW)
            {
                return "TY";
            }
            else if(this->color == GREEN)
            {
                return "TG";
            }
            else if(this->color == MULTICOLOR)
            {
                return "TM";  
            }                                 
        break;
        case SQUARE:
            if(this->color == RED)
            {
                return "SR";
            }
            else if(this->color == BLUE)
            {
                return "SB";
            }
            else if(this->color == YELLOW)
            {
                return "SY";
            }
            else if(this->color == GREEN)
            {
                return "SG";
            } 
            else if(this->color == MULTICOLOR)
            {
                return "SM";  
            }                  
        break;
        case CIRCLE:
            if(this->color == RED)
            {
                return "CR";
            }
            else if(this->color == BLUE)
            {
                return "CB";
            }
            else if(this->color == YELLOW)
            {
                return "CY";
            }
            else if(this->color == GREEN)
            {
                return "CG";
            }  
            else if(this->color == MULTICOLOR)
            {
                return "CM";  
            }            
        break;
        case DIAMOND:
            if(this->color == RED)
            {
                return "DR";
            }
            else if(this->color == BLUE)
            {
                return "DB";
            }
            else if(this->color == YELLOW)
            {
                return "DY";
            }
            else if(this->color == GREEN)
            {
                return "DG";
            }
            else if(this->color == MULTICOLOR)
            {
                return "DM";  
            }
                        
        break;
    }
    return "..";

}