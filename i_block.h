#ifndef IBLOCK_H
#define IBLOCK_H
#include <iostream>
#include <vector>
#include "block.h"
using namespace std;

class IBlock: public Block{
    vector<vector<int>> iblock;
    int num_rot;
    int pos;

    public:
    IBlock(int num_rot, int pos, vector<vector<int>> iblock); 
    virtual vector<vector<int>> get_block();
    virtual vector<vector<int>> find_rotation();
    virtual int get_position();
    virtual void set_position();
};

#endif
