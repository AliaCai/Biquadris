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
    vector<vector<int>> get_block() override;
    vector<vector<int>> find_rotation() override;
    int get_position() override;
    void set_position() override;
};

#endif
