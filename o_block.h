#ifndef OBLOCK_H
#define OBLOCK_H
#include <iostream>
#include <vector>
#include "block.h"
using namespace std;

class OBlock: public Block{
    vector<vector<int>> oblock;
    int num_rot;
    int pos;

    public:
    OBlock(int num_rot, int pos, vector<vector<int>> oblock); 
    virtual vector<vector<int>> get_block();
    virtual vector<vector<int>> find_rotation();
    virtual int get_position();
    virtual void set_position();
};

#endif
