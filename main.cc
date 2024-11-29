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

void print_b(vector<std::vector<int>> pts)
{
    for (size_t i = 0; i < pts.size(); ++i)
    {
        cout << " pts" << i << ": x: " << pts.at(i).at(0) << " y: " << pts.at(i).at(1) << endl;
    }
    cout << endl;
}

void print_dbs(vector<shared_ptr<Block>> dbs)
{
    for (size_t i = 0; i < dbs.size(); ++i)
    {
        auto db = dbs.at(i)->getPosition();
        int db_cells = dbs.at(i)->get_cells_left();
        cout << " cell_left:" << db_cells << endl;
        print_b(db);

        /*
        for (int j = 0; j < dbs.at(i).size(); < ++j)
        {
            cout << " pts" << i << ": x: " << dbs.at(i).at(j).at(0) << " y: " << pts.at(i).at(j).at(1) << endl;
        }*/
    }
    cout << endl;
}

void printBoard(vector<vector<char>> b1)
{

    const int rows = 18; // Number of rows in the board
    const int cols = 11; // Number of columns in the board

    for (int i = 0; i < rows; ++i)
    {
        // Print Player 1's board row
        for (int j = 0; j < cols; ++j)
        {
            cout << b1.at(i).at(j);
        }

        cout << endl; // Space between Player 1 and Player 2 boards
    }
    cout << "--------------------------" << endl;
}

void info(Board b1)
{

    cout << "Score " << b1.score_num() << endl;
    cout << "high_score " << b1.get_highscore() << endl;

    cout << "level " << b1.get_level_num() << endl;
    cout << "fileName " << b1.get_fileName() << endl;
    cout << "count " << b1.get_count() << endl;
    cout << "current_block: " << b1.get_cB()->get_type() << endl;
    print_b(b1.get_curBlock());
    cout << "next_block: " << b1.get_nB()->get_type() << endl;
    print_b(b1.get_nextBlock());
    cout << "dropped_blocks: " << endl;

    print_dbs(b1.get_dBs());
    b1.upd_board();
    printBoard(b1.getBoard());
}

