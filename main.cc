#include "board.h"
#include "i_block.h"
#include "o_block.h"
#include "l_block.h"
#include "s_block.h"
#include "t_block.h"
#include "z_block.h"
#include "j_block.h"
#include "block.h"
#include "score.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "game.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

// int main() {
//     shared_ptr<Block> iblock = make_shared<JBlock>(0);

//      for (const auto& coordinate : iblock->getPosition()) {
//         // Each 'coordinate' is a vector of size 2: [row, col]
//         int row = coordinate[0];
//         int col = coordinate[1];

//         // Output the row and column values
//         std::cout << row << " " << col << std::endl;
//     }

//     iblock->rotateCounterClockwise();
//     iblock->rotateCounterClockwise();
//     for (const auto& coordinate : iblock->getPosition()) {
//         // Each 'coordinate' is a vector of size 2: [row, col]
//         int row = coordinate[0];
//         int col = coordinate[1];

//         // Output the row and column values
//         std::cout << row << " " << col << std::endl;
//     }

// }

int main(int argc, char *argv[])
{
    // Create the game instance
    Game game{argv[1], argv[2]};

    // Print initial state of the boards
    game.printBoards();

    // Main game loop
    cout << "Starting the game! Player 1 begins." << endl;
    // Display whose turn it is
    cout << "Player " << game.get_turn() << "'s turn." << endl;

    // Allow the player to take their turn
    game.take_turn();

    // Print updated boards
    // game.printBoards();

    // Check for a win condition
    // if (!game.has_won()) {
    //     cout << "Player " << game.get_turn() << " has lost!" << endl;
    //     cout << "Game over!" << endl;
    //     break;
    // }
    return 0;
}

/*
vector<unique_ptr<Block>> blocks;



blocks.push_back(make_unique<IBlock>());
blocks.push_back(make_unique<OBlock>());
blocks.push_back(make_unique<LBlock>());
blocks.push_back(make_unique<SBlock>());
blocks.push_back(make_unique<TBlock>());
blocks.push_back(make_unique<ZBlock>());
blocks.push_back(make_unique<JBlock>());
// Print the initial shape
for (auto it = blocks.begin(); it != blocks.end(); ++it) {
    char type = (*it)->get_type();
    cout << type << endl;

    auto shape = (*it)->getShape();
    for (const auto& row : shape) {
        for (int cell : row) {
            if (cell == 1) cout << type;
            else if (cell == -1) cout << " ";
        }
        cout << endl;
    }


//     cout << endl;



    // Rotate the block and print the new shape
    (*it)->rotateClockwise();
    (*it)->rotateClockwise();
    (*it)->rotateClockwise();
    (*it)->rotateClockwise();
    (*it)->rotateCounterClockwise();
    (*it)->rotateCounterClockwise();
    shape = (*it)->get_curShape();
    std::cout << "After rotation:\n";
    for (const auto& row : shape) {
        for (int cell : row) {
            if (cell == 1) cout << type;
            else if (cell == -1) cout << " ";
        }
        cout << endl;
    }
    cout << endl;
}


return 0;
*/

/*
//score testing
Score s{1, 2};
cout << s.get_score() << " " << s.get_highScore() << endl;
s.resetScore();
cout << s.get_score() << " " << s.get_highScore() << endl;
s.cumulative_s(1, 2, 3, 4);
cout << s.get_score() << " " << s.get_highScore() << endl;
s.resetScore();
cout << s.get_score() << " " << s.get_highScore() << endl;
*/

// level2 testing---------------------------------
// cout << "print" << endl;
/*
unique_ptr<Level> level = make_unique<Level2>();
for (int i = 0; i < 10; i++)
{
unique_ptr<Block> cur_block = level->currentBlock();
level->set_seed(i);
cout << "i:" << i << " seed:" << level->get_seed() << " block:" << cur_block->get_type() << endl;
}
*/
/*
    // level0 testing---------------------------------
    unique_ptr<Level> level = make_unique<Level0>("sequence2.txt", 0);

    for (int i = 0; i < 20; ++i)
    {
        level->set_count(13);
        cout << i % 8 << level->currentBlock()->get_type() << " end" << endl;
    }
*/

/*
//more level0 testing---------------------------------
unique_ptr<Block> cur_block = level->currentBlock();
cout << cur_block->get_type() << " end" << endl;

level->set_count(13);
unique_ptr<Block> next_block1 = level->currentBlock();
cout << next_block1->get_type() << " end" << endl;

level->set_count(15);
unique_ptr<Block> next_block2 = level->currentBlock();
cout << next_block2->get_type() << " end" << endl;*/

