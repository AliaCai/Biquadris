#ifndef LEVEL3_H
#define LEVEL3_H
#include <iostream>
#include <cstdlib>
#include "level.h"
#include "block.h"

class Level3 : public Level
{
    bool nonRandomOn;
    int count;
    string fileName;
    // maybe seed;

public:
    char rand_gen();
    char non_random();
    void random();
    shared_ptr<Block> currentBlock();
    Level3(bool, int, std::string);
};

#endif

