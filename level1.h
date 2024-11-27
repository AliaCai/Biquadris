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
    Block *currentBlock() override;
    Level1();
};

#endif