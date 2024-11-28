#ifndef LEVEL2_H
#define LEVEL2_H
#include <iostream>
#include <cstdlib>
#include "level.h"
#include "block.h"

class Level2 : public Level
{

public:
    char rand_gen();
    unique_ptr<Block> currentBlock() override;
    Level2();
};

#endif

// Level *L= &Level2();
// currentBlock= std::move (L->currentBlock());