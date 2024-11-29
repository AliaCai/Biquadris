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

void info_level(Board b1)
{

    cout << "level " << b1.get_level_num();
    cout << " r_level " << b1.get_level()->get_level();
    cout << " seed " << b1.get_level()->get_seed();
    // cout << "fileName " << b1.get_fileName() << endl;
    cout << " count " << b1.get_count();

    cout << " *current_block: " << b1.get_cB()->get_type();

    cout << " *next_block: " << b1.get_nB()->get_type();

    b1.upd_board();
    // printBoard(b1.getBoard());
    cout << endl;
}

int main()
{
    cout << "print" << endl;
    Board b1{"sequence1.txt"};
    info_level(b1);
    cout << "init--------------------------------------------------------" << endl;
    b1.is_drop_valid();
    info_level(b1);

    cout << "************************************************************" << endl;

    b1.level_down();
    b1.is_drop_valid();
    info_level(b1);
    cout << "************************************************************" << endl;
    b1.set_seed(9);
    b1.level_up();
    b1.is_drop_valid();
    info_level(b1);

    cout << "************************************************************" << endl;

    b1.level_up();
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info_level(b1);

    cout << "************************************************************" << endl;

    b1.level_down();
    b1.is_drop_valid();
    info_level(b1);

    cout << "************************************************************" << endl;

    b1.level_down();
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info_level(b1);
    cout << "************************************************************" << endl;
    b1.level_down();
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info_level(b1);
    b1.is_drop_valid();
    info(b1);
         */
         