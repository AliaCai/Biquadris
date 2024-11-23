#include "l_block.h"
#include <vector>
using namespace std;

LBlock::LBlock() : num_rot{0}, pos{0}, type{'L'} {
    lblock.push_back({{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 1, 1, 0}}); // original or 360
    lblock.push_back({{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 0, 0}}); // 90 degrees
    lblock.push_back({{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 0}, {1, 0, 0, 0}}); // 180
    lblock.push_back({{0, 0, 0, 0}, {1, 1, 0, 0}, {-1, 1, 0, 0}, {-1, 1, 0, 0}}); // 270
}


vector<vector<int>> LBlock::getShape() const {
    return lblock.at(0);
}

vector<vector<int>> LBlock::find_rotation(int num_rot) const{
    if (num_rot % 4 == 0) return lblock.at(0);
    else if (num_rot % 4 == 1) return lblock.at(1);
    else if (num_rot % 4 == 2) return lblock.at(2);
    else return lblock.at(3); 
}

int LBlock::get_position() const{
    return pos;
}

void LBlock::set_position(int newPos){
    pos = newPos;
}

char LBlock::get_type() const {
    return type;
}