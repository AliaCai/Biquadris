#include "interpreter.h"
#include <iostream>
#include <string>
using namespace std;

/*
Interpreter::Interpreter(Board* b1): board1{b1}, currentBlock{nullptr}, sequenceIndex{0}, isRandom{true} {
    commandMap = {
               {"left", moveLeft()},
               {"right", moveRight()},
               {"down", moveDown()},        //
               {"clockwise", rotateClockwise()},
               {"counterclockwise", rotateCounterClockwise()},
               {"drop", drop()},        //
               {"levelup", levelUp()},
               {"leveldown", levelDown()},
               {"norandom", Interpreter::norandom},     //
               {"random", Interpreter::random},         //
               {"sequence", Interpreter::sequence},
               {"I", currentBlock{make_unique<IBlock>()}},
               {"J", currentBlock{make_unique<JBlock>()}},
               {"L", currentBlock{make_unique<LBlock>()}},
               {"O", currentBlock{make_unique<OBlock>()}},
               {"S", currentBlock{make_unique<SBlock>()}},
               {"T", currentBlock{make_unique<TBlock>()}},
               {"Z", currentBlock{make_unique<ZBlock>()}},
               {"restart", restart()}                           //
    };
}
*/

// constructor
Interpreter::Interpreter(Board* b1)
    : board1{b1}, currentBlock{nullptr}, sequenceIndex{0}, isRandom{true} {}

void Interpreter::executeCommand(Command cmd) {
    switch (cmd) {
        case Command::Left:
            moveLeft();
            break;
        case Command::Right:
            moveRight();
            break;
        case Command::Down:
            moveDown();
            break;
        case Command::Clockwise:
            rotateClockwise();
            break;
        case Command::CounterClockwise:
            rotateCounterClockwise();
            break;
        case Command::Drop:
            drop();
            break;
        case Command::LevelUp:
            levelUp();
            break;
        case Command::LevelDown:
            levelDown();
            break;
        case Command::NoRandom:
            disableRandom(sequenceFile);
            break;
        case Command::Random:
            enableRandom();
            break;
        //case Command::Sequence:
            // Add sequence handling logic here
        //    break;
        case Command::Restart:
            restart();
            break;
        default:
            // Handle setting blocks
            break;
    }
}


void Interpreter::moveLeft() {
    //board1->is_mL_valid(currentBlock, 'L');
    board1->is_mL_valid();
}

void Interpreter::moveRight() {
    //board1->is_move_valid(currentBlock, 'R');
    board1->is_mR_valid();
}

void Interpreter::moveDown() {
    //board1->is_move_valid(currentBlock, 'D');   // need to add down fn in board.cc
    board1->is_mD_valid();
}

void Interpreter::rotateClockwise(){
    //currentBlock->rotateClockwise();
    //board1->is_rotation_valid(&(currentBlock->get_curShape()), currentBlock->get_type());
    if (board1->is_rotateCW_valid()) {
        currentBlock->rotateClockwise();
    }
}

void Interpreter::rotateCounterClockwise(){
    //currentBlock->rotateCounterClockwise();
    //board1->is_rotation_valid(&(currentBlock->get_curShape()), currentBlock->get_type());
    if (board1->is_rotateCCW_valid()) {
        currentBlock->rotateCounterClockwise();
    }
}

void Interpreter::drop() {
    //while (board1->is_mD_valid()) {
    //    currentBlock->moveDown();
    //}
    //board1->drop();
    board1->is_drop_valid();
    //board1->update_display();        // check impl
}

void Interpreter::levelUp() {
    board1->level_up();
}

void Interpreter::levelDown() {
    board1->level_down();
}

void Interpreter::enableRandom() {
    isRandom = true;
}

void Interpreter::disableRandom(const std::string& sequenceFile) {
    isRandom = false;
    this->sequenceFile = sequenceFile;
    sequenceIndex = 0;
}


void Interpreter::restart() {
    board1->restart();
    currentBlock = nullptr;
    isRandom = true;
    sequenceIndex = 0;
}

