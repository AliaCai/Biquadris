#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "interpreter.h"
#include "board.h"
#include "subject.h"
#include "graphical_display.h"
#include "observer.h"
#include <memory>
#include <vector>
using namespace std;


class Board;
class Interpreter;

class Game: public Subject
{

    shared_ptr<Board> b1, b2;
    shared_ptr<Interpreter> interpreter1, interpreter2;
    bool player1;
    string fn1;
    string fn2;
    vector<shared_ptr<Observer>> gd;

public:
    void take_turn();
    bool has_won();
    void reset();
    int get_turn();
    void printBoards();
    vector<vector<char>> blockGrid(char type); 
    Game(string fn1, string fn2); //initialises the game
};

#endif
