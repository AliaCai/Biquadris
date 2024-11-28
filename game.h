#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "interpreter.h"
#include "board.h"
#include <memory>
using namespace std;

class Board;
class Interpreter;

class Game {
    //Board* b1;
    //Board* b2;

    unique_ptr<Board> b1, b2;
    unique_ptr<Interpreter> interpreter1, interpreter2;
    bool player1;
    unique_ptr<TextDisplay> td1;
    unique_ptr<GraphicsDisplay> gd1;
    unique_ptr<TextDisplay> td2;
    unique_ptr<GraphicalDisplay> gd2;

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
