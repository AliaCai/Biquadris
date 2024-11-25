#ifndef LEVEL1_H
#define LEVEL1_H
#include <iostream>
#include <cstdlib>
#include "level.h"
#include "block.h"

class Level1 : public Level
{
    int level;

public:
    int get_level() override;
    char rand_gen() override;
    Level1();
};

#endif