#include "i_block.h"
#include <vector>
using namespace std;

IBlock::IBlock() : num_rot{0}, pos{0}, type{'I'} {
    iblock.push_back({{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 1, 1, 1}}); // Horizontal
    iblock.push_back({{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}}); // Vertical
}


vector<vector<int>> IBlock::getShape() const {
    return iblock.at(0);
}

vector<vector<int>> IBlock::find_rotation(int num_rot) const{
    if (num_rot % 2 == 0) return iblock[0];
    else return iblock.at(1);
}

int IBlock::get_position() const{
    return pos;
}

void IBlock::set_position(int newPos){
    pos = newPos;
}

char IBlock::get_type() const {
    return type;
}
