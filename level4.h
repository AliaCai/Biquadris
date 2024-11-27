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
    Block *currentBlock();
    Level4(std::string);
};

#endif