#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include "block.h"

class Level
{
    int level;
    Block *block; // doesnt really make sense

public:
    void set_level(int new_level);
    virtual int get_level() = 0;
    virtual Block rand_gen() = 0; // changed from void to Block
    Level(int level, Block *block);
    virtual ~Level() = default;
};

#endif