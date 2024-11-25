#ifndef LEVEL0_H
#define LEVEL0_H
#include <string>
#include <iostream>
#include <cstdlib>
#include "level.h"

class Level0 : public Level
{
    int count;

public:
    int get_level() override;
    Level0(std::string);
};

#endif