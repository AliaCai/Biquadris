#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
#include <vector>
using namespace std;

class Block {
    public:
    virtual vector<vector<int>> getShape() const = 0;
    virtual vector<vector<int>> find_rotation(int num_rot) const = 0;
    virtual int get_position() const = 0;
    virtual char get_type() const = 0;
    virtual void rotateClockwise() = 0;
    virtual void rotateCounterClockwise() = 0;
    virtual void set_position(int newPos) = 0;
    virtual vector<vector<int>> get_curShape() = 0;
    virtual ~Block() = default;

};

#endif
