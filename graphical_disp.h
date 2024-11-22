#ifndef GRAPHICAL_DISP_H
#define GRAPHICAL_DISP_H
#include "observer.h"
#include "window.h"
#include "board.h"
#include <iostream>

class GraphicalDisplay: public Observer {
    Board* subject;
    int top, bottom, left, right;

    public:
    GraphicalDisplay(Board* subject, int top, int bottom, int left, int right); // constructor
    void notify() override;
    ~GraphicalDisplay(); // destructor
};

#endif