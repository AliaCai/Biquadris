#include "block.h"

Block::Block(char type, const vector<vector<int>>& initialPosition, 
             const vector<vector<vector<int>>>& rotations)
    : type(type), curPosition(initialPosition), allRotations(rotations), num_rot(0), cells_left(4) {}

vector<vector<int>> Block::getPosition() const {
    return curPosition;
}

void Block::rotateClockwise() {
    int nextRotation = num_rot % 4;  // Get the next rotation index
    vector<vector<int>> toAdd = allRotations.at(nextRotation);
    auto it2 = toAdd.begin();
    for (auto it = curPosition.begin(); it != curPosition.end(); ++it, ++it2) {
        (*it).at(0) += (*it2).at(0);
        (*it).at(1) += (*it2).at(1);
    }
    num_rot++;
}

void Block::rotateCounterClockwise() {
    int prevRotation = num_rot % 4;  // Get the previous rotation index
    vector<vector<int>> toSubtract = allRotations.at(4 - prevRotation); // Undo current rotation
    auto it2 = toSubtract.begin();
    for (auto it = curPosition.begin(); it != curPosition.end(); ++it, ++it2) {
        (*it).at(0) -= (*it2).at(0);
        (*it).at(1) -= (*it2).at(1);
    }
    num_rot--;
}

char Block::get_type() const {
    return type;
}

void Block::moveLeft() {
    for(auto it = curPosition.begin(); it != curPosition.end(); ++it) {
        (*it).at(0)--;
    }
}

void Block::moveRight() {
    for(auto it = curPosition.begin(); it != curPosition.end(); ++it) {
        (*it).at(0)++;
    }
}

void Block::moveDown() {
    for(auto it = curPosition.begin(); it != curPosition.end(); ++it) {
        (*it).at(1)++;
    }
}
