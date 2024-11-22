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
    vector<vector<int>> get_block() override;
    vector<vector<int>> find_rotation() override;
    int get_position() override;
    void set_position() override;
};

#endif
