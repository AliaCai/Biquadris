#ifndef LBLOCK_H
#define LBLOCK_H
#include <iostream>
#include <vector>
#include "block.h"
using namespace std;

class LBlock: public Block{
    int num_rot;
    int pos;
    char type;
    vector<vector<vector<int>>> lblock;
    vector<vector<int>> currentShape;

    public:
    LBlock(); 
   vector<vector<int>> getShape() const override;
    vector<vector<int>> find_rotation(int num_rot) const override;
    int get_position() const override;
    void set_position(int newPos) override;
    char get_type() const override;
    vector<vector<int>> get_curShape() override;
    void rotateClockwise() override;
    void rotateCounterClockwise() override;
};

#endif
