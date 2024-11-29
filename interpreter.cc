#include "interpreter.h"
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;


// constructor
Interpreter::Interpreter(Board* b1)
    : board1{b1}, currentBlock{nullptr}, sequenceIndex{0}, isRandom{true} {}

void Interpreter::executeCommand(Command cmd, int multiplier = 1) {
    for (int i = 0; i < multiplier; ++i) {
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
            case Command::Restart:
                restart();
                break;
            default:
                // Handle setting blocks
                break;
        }
    }
}


//std::pair<std::string, int> getCommandAndMultiplier(const std::string& input) {
std::pair<Interpreter::Command, int> Interpreter::MultiplierCommand(const std::string& input) {
    int multiplier = 1;
    size_t i = 0;

    while (i < input.size() && isdigit(input[i])) {
        multiplier = multiplier * 10 + (input[i] - '0');
        ++i;
    }

    std::string commandStr = input.substr(i);
    Command command;

    if (commandStr == "left") {
        command = Command::Left;
    } else if (commandStr == "right") {
        command = Command::Right;
    } else if (commandStr == "down") {
        command = Command::Down;
    } else if (commandStr == "drop") {
        command = Command::Drop;
    } else if (commandStr == "clockwise") {
        command = Command::Clockwise;
    } else if (commandStr == "counterclockwise") {
        command = Command::CounterClockwise;
    } else if (commandStr == "levelup") {
        command = Command::LevelUp;
    } else if (commandStr == "leveldown") {
        command = Command::LevelDown;
    } else if (commandStr == "restart") {
        command = Command::Restart;
    }

    return {command, multiplier};
}

void Interpreter::moveLeft() {
    board1->is_mL_valid();
}

void Interpreter::moveRight() {
    board1->is_mR_valid();
}

void Interpreter::moveDown() {
    board1->is_mD_valid();
}

void Interpreter::rotateClockwise(){
   board1->is_rotateCW_valid();
}

void Interpreter::rotateCounterClockwise(){
    board1->is_rotateCCW_valid(); 
}

void Interpreter::drop() {
    board1->is_drop_valid();
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

