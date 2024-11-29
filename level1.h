#ifndef LEVEL1_H
#define LEVEL1_H
#include <iostream>
#include <cstdlib>
#include "level.h"
#include "block.h"

class Level1 : public Level
{

public:
    void set_count(int count) override;          // will not be used
    void set_fileName(string fileName) override; // will not be used
    char rand_gen();
    shared_ptr<Block> currentBlock() override;
    Level1();
};

#endif

// Level *L= &Level1();
// currentBlock= std::move (L->currentBlock());