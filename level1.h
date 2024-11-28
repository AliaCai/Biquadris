#ifndef LEVEL1_H
#define LEVEL1_H
#include <iostream>
#include <cstdlib>
#include "level.h"
#include "block.h"

class Level1 : public Level
{

public:
    char rand_gen();
    unique_ptr<Block> currentBlock() override;
    Level1();
};

#endif

// Level *L= &Level1();
// currentBlock= std::move (L->currentBlock());