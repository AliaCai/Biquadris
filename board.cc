#include <iostream>
#include <memory>
#include "block.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "score.h"
#include "game.h"

using namespace std;

// getters------------------------------------------------------------
Score Board::get_score()
{
    return score;
}

int Board::score_num()
{
    return score.get_score();
};

int Board::get_highscore()
{
    return score.get_highScore();
}

Level *Board::get_level()
{
    return level.get();
}

int Board::get_level_num()
{
    return level->get_level();
}

string Board::get_fileName()
{
    return fileName;
}

vector<vector<int>> Board::get_curBlock()
{
    return cur_block->getPosition();
}

vector<vector<int>> Board::get_nextBlock()
{
    return next_block->getPosition();
}

vector<vector<char>> Board::getBoard()
{
    return board;
}

char Board::getNextType() {
    return next_block->get_type();
}

// setter------------------------------------------------------------
void Board::set_fileName(string newFileName)
{
    fileName = newFileName;
}

void Board::set_seed(int newSeed)
{
    level->set_seed(newSeed);
}

void Board::set_level()
{
    if (get_level_num() == 0)
    {
        level = make_shared<Level0>(fileName, count);
    }
    else if (get_level_num() == 1)
    {
        level = make_shared<Level1>();
    }
    else if (get_level_num() == 2)
    {
        level = make_shared<Level2>();
    }
}
void Board::level_up()
{ // 0->1, 1->2
    if (get_level_num() == 0)
    {
        level = make_shared<Level1>();
    }
    else if (get_level_num() == 1)
    {
        level = make_shared<Level2>();
    }
}

void Board::level_down()
{ // 1->0, 2->1
    if (get_level_num() == 1)
    {
        level = make_shared<Level0>(fileName, count);
    }
    else if (get_level_num() == 2)
    {
        level = make_shared<Level1>();
    }
}

void Board::gen_blocks() // level 0-2
{
    if (get_level_num() == 0)
    {
        cur_block = level->currentBlock();
        level->set_count(count + 1);
        next_block = level->currentBlock();
        level->set_count(count); // change count back
    }

    else if (get_level_num() == 1)
    {
        cur_block = level->currentBlock();
        next_block = level->currentBlock();
    }
    else if (get_level_num() == 2)
    {
        cur_block = level->currentBlock();
        next_block = level->currentBlock();
    }
}

void Board::upd_dropped_blocks(shared_ptr<Block> new_dropped_b)
{
    dropped_blocks.emplace_back(std::move(new_dropped_b));
}

void Board::upd_board()
{
    std::vector<std::vector<char>> new_board(18, std::vector<char>(11, '.'));
    board = new_board;

    // update drop_blocks
    for (size_t i = 0; i < dropped_blocks.size(); ++i) // loop through all the dropped block
    {

        vector<vector<int>> d_block = dropped_blocks.at(i)->getPosition();
        char new_type = dropped_blocks.at(i)->get_type();
        for (int j = 0; j < 4; ++j) // loop through all the points of the dropped block
        {

            vector<int> point = d_block.at(j);
            size_t x = point.at(0);
            size_t y = point.at(1);

            for (size_t r = 0; r < board.size(); ++r)
            {
                vector<char> line = board.at(r); // 1 row
                for (size_t c = 0; c < line.size(); ++c)
                {
                    // char old_char = line.at(c);
                    if (r == y && c == x) // the cell equals to the point
                    {
                        board.at(r).at(c) = new_type; // update the character
                    }
                }
            }
        }
    }

    // update cur_blocki

    vector<vector<int>> c_block = cur_block->getPosition();
    char new_type = cur_block->get_type();
    for (int j = 0; j < 4; ++j) // loop through all the points of the dropped block
    {

        vector<int> point = c_block.at(j);
        size_t x = point.at(0);
        size_t y = point.at(1);

        for (size_t r = 0; r < board.size(); ++r)
        {
            vector<char> line = board.at(r); // 1 row
            for (size_t c = 0; c < line.size(); ++c)
            {
                if (r == y && c == x) // the cell equals to the point
                {
                    board.at(r).at(c) = new_type; // update the character
                }
            }
        }
    }

    // notifyObservers();
}

