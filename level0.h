#ifndef LEVEL0_H
#define LEVEL0_H 
#include <iostream>
#include <cstdlib>
#include "level.h"

class Level0: public Level {
    int level;
    
    public:
    int get_level() override;
    void read_file();
    Level0(int level);

};

#endif