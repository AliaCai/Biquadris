#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include <memory>
#include "block.h"

class Level
{
protected:
    int level;
    int seed;

public:
    // virtual
    virtual std::shared_ptr<Block> currentBlock() = 0;
    virtual void set_count(int count) = 0;
    virtual void set_fileName(string fileName) = 0;

    // for superclass
    int get_seed();
    void set_seed(int newSeed);
    int get_level();
    void set_level(int new_level);
    std::shared_ptr<Block> createBlock(char type, int level);
    Level(int level, int seed);
    virtual ~Level() = default;
};

#endif
