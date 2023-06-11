#pragma once
/**
 * @defgroup util util.hpp
 * 
* 
*/

enum Color {
    RED,
    YELLOW,
    BLUE,
    GREEN,
    MULTICOLOR
};

enum Symbol {
    CIRCLE,
    SQUARE,
    TRIANGLE,
    DIAMOND,
};

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

enum Angle {
    HD,
    BD,
    BG,
    HG,
    NONE
};

enum quartPlateau{
    premier_quart, //haut gauche
    deuxieme_quart, //haut droit
    troisieme_quart, //bas droit
    quatrieme_quart  //bas gauche  
};
