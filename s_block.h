#ifndef SBLOCK_H
#define SBLOCK_H
#include <iostream>
#include <vector>
#include "block.h"
using namespace std;

class SBlock: public Block{
    vector<vector<int>> sblock;
    int num_rot;
    int pos;

    public:
    SBlock(int num_rot, int pos, vector<vector<int>> sblock); 
    virtual vector<vector<int>> get_block();
    virtual vector<vector<int>> find_rotation();
    virtual int get_position();
    virtual void set_position();
};

#endif