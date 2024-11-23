#include "z_block.h"
#include <vector>
using namespace std;

ZBlock::ZBlock() : num_rot{0}, pos{0}, type{'Z'} {
    block.push_back({{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 0, 0}, {-1, 1, 1, 0}});
    block.push_back({{0, 0, 0, 0}, {-1, 1, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}});  
    
}

vector<vector<int>> ZBlock::getShape() const {
    return block.at(0);
}

vector<vector<int>> ZBlock::find_rotation(int num_rot) const{
     if (num_rot % 2 == 0) return block[0];
    else return block.at(1);
    
}

int ZBlock::get_position() const{
    return pos;
}

void ZBlock::set_position(int newPos){
    pos = newPos;
}

char ZBlock::get_type() const {
    return type;
}
