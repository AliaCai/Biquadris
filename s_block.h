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
    vvector<vector<int>> get_block() override;
    vector<vector<int>> find_rotation() override;
    int get_position() override;
    void set_position() override;
};

#endif
