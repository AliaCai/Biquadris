#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
#include <memory>
using namespace std;

class Block
{
protected:
    char type;                                // Block type identifier
    vector<vector<int>> curPosition;          // Current position of the block's cells
    vector<vector<vector<int>>> allRotations; // Precomputed rotation offsets
    int num_rot;                              // Current rotation index (0 to 3)
    int cells_left;                           // Remaining cells (for game logic)
    int level;

public:
    Block(char type, const vector<vector<int>> &initialPosition,
          const vector<vector<vector<int>>> &rotations, int level);
    virtual ~Block() = default;
    Block(const Block &other);

    vector<vector<int>> getPosition() const;

    void rotateClockwise();
    void rotateCounterClockwise();
    char get_type() const;
    int get_cells_left();          // Alia adds this
    int get_level();               // Alia adds this //make it virtual?
    void set_cells(int num_cells); // Alia adds this

    void moveLeft();
    void moveRight();
    void moveDown();

    shared_ptr<Block> p_after_left() const;
    shared_ptr<Block> p_after_right() const;
    shared_ptr<Block> p_after_down() const;
    shared_ptr<Block> p_after_rotateCW() const;
    shared_ptr<Block> p_after_rotateCCW() const;
};

#endif
