#ifndef GRAPHICAL_DISPLAY_H
#define GRAPHICAL_DISPLAY_H
#include "observer.h"
#include "window.h"
#include "board.h"
#include <iostream>
using namespace std;

class Board;

class GraphicalDisplay: public Observer {
    vector<shared_ptr<Board>> subject;
    Xwindow w;

    public:
    GraphicalDisplay(vector<shared_ptr<Board>> subject2); // constructor
    void notify() override;
    int getColor(char c);
    vector<vector<char>> blockGrid(char type);
    ~GraphicalDisplay(); // destructor
};

#endif