// TESTING REACH, DOWN, DROP
/*
  // testing reach, down,drop

    //  dropped blocks
    //  db1
    shared_ptr<Block> jBlock = make_shared<JBlock>(0);

    // b1.set_cb(jBlock);
    // b1.is_drop_valid();
    // info(b1);

    for (int i = 0; i < 14; ++i)
    {
        jBlock->moveDown();
        // b1.is_mD_valid();
        //  b1.is_mR_valid();
        // b1.reach_bottom();
    }
    b1.upd_dropped_blocks(jBlock);
    info(b1);
    // db2
    shared_ptr<Block> iBlock = make_shared<IBlock>(0);

    // b1.set_cb(jBlock);
    // b1.is_drop_valid();
    // info(b1);

    for (int i = 0; i < 13; ++i)
    {
        iBlock->moveDown();
    }
    for (int i = 0; i < 2; ++i)
    {
        iBlock->moveRight();
    }
    b1.upd_dropped_blocks(iBlock);
    info(b1);

    // db3
    shared_ptr<Block> sBlock = make_shared<SBlock>(0);
    sBlock->rotateClockwise();
    for (int i = 0; i < 14; ++i)
    {
        sBlock->moveDown();
    }
    for (int i = 0; i < 7; ++i)
    {
        sBlock->moveRight();
    }
    b1.upd_dropped_blocks(sBlock);
    info(b1);

    b1.is_drop_valid();
    info(b1);

    b1.is_drop_valid();
    info(b1);
    b1.is_drop_valid();
    info(b1);
    for (int i = 0; i < 7; ++i)
    {
        b1.is_mR_valid();
    }

    info(b1);
    for (int i = 0; i < 7; ++i)
    {
        b1.is_mR_valid();
    }
    b1.is_drop_valid();

    info(b1);
    // move down

    cout << "MOVE DOWN-ASDIUHFIASDIFHO" << endl;
    for (int i = 0; i < 9; ++i)
    {
        b1.is_mD_valid();
        info(b1);
    }
    b1.is_drop_valid();
    info(b1);

*/
// testing clear_block_points, clear_blocks
/*
//  dropped blocks
//  db1
shared_ptr<Block> jBlock = make_shared<JBlock>(0);

// b1.set_cb(jBlock);
// b1.is_drop_valid();
// info(b1);

for (int i = 0; i < 14; ++i)
{
    jBlock->moveDown();
    // b1.is_mD_valid();
    //  b1.is_mR_valid();
    // b1.reach_bottom();
}
b1.upd_dropped_blocks(jBlock);

// db2
shared_ptr<Block> iBlock = make_shared<IBlock>(0);

// b1.set_cb(jBlock);
// b1.is_drop_valid();
// info(b1);

for (int i = 0; i < 13; ++i)
{
    iBlock->moveDown();
}
for (int i = 0; i < 2; ++i)
{
    iBlock->moveRight();
}
b1.upd_dropped_blocks(iBlock);

// db3
shared_ptr<Block> sBlock = make_shared<SBlock>(0);
sBlock->rotateClockwise();
for (int i = 0; i < 14; ++i)
{
    sBlock->moveDown();
}
for (int i = 0; i < 7; ++i)
{
    sBlock->moveRight();
}
b1.upd_dropped_blocks(sBlock);

b1.is_drop_valid();

b1.is_drop_valid();

b1.is_drop_valid();

for (int i = 0; i < 7; ++i)
{
    b1.is_mR_valid();
}

for (int i = 0; i < 7; ++i)
{
    b1.is_mR_valid();
}
b1.is_drop_valid();

for (int i = 0; i < 5; ++i)
{
    b1.is_mR_valid();
}
b1.is_drop_valid();

for (int i = 0; i < 6; ++i)
{
    b1.is_mR_valid();
}
b1.is_drop_valid();

info(b1);
for (int i = 0; i < 8; ++i)
{
    b1.clear_block_points(17);
    b1.clear_blocks();
    info(b1);
}
* /
    // clear line
    /*
 for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < count; ++j)
        {

            b1.is_mR_valid();
        }
        b1.is_drop_valid();
        info(b1);
        count += 2;
    }
    b1.is_rotateCW_valid();
    b1.is_drop_valid();
    info(b1);
    b1.restart();
    info(b1);

    b1.is_drop_valid();
    info(b1);
    b1.is_mR_valid();
    b1.is_mR_valid();
    b1.is_mR_valid();
    b1.is_drop_valid();
    info(b1);
         */