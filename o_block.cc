#include "o_block.h"
#include <vector>
using namespace std;

OBlock::OBlock() : num_rot{0}, pos{0}, type{'O'} {
    oblock.push_back({{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 1}, {0, 0, 1, 1}}); //only one representation
    currentShape = oblock.at(0);
    
}

vector<vector<int>> OBlock::getShape() const {
    return oblock.at(0);
}

vector<vector<int>> OBlock::find_rotation(int num_rot) const{
    return oblock[0];
    
}

void OBlock::rotateClockwise() {
    num_rot++;
    currentShape = find_rotation(num_rot);
}

void OBlock::rotateCounterClockwise() {
    num_rot--;
    currentShape = find_rotation(num_rot);
}

vector<vector<int>> OBlock::get_curShape() {
    return currentShape;
}

int OBlock::get_position() const{
    return pos;
}

void OBlock::set_position(int newPos){
    pos = newPos;
}

char OBlock::get_type() const {
    return type;
}
