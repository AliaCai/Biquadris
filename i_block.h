#ifndef IBLOCK_H
#define IBLOCK_H
#include <iostream>
#include <vector>
#include "block.h"
using namespace std;

class IBlock: public Block{
    vector<vector<int>> iblock;
    int num_rot;
    int pos;

    public:
    IBlock(int num_rot, int pos, vector<vector<int>> iblock); 
    vector<vector<int>> get_block() override;
    vector<vector<int>> find_rotation() override;
    int get_position() override;
    void set_position() override;
};

#endif
