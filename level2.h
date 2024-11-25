#ifndef LEVEL2_H
#define LEVEL2_H
#include <iostream>
#include <cstdlib>
#include "level.h"
#include "block.h"

class Level2 : public Level
{

public:
    int get_level() override;
    Block rand_gen() override; // all blocks have equal probability
    Level2();
};

#endif