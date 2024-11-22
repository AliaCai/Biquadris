#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "board.h"

class Game {
    Board* b1;
    Board* b2;
    int turn;

    public:
    void take_turn();
    bool has_won();
    void reset();
    Board* get_board();
    int get_turn();
    Game(Board* b1, Board* b2, int turn);
};

#endif
