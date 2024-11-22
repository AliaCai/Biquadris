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
    vector<vector<int>> get_block() override;
    vector<vector<int>> find_rotation() override;
    int get_position() override;
    void set_position() override;
};

#endif
