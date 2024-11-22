#ifndef LEVEL4_H
#define LEVEL4_H 
#include <iostream>
#include <cstdlib>
#include "level.h"
#include "block.h"

class Level4: public Level {
    int level;

    public:
    int get_level() override;
    Block rand_gen() override;
    void drop_div();
    Level4(int level);

};

#endif