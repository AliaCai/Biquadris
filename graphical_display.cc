#include "graphical_display.h"
#include "window.h"

GraphicalDisplay::GraphicalDisplay(Board* subject, int top, int bottom, int left, int right):
    subject{subject}, top{top}, bottom{bottom}, left{left}, right{right}, w{11*2 + 3, 30} {
        subject->attach(this);
}

GraphicalDisplay::~GraphicalDisplay() {
    subject->detach(this);
}

//notify function
void GraphicalDisplay::notify() {
    
}
