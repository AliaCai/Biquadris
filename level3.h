#ifndef LEVEL3_H
#define LEVEL3_H 
#include <iostream>
#include <cstdlib>
#include "level.h"
#include "block.h"

class Level3: public Level {
    int level;

    public:
    int get_level() override;
    Block rand_gen() override;
    void heavy();
    Level3(int level);

};

#endif