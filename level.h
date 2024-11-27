#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include "block.h"

class Level
{
protected:
    int level;
    Block *block; // doesnt really make sense

public:
    virtual Block *currentBlock() = 0;
    virtual ~Level() = default;

    int get_level();
    void set_level(int new_level);
    Block *createBlock(char type);
    Level(int level, Block *block);
};

#endif