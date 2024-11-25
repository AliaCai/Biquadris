#include "interpreter.h"
#include <iostream>
#include <string>
using namespace std;

Interpreter::Interpreter(Board* b1, int& level): board1{b1}, currentBlock{nullptr}, level{level}, sequenceIndex{0}, isRandom{true} {
    commandMap = {
               {"left", moveLeft()},
               {"right", moveRight()},
               {"down", moveDown()},
               {"clockwise", rotateClockwise()},
               {"counterclockwise", rotateCounterClockwise()},
               {"drop", drop()},
               {"levelup", levelUp()},
               {"leveldown", levelDown()},
               {"norandom", Interpreter::norandom},
               {"random", Interpreter::random},
               {"sequence", Interpreter::sequence},
               {"I", currentBlock{make_unique<IBlock>()}},
               {"J", currentBlock{make_unique<JBlock>()}},
               {"L", currentBlock{make_unique<LBlock>()}},
               {"O", currentBlock{make_unique<OBlock>()}},
               {"S", currentBlock{make_unique<SBlock>()}},
               {"T", currentBlock{make_unique<TBlock>()}},
               {"Z", currentBlock{make_unique<ZBlock>()}},
               {"restart", restart()}
    };
}

void Interpreter::moveLeft() {
    b1->is_move_valid(currentBlock, 'L');
}

void Interpreter::moveRight() {
    b1->is_move_valid(currentBlock, 'R');
}

void Interpreter::moveDown() {}

void Interpreter::rotateClockwise(){
    currentBlock->rotateClockwise();
    b1->is_rotation_valid(&(currentBlock->get_curShape()), currentBlock->get_type());
    
}

void Interpreter::rotateCounterClockwise(){
    currentBlock->rotateCounterClockwise();
    b1->is_rotation_valid(&(currentBlock->get_curShape()), currentBlock->get_type());
}

void Interpreter::drop(){}

void Interpreter::levelUp() {
    if (level < 4) level++;
}

void Interpreter::levelDown() {
    if (level > 0) level--;
}

