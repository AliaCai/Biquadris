#ifndef LEVEL0_H
#define LEVEL0_H
#include <string>
#include <iostream>
#include <cstdlib>
#include "level.h"

class Level0 : public Level
{
    int count;
    string fileName;

public:
    char read_file();
    virtual Block *currentBlock() override;
    Level0(std::string);
};

#endif