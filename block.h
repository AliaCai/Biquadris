#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>
#include <vector>
using namespace std;

class Block {
    public:
    Block(); 
    virtual vector<vector<int>> get_block() = 0;
    virtual vector<vector<int>> find_rotation() = 0;
    virtual int get_position() = 0;
    virtual void set_position() = 0;
    virtual ~Block() = default;
    
};

#endif