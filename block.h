#ifndef BLOCK_H
#define BLOCK_H

#include <vector>
using namespace std;

class Block {
protected:
    vector<vector<int>> curPosition;  // Current position of the block's cells
    vector<vector<vector<int>>> allRotations;  // Precomputed rotation offsets
    int num_rot;  // Current rotation index (0 to 3)
    char type;  // Block type identifier
    int cells_left;  // Remaining cells (for game logic)

public:
    Block(char type, const vector<vector<int>>& initialPosition, 
          const vector<vector<vector<int>>>& rotations);
    virtual ~Block() = default;

    vector<vector<int>> getPosition() const;
    void rotateClockwise();
    void rotateCounterClockwise();
    char get_type() const;

    void moveLeft();
    void moveRight();
    void moveDown();
};

#endif
