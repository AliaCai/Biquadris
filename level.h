#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include <memory>
#include "block.h"

class Level
{
protected:
    int level;

public:
    // virtual
    virtual std::unique_ptr<Block> currentBlock() = 0;

    // for superclass
    int get_level();
    void set_level(int new_level);
    std::unique_ptr<Block> createBlock(char type, int level);
    Level(int level);
    virtual ~Level() = default;
};

#endif