void Board::restart()
{
    score.resetScore();
    fileName = "";
    count = 0;
    level = make_shared<Level0>(fileName, count); // Sampoorna changed from Level to Level0
    gen_blocks();                                 // update cur_block and next_block
    if (!is_block_valid())
    {
        cout << "GAME END" << endl;
    }
    dropped_blocks.clear();
    std::vector<std::vector<char>> new_board(18, std::vector<char>(11, '.'));
    board = new_board;
}

//// functions:------------------------------------------------
bool Board::is_block_valid() // game over method
{
    vector<vector<int>> pts_forshadow = cur_block->getPosition();
    for (auto i = 0; i < 4; ++i) // loop through each point
    {

        vector<int> point = pts_forshadow.at(i);

        size_t x = point.at(0);
        size_t y = point.at(1);

        for (size_t a = 0; a < board.size(); ++a)
        {
            vector<char> line = board.at(a);
            for (size_t b = 0; b < line.size(); ++b)
            {
                if (a == y && b == x) // the cell equals to the point //reach bottom
                {
                    return false; // the game end
                }
            }
        }
    }
    upd_board();
    return true;
}
bool Board::is_mL_valid()
{
    vector<vector<int>> pts_forshadow = cur_block->p_after_left();
    for (auto i = 0; i < 4; ++i) // loop through each point
    {

        vector<int> point = pts_forshadow.at(i);

        size_t x = point.at(0);
        size_t y = point.at(1);

        for (size_t a = 0; a < board.size(); ++a)
        {
            vector<char> line = board.at(a);
            for (size_t b = 0; b < line.size(); ++b)
            {
                if (a == y && b == x) // the cell equals to the point
                {
                    return false;
                }
            }
        }
    }

    cur_block->moveLeft(); // the points are not occupied
    // notifyObservers();
    upd_board();
    return true;
}

bool Board::is_mR_valid()
{
    vector<vector<int>> pts_forshadow = cur_block->p_after_right();
    for (auto i = 0; i < 4; ++i) // loop through each point
    {

        vector<int> point = pts_forshadow.at(i);

        size_t x = point.at(0);
        size_t y = point.at(1);

        for (size_t a = 0; a < board.size(); ++a)
        {
            vector<char> line = board.at(a);
            for (size_t b = 0; b < line.size(); ++b)
            {
                if (a == y && b == x) // the cell equals to the point
                {
                    return false;
                }
            }
        }
    }

    cur_block->moveRight(); // the points are not occupied
    // notifyObservers();
    upd_board();
    return true;
}

bool Board::is_rotateCW_valid()
{
    vector<vector<int>> pts_forshadow = cur_block->p_after_rotateCW();
    for (auto i = 0; i < 4; ++i) // loop through each point
    {

        vector<int> point = pts_forshadow.at(i);

        size_t x = point.at(0);
        size_t y = point.at(1);

        for (size_t a = 0; a < board.size(); ++a)
        {
            vector<char> line = board.at(a);
            for (size_t b = 0; b < line.size(); ++b)
            {
                if (a == y && b == x) // the cell equals to the point
                {
                    return false;
                }
            }
        }
    }

    cur_block->rotateClockwise(); // the points are not occupied
    // notifyObservers();
    upd_board();
    return true;
}

bool Board::is_rotateCCW_valid()
{
    vector<vector<int>> pts_forshadow = cur_block->p_after_rotateCCW();
    for (auto i = 0; i < 4; ++i) // loop through each point
    {

        vector<int> point = pts_forshadow.at(i);

        size_t x = point.at(0);
        size_t y = point.at(1);

        for (size_t a = 0; a < board.size(); ++a)
        {
            vector<char> line = board.at(a);
            for (size_t b = 0; b < line.size(); ++b)
            {
                if (a == y && b == x) // the cell equals to the point
                {
                    return false;
                }
            }
        }
    }

    cur_block->rotateCounterClockwise(); // the points are not occupied
                                         // notifyObservers();
    upd_board();

    return true;
}

