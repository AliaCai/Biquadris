#include "j_block.h"
#include <vector>
using namespace std;

JBlock::JBlock() : num_rot{0}, pos{0}, type{'J'} {
    block.push_back({{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 1, 0}}); // original or 360
    block.push_back({{0, 0, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}}); // 90 degrees
    block.push_back({{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 0}, {-1, -1, 1, 0}}); // 180
    block.push_back({{0, 0, 0, 0}, {-1, 1, 0, 0}, {-1, 1, 0, 0}, {1, 1, 0, 0}}); // 270
}


vector<vector<int>> JBlock::getShape() const {
    return block.at(0);
}

vector<vector<int>> JBlock::find_rotation(int num_rot) const{
    if (num_rot % 4 == 0) return block.at(0);
    else if (num_rot % 4 == 1) return block.at(1);
    else if (num_rot % 4 == 2) return block.at(2);
    else return block.at(3); 
}

int JBlock::get_position() const{
    return pos;
}

void JBlock::set_position(int newPos){
    pos = newPos;
}

char JBlock::get_type() const {
    return type;
}