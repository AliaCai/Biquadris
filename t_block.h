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
    vector<vector<int>> get_block() override;
    vector<vector<int>> find_rotation() override;
    int get_position() override;
    void set_position() override;
};

#endif