//------------------------------------------------------------------------------------------------
void Board::reach_bottom()
{
    upd_dropped_blocks(std::move(cur_block));
    upd_board();
    clear_lines();  // score is updated
    clear_blocks(); // score is updated

    count += 1;
    cur_block = std::move(next_block);
    next_block = level->currentBlock();
    if (!is_block_valid())
    {
        cout << "GAME END" << endl;
    }
    upd_board();
}

bool Board::is_mD_valid()
{
    vector<vector<int>> pts_forshadow = cur_block->p_after_down();
    for (auto i = 0; i < 4; ++i) // loop through each point
    {

        vector<int> point = pts_forshadow.at(i);

        size_t x = point.at(0);
        size_t y = point.at(1);

        for (size_t a = 0; a < board.size(); ++a)
        {
            vector<char> line = board.at(a);
            for (size_t b = 0; b < line.size(); ++b)
            {
                if (a == y && b == x) // the cell equals to the point //reach bottom
                {
                    reach_bottom();
                    return false;
                }
            }
        }
    }

    cur_block->moveDown(); // cur_block points is updated
    upd_board();

    return true;
}

bool Board::is_drop_valid()
{
    while (is_mD_valid()) // move down while it is valid
    {
    }
    return true;
}

// clears:------------------------------------------------------------------------
vector<int> Board::clear_line_valid()
{
    vector<int> n_cl;
    for (size_t r = 0; r < board.size(); ++r)
    {
        int num_col = 0;                 // 11
        vector<char> line = board.at(r); // 1 row
        for (size_t c = 0; c < line.size(); ++c)
        {
            char cell = board.at(r).at(c);
            if (cell != '.')
            {
                num_col += 1;
            }
        }
        if (num_col == 11)
        {                         // that row/line is full
            n_cl.emplace_back(r); // row index;
        }
    }

    return n_cl;
}

void Board::clear_block_points(int line)
{
    for (size_t i = 0; i < dropped_blocks.size(); ++i) // loop through all the dropped block
    {

        vector<vector<int>> d_block = dropped_blocks.at(i)->getPosition();
        int d_b_c = dropped_blocks.at(i)->get_cells_left(); // dropped block cells
        for (int j = 0; j < 4; ++j)                         // loop through all the points of the dropped block
        {
            vector<int> point = d_block.at(j);
            // int x = point.at(0);
            int y = point.at(1);

            if (y == line)
            { // same row as cleared row
                point.at(0) = -1;
                point.at(1) = -1;
                dropped_blocks.at(i)->set_cells(d_b_c - 1); // update cells_left of the block
            }
            else if (y > line)
            { // the blocks on the top of cleared down drop down by 1
                point.at(1) = point.at(1) - 1;
            }
        }
    }
}

void Board::clear_blocks()
{
    int n_cb = 0;
    for (auto i = dropped_blocks.begin(); i != dropped_blocks.end();) // loop through all the dropped block
    {

        int num_db_cells = (*i)->get_cells_left();
        if (num_db_cells == 0)
        {
            n_cb += 1;
            i = dropped_blocks.erase(i);                    // erase this point from dropped_blocks
            score.cumulative_s(0, 0, (*i)->get_level(), 1); // update score
        }
        else
        {
            ++i;
        }
    }
}

void Board::clear_lines()
{
    vector<int> cl_l = clear_line_valid();
    int cl_len = 0;
    for (size_t i = 0; i < cl_l.size(); ++i)
    {
        clear_block_points(cl_l.at(i));
        cl_len++;
    }
    score.cumulative_s(get_level_num(), cl_len, 0, 0); // update score
}
//------------------------------------------------------------------------------------------------------------

Board::Board(string fn) : score(0, 0), fileName{fn}, count{0}, level(make_shared<Level0>(fn, 0)), board(18, vector<char>(11, '.'))
{
    gen_blocks(); // Update cur_block and next_block
    // if (!is_block_valid())
    // {
    //     cout << "GAME END" << endl;
    // }
}

Board::~Board() = default;
