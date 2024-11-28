#ifndef SBLOCK_H
#define SBLOCK_H
#include <iostream>
#include <vector>
#include "block.h"
using namespace std;

class SBlock: public Block{
    public:
    SBlock(int level); 
};

#endif
