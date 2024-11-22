#ifndef ZBLOCK_H
#define ZBLOCK_H
#include <iostream>
#include <vector>
#include "block.h"
using namespace std;

class ZBlock: public Block{
    vector<vector<int>> zblock;
    int num_rot;
    int pos;

    public:
    ZBlock(int num_rot, int pos, vector<vector<int>> zblock); 
    virtual vector<vector<int>> get_block();
    virtual vector<vector<int>> find_rotation();
    virtual int get_position();
    virtual void set_position();
};

#endif
