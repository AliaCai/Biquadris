#ifndef INTERPRETER_H
#define INTERPRETER_H 
#include "block.h"
#include "board.h"
#include <unordered_map>
#include <iostream>
#include <string>
#include <functional>
using namespace std;

class Interpreter {
    Board* board1;                      // Pointer to the game board
    Block* currentBlock;               // Currently active block
    //int& level;                         // Current game level
    std::string sequenceFile;          // File used for norandom or sequence commands
    size_t sequenceIndex;              // Current index in sequence file
    bool isRandom;                     // Randomness flag for block generation
    std::unordered_map<std::string, std::function<void()>> commandMap; // Command-to-method map

    //Block* nextBlock;                  // Next block to be spawned
    //
    //bool gameOver;                     // Game over status

    // Helper methods
   // void validateMove(const Block& newBlock);

    
    //void clearRows();
    void lockBlock();

    public:
        // Constructor
        Interpreter(Board* b1);

        // Command methods
        //void executeCommand(const string& commandLine);
        void moveLeft();
        void moveRight();
        void moveDown();
        void drop();
        void rotateClockwise();
        void rotateCounterClockwise();
        void levelUp();
        void levelDown();
        void enableRandom();
        void disableRandom(const std::string& sequenceFile);
        void setBlock(const std::string& blockType);
        void executeSequence(const std::string& sequenceFile);
        void restart();
};


#endif