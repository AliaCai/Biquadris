#ifndef JBLOCK_H
#define JBLOCK_H
#include <iostream>
#include <vector>
#include "block.h"
using namespace std;

class JBlock: public Block{
    vector<vector<int>> jblock;
    int num_rot;
    int pos;

    public:
    JBlock(int num_rot, int pos, vector<vector<int>> jblock); 
    virtual vector<vector<int>> get_block();
    virtual vector<vector<int>> find_rotation();
    virtual int get_position();
    virtual void set_position();
};

#endif
