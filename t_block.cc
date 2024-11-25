#include "t_block.h"
#include <vector>
using namespace std;

TBlock::TBlock() : num_rot{0}, pos{0}, type{'T'} {
    tblock.push_back({{0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 0}, {-1, 1, 0, 0}}); // original or 360
    tblock.push_back({{0, 0, 0, 0}, {-1, 1, 0, 0}, {1, 1, 0, 0}, {-1, 1, 0, 0}}); // 90 degrees
    tblock.push_back({{0, 0, 0, 0}, {0, 0, 0, 0}, {-1, 1, 0, 0}, {1, 1, 1, 0}}); // 180
    tblock.push_back({{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 0, 0}, {1, 0, 0, 0}}); // 270
    currentShape = tblock.at(0);
}


vector<vector<int>> TBlock::getShape() const {
    return tblock.at(0);
}

vector<vector<int>> TBlock::find_rotation(int num_rot) const{
    if (num_rot % 4 == 0) return tblock.at(0);
    else if (num_rot % 4 == 1) return tblock.at(1);
    else if (num_rot % 4 == 2) return tblock.at(2);
    else return tblock.at(3); 
}

void TBlock::rotateClockwise() {
    num_rot++;
    currentShape = find_rotation(num_rot);
}

void TBlock::rotateCounterClockwise() {
    num_rot--;
    currentShape = find_rotation(num_rot);
}

vector<vector<int>> TBlock::get_curShape() {
    return currentShape;
}

int TBlock::get_position() const{
    return pos;
}

void TBlock::set_position(int newPos){
    pos = newPos;
}

char TBlock::get_type() const {
    return type;
}