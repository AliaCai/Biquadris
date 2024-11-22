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
    vector<vector<int>> get_block() override;
    vector<vector<int>> find_rotation() override;
    int get_position() override;
    void set_position() override;
};

#endif