int main()
{
    cout << "print" << endl;
    Board b1{"sequence1.txt"};
    info(b1);
    b1.is_drop_valid();
    cout << "init--------------------------------------------------------" << endl;
    for (int i = 0; i < 7; ++i)
    {

        b1.is_drop_valid();
        info(b1);
    }

    /*
    b1.clear_block_points(5);
    b1.clear_blocks();
    info(b1);
    b1.clear_block_points(17);
    b1.clear_blocks();
    info(b1);
    b1.clear_block_points(16);
    b1.clear_blocks();
    info(b1);
    b1.clear_block_points(15);
    b1.clear_blocks();
    info(b1);
    b1.clear_block_points(14);
    b1.clear_blocks();
    info(b1);
    b1.clear_block_points(17);
    b1.clear_blocks();
    info(b1);
    b1.clear_block_points(17);
    b1.clear_blocks();
    info(b1);
    b1.clear_block_points(17);
    b1.clear_blocks();
    info(b1);*/

    // move down
    /*
    cout << "MOVE DOWN-ASDIUHFIASDIFHO" << endl;
    for (int i = 0; i < 9; ++i)
    {
        b1.is_mD_valid();
        info(b1);
    }
    b1.is_drop_valid();
    info(b1);

    /*
    //testing mL_valid, mR_valid, rotateCW_valid, rotateCCW_valid
    shared_ptr<Block> jBlock = make_shared<IBlock>(0);
        jBlock->rotateCounterClockwise();
        jBlock->rotateCounterClockwise();
        jBlock->rotateCounterClockwise();
        jBlock->moveRight();
        jBlock->moveRight();
        jBlock->moveRight();
        jBlock->moveRight();
        jBlock->moveRight();
        jBlock->moveRight();
        b1.upd_dropped_blocks(jBlock);
        // b1.set_cb(jBlock);
        b1.upd_board();
        printBoard(b1.getBoard());

        b1.is_mR_valid();
        b1.upd_board();
        printBoard(b1.getBoard());
        b1.is_mR_valid();
        b1.upd_board();
        printBoard(b1.getBoard());
        b1.is_mR_valid();
        b1.upd_board();
        printBoard(b1.getBoard());

        shared_ptr<Block> iBlock = make_shared<IBlock>(0);
        iBlock->rotateClockwise();
        // b1.upd_dropped_blocks(iBlock);
        b1.upd_board();
        printBoard(b1.getBoard());
        b1.is_mL_valid();
        b1.upd_board();
        printBoard(b1.getBoard());
        b1.is_mL_valid();
        b1.upd_board();
        printBoard(b1.getBoard());

        b1.is_rotateCW_valid();
        b1.upd_board();
        printBoard(b1.getBoard());
        b1.is_rotateCW_valid();
        b1.upd_board();
        printBoard(b1.getBoard());

        shared_ptr<Block> sBlock = make_shared<JBlock>(0);
        sBlock->moveRight();
        sBlock->moveRight();
        b1.set_cb(sBlock);
        b1.upd_board();
        printBoard(b1.getBoard());
        b1.is_rotateCW_valid();
        b1.upd_board();
        printBoard(b1.getBoard());
        b1.is_mR_valid();
        b1.upd_board();
        printBoard(b1.getBoard());
        b1.is_mR_valid();
        b1.upd_board();
        printBoard(b1.getBoard());
        b1.is_rotateCW_valid();
        b1.upd_board();
        printBoard(b1.getBoard());
    */

    /*
     jBlock->rotateCounterClockwise();
    b1.set_cb(jBlock);
    b1.upd_board();
    printBoard(b1.getBoard());
    jBlock->rotateClockwise();
    b1.set_cb(jBlock);
    b1.upd_board();
    printBoard(b1.getBoard());
    jBlock->rotateClockwise();
    b1.set_cb(jBlock);
    b1.upd_board();
    printBoard(b1.getBoard());
    jBlock->rotateClockwise();
    b1.set_cb(jBlock);
    b1.upd_board();
    printBoard(b1.getBoard());
*/
    /*
    // vector<vector<int>> nbp = b1.get_nextBlock();

    shared_ptr<Block> nB = b1.get_nB();
    nB->rotateClockwise();
    // nB->moveDown();

    b1.upd_dropped_blocks(nB);
    // b1.upd_dropped_blocks(b1.get_cB());

    b1.upd_board();
    printBoard(b1.getBoard());
    */

    /*
    if (b1.is_block_valid(b1.get_cB()))
    {
        cout << "block valid" << endl;
    }
    else
    {
        cout << "block isn't valid" << endl;
    }
    */

    // restart: working
    /*
    b1.restart();

    cout << "Score " << b1.score_num() << endl;
    cout << "high_score " << b1.get_highscore() << endl;
    cout << "level " << b1.get_level_num() << endl;
    cout << "fileName " << b1.get_fileName() << endl;
    b1.upd_board();
    printBoard(b1.getBoard());
    */

    /*
     for (int i = 0; i < 9; ++i)
     {
         b1.is_mR_valid();
         printBoard(b1.getBoard());
     }*/
}
/*
int main()
{
    // Create the game instance
    Game game;

    // Print initial state of the boards
    game.printBoards();

    // Main game loop
    cout << "Starting the game! Player 1 begins." << endl;
    while (true)
    {
        // Display whose turn it is
        cout << "Player " << game.get_turn() << "'s turn." << endl;

        // Allow the player to take their turn
        game.take_turn();

        // Print updated boards
        game.printBoards();

        // Check for a win condition
        if (!game.has_won())
        {
            cout << "Player " << game.get_turn() << " has lost!" << endl;
            cout << "Game over!" << endl;
            break;
        }
    }

    // Reset the game after it ends (optional)
    game.reset();
    return 0;
}
*/
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