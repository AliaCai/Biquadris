#include "interpreter.h"
#include "i_block.h"
#include "o_block.h"
#include "l_block.h"
#include "s_block.h"
#include "t_block.h"
#include "z_block.h"
#include "j_block.h"
#include <iostream>
#include <string>
using namespace std;

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
        case Command::I:
            setBlock('I');
            break;
        case Command::J:
            setBlock('J');
            break;
        case Command::L:
            setBlock('L');
            break;
        case Command::T:
            setBlock('T');
            break;
        case Command::S:
            setBlock('S');
            break;
        case Command::Z:
            setBlock('Z');
            break;
        case Command::O:
            setBlock('O');
            break;
        case Command::Restart:
            restart();
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
    // if (board1->is_rotateCW_valid()) {
    //     currentBlock->rotateClockwise();
    // }
   board1->is_rotateCW_valid();
}

void Interpreter::rotateCounterClockwise(){
    //currentBlock->rotateCounterClockwise();
    //board1->is_rotation_valid(&(currentBlock->get_curShape()), currentBlock->get_type());
    board1->is_rotateCCW_valid(); 
}

void Interpreter::setBlock(char type) {
    if (type == 'I') board1->set_cb(make_shared<IBlock>(0));
    if (type == 'J') board1->set_cb(make_shared<JBlock>(0));
    if (type == 'L') board1->set_cb(make_shared<LBlock>(0));
    if (type == 'T') board1->set_cb(make_shared<TBlock>(0));
    if (type == 'S') board1->set_cb(make_shared<SBlock>(0));
    if (type == 'Z') board1->set_cb(make_shared<ZBlock>(0));
    if (type == 'O') board1->set_cb(make_shared<OBlock>(0));

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

