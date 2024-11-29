#ifndef LEVEL2_H
#define LEVEL2_H
#include <iostream>
#include <cstdlib>
#include "level.h"
#include "block.h"

class Level2 : public Level
{

public:
    void set_count(int count) override;          // will not be used
    void set_fileName(string fileName) override; // will not be used
    char rand_gen();
    shared_ptr<Block> currentBlock() override;
    Level2();
};

#endif

