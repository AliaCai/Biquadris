#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "board.h"

class Game {
    Board* b1;
    Block * curB1;
    Block * nextB1;

    Board* b2;
    Block * curB2;
    Block * nextB2;

    bool player1;

    public:
    void take_turn();
    void generateBlock();
    bool has_won();
    void reset();
    Board* get_board();
    int get_turn(); 
    Game(); //initialises the game
};

#endif
