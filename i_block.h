#ifndef IBLOCK_H
#define IBLOCK_H
#include <iostream>
#include <vector>
#include "block.h"
using namespace std;

class IBlock: public Block{

    public:
    IBlock(int level); 
};

#endif
