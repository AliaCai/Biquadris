#include "block.h"
#include <memory>

Block::Block(char type, const vector<vector<int>> &initialPosition,
             const vector<vector<vector<int>>> &rotations, int level)
    : type(type), curPosition(initialPosition), allRotations(rotations), num_rot(0), cells_left(4), level{level} {}

vector<vector<int>> &Block::getPosition() // Alia adds it, for reference to change point
{
    return curPosition;
}

vector<vector<int>> Block::getPosition() const
{
    return curPosition;
}

Block::Block(const Block &other) : type{other.type}, curPosition{other.curPosition}, allRotations{other.allRotations},
                                   num_rot{other.num_rot}, cells_left{other.cells_left} {}

void Block::rotateClockwise()
{
    int nextRotation = num_rot % 4; // Get the next rotation index
    vector<vector<int>> toAdd = allRotations.at(nextRotation);
    auto it2 = toAdd.begin();
    for (auto it = curPosition.begin(); it != curPosition.end(); ++it, ++it2)
    {
        (*it).at(0) += (*it2).at(0);
        (*it).at(1) += (*it2).at(1);
    }
    num_rot++;
}

void Block::rotateCounterClockwise()
{
    int prevRotation = num_rot % 4;                                     // Get the previous rotation index
    vector<vector<int>> toSubtract = allRotations.at(3 - prevRotation); // Undo current rotation
    auto it2 = toSubtract.begin();
    for (auto it = curPosition.begin(); it != curPosition.end(); ++it, ++it2)
    {
        (*it).at(0) -= (*it2).at(0);
        (*it).at(1) -= (*it2).at(1);
    }
    num_rot++;
}

char Block::get_type() const
{
    return type;
}

int Block::get_cells_left() // Alia adds this
{
    return cells_left;
}

int Block::get_level() // Alia adds this
{
    return level;
}

void Block::set_cells() // Alia adds this
{
    cells_left = cells_left - 1;
}

void Block::moveLeft()
{
    for (auto it = curPosition.begin(); it != curPosition.end(); ++it)
    {
        (*it).at(0)--;
    }
}

void Block::moveRight()
{
    for (auto it = curPosition.begin(); it != curPosition.end(); ++it)
    {
        (*it).at(0)++;
    }
}

void Block::moveDown()
{
    for (auto it = curPosition.begin(); it != curPosition.end(); ++it)
    {
        (*it).at(1)++;
    }
}

shared_ptr<Block> Block::p_after_left() const
{
    vector<vector<int>> tempBlock = curPosition;
    for (auto it = tempBlock.begin(); it != tempBlock.end(); ++it)
    {
        (*it).at(0)--;
    }

    shared_ptr<Block> tBlock = make_shared<Block>(type, tempBlock, allRotations, level);

    return tBlock;
}

shared_ptr<Block> Block::p_after_right() const
{
    vector<vector<int>> tempBlock = curPosition;
    for (auto it = tempBlock.begin(); it != tempBlock.end(); ++it)
    {
        (*it).at(0)++;
    }

    shared_ptr<Block> tBlock = make_shared<Block>(type, tempBlock, allRotations, level);

    return tBlock;
}

shared_ptr<Block> Block::p_after_down() const
{
    vector<vector<int>> tempBlock = curPosition;
    for (auto it = tempBlock.begin(); it != tempBlock.end(); ++it)
    {
        (*it).at(1)++;
    }
    shared_ptr<Block> tBlock = make_shared<Block>(type, tempBlock, allRotations, level);

    return tBlock;
}
shared_ptr<Block> Block::p_after_rotateCW() const
{
    vector<vector<int>> tempBlock = curPosition;
    int nextRotation = num_rot % 4; // Get the next rotation index
    vector<vector<int>> toAdd = allRotations.at(nextRotation);
    auto it2 = toAdd.begin();
    for (auto it = tempBlock.begin(); it != tempBlock.end(); ++it, ++it2)
    {
        (*it).at(0) += (*it2).at(0);
        (*it).at(1) += (*it2).at(1);
    }

    shared_ptr<Block> tBlock = make_shared<Block>(type, tempBlock, allRotations, level);

    return tBlock;
}

shared_ptr<Block> Block::p_after_rotateCCW() const
{
    vector<vector<int>> tempBlock = curPosition;
    int nextRotation = num_rot % 4; // Get the next rotation index
    vector<vector<int>> toAdd = allRotations.at(3 - nextRotation);
    auto it2 = toAdd.begin();
    for (auto it = tempBlock.begin(); it != tempBlock.end(); ++it, ++it2)
    {
        (*it).at(0) -= (*it2).at(0);
        (*it).at(1) -= (*it2).at(1);
    }

    shared_ptr<Block> tBlock = make_shared<Block>(type, tempBlock, allRotations, level);

    return tBlock;
}
