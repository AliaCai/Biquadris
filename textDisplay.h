#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include "observer.h"
#include "board.h"
#include <iostream>

class TextDisplay: public Observer {
    Board* subject;
    int top, bottom, left, right;

    public:
    TextDisplay(Board* subject, int top, int bottom, int left, int right); // constructor
    void notify() override;
    ~TextDisplay(); // destructor
};

#endif