#ifndef ZBLOCK_H
#define ZBLOCK_H
#include <iostream>
#include <vector>
#include "block.h"
using namespace std;

class ZBlock: public Block{
    int num_rot;
    int pos;
    char type;
    vector<vector<vector<int>>> block;

    public:
    ZBlock(); 
    vector<vector<int>> getShape() const override;
    vector<vector<int>> find_rotation(int num_rot) const override;
    int get_position() const override;
    void set_position(int newPos) override;
    char get_type() const override;
};

#endif
