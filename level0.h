#ifndef LEVEL0_H
#define LEVEL0_H
#include <iostream>
#include <cstdlib>
#include "level.h"

class Level0 : public Level
{

public:
    int get_level() override;
    void read_file(string fileName, string player);
    Level0();
};

#endif