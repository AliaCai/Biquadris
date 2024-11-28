#ifndef LEVEL4_H
#define LEVEL4_H
#include <iostream>
#include <cstdlib>
#include "level.h"
#include "block.h"

class Level4 : public Level
{
    bool nonRandomOn;
    int count;
    string fileName;

public:
    char rand_gen();
    char non_random();
    void random();
    unique_ptr<Block> currentBlock();
    Level4(bool, int, std::string);
};

#endif

// Level *L= &Level4(nonRandomOn, count, fileName);
// currentBlock= std::move (L->currentBlock());
