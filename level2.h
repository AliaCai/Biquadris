#ifndef LEVEL2_H
#define LEVEL2_H
#include <iostream>
#include <cstdlib>
#include "level.h"
#include "block.h"

class Level2 : public Level
{

public:
    char rand_gen(); // all blocks have equal probability
    Block *currentBlock() override;
    Level2();
};

#endif