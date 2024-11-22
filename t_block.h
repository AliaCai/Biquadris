#ifndef TBLOCK_H
#define TBLOCK_H
#include <iostream>
#include <vector>
#include "block.h"
using namespace std;

class TBlock: public Block{
    vector<vector<int>> tblock;
    int num_rot;
    int pos;

    public:
    TBlock(int num_rot, int pos, vector<vector<int>> tblock); 
    virtual vector<vector<int>> get_block();
    virtual vector<vector<int>> find_rotation();
    virtual int get_position();
    virtual void set_position();
};

#endif