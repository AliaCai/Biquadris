#include "s_block.h"
#include <vector>
using namespace std;

SBlock::SBlock() : num_rot{0}, pos{0}, type{'S'} {
    sblock.push_back({{0, 0, 0, 0}, {0, 0, 0, 0}, {-1, 1, 1, 0}, {1, 1, 0, 0}});
    sblock.push_back({{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 0, 0}, {-1, 1, 0, 0}});  
    currentShape = sblock.at(0);
    
}

vector<vector<int>> SBlock::getShape() const {
    return sblock.at(0);
}

vector<vector<int>> SBlock::find_rotation(int num_rot) const{
     if (num_rot % 2 == 0) return sblock[0];
    else return sblock.at(1);
    
}

void SBlock::rotateClockwise() {
    num_rot++;
    currentShape = find_rotation(num_rot);
}

void SBlock::rotateCounterClockwise() {
    num_rot--;
    currentShape = find_rotation(num_rot);
}

vector<vector<int>> SBlock::get_curShape() {
    return currentShape;
}

int SBlock::get_position() const{
    return pos;
}

void SBlock::set_position(int newPos){
    pos = newPos;
}

char SBlock::get_type() const {
    return type;
}
