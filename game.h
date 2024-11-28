#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "interpreter.h"
#include "board.h"

class Game {
    //Board* b1;
    //Board* b2;

    std::unique_ptr<Board> b1, b2;
    std::unique_ptr<Interpreter> interpreter1, interpreter2;
    bool player1;

    public:
    void take_turn();
    //void generateBlock();
    bool has_won();
    void reset();
    //Board* get_board();
    int get_turn(); 
    Game(); //initialises the game
};

#endif
