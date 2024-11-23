#ifndef IBLOCK_H
#define IBLOCK_H
#include <iostream>
#include <vector>
#include "block.h"
using namespace std;

class IBlock: public Block{
    
    int num_rot;
    int pos;
    vector<vector<vector<int>>> iblock;

    public:
    IBlock(); 
    vector<vector<int>> getShape() const override;
    vector<vector<int>> find_rotation(int num_rot) const override;
    int get_position() const override;
    void set_position(int newPos) override;
};

#endif
