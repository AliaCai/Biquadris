#ifndef LBLOCK_H
#define LBLOCK_H
#include <iostream>
#include <vector>
#include "block.h"
using namespace std;

class LBlock: public Block{
    vector<vector<int>> lblock;
    int num_rot;
    int pos;

    public:
    LBlock(int num_rot, int pos, vector<vector<int>> lblock); 
    virtual vector<vector<int>> get_block();
    virtual vector<vector<int>> find_rotation();
    virtual int get_position();
    virtual void set_position();
};

#endif