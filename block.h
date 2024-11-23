#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
#include <vector>
using namespace std;

class Block {
    protected:
    int num_rot;                          // Current rotation index
    int pos;                              // Position on the board
    vector<vector<vector<int>>> shape;  // Current shape of the block

    public:
    // // Rotate the block clockwise
    // virtual void rotateClockwise() = 0;

    // // Rotate the block counterclockwise
    // virtual void rotateCounterclockwise() = 0;
    virtual vector<vector<int>> getShape() const = 0;
    virtual vector<vector<int>> find_rotation(int num_rot) const = 0;
    virtual int get_position() const = 0;
    virtual void set_position(int newPos) = 0;
    virtual ~Block() = default;

};

#endif
