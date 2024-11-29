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

int Board::get_count()
{
    return count;
}

vector<shared_ptr<Block>> Board::get_dBs()
{
    return dropped_blocks;
}
Level *Board::get_level()
{
    return level.get();
}

int Board::get_level_num()
{
    return level->get_level();
}

void Board::set_cb(shared_ptr<Block> cb) // testing
{
    cur_block = cb;
    upd_board();
}
void Board::set_nb(shared_ptr<Block> nb) // testing
{
    next_block = nb;
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

char Board::getNextType()
{
    return next_block->get_type();
}

shared_ptr<Block> Board::get_cB()
{ // Alia
    return cur_block;
}
shared_ptr<Block> Board::get_nB()
{
    return next_block;
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

    // dropped_blocks
    /*
    cout << "START" << endl;
    for (int i = 0; i < dropped_blocks.size(); ++i)
    {
        auto db = dropped_blocks.at(i)->getPosition();
        for (int i = 0; i < db.size(); ++i)
        {
            cout << " pts" << i << ": x: " << db.at(i).at(0) << " y: " << db.at(i).at(1) << endl;
        }
        cout << endl;
    }
    cout << endl;
    cout << "END" << endl;
    */
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
    fileName = fileName; // KEEP FILENAME FOR NOW
    count = 0;
    level = make_shared<Level0>(fileName, count); // Sampoorna changed from Level to Level0
    gen_blocks();                                 // update cur_block and next_block
    dropped_blocks.clear();
    std::vector<std::vector<char>> new_board(18, std::vector<char>(11, '.'));
    board = new_board;
}

//// functions:------------------------------------------------
bool Board::is_block_valid(shared_ptr<Block> block) // game over method
{
    vector<vector<int>> pts_forshadow = block->getPosition();
    // cout << "type" << block->get_type() << endl;
    for (auto i = 0; i < 4; ++i) // loop through each point
    {

        vector<int> point = pts_forshadow.at(i);

        size_t x = point.at(0);
        size_t y = point.at(1);

        if (x >= 11 || y >= 18)
        {

            return false;
        }

        // cout << "pts" << i << ": x " << x << " y: " << y << endl;

        for (size_t b = 0; b < dropped_blocks.size(); ++b) // loop through each block
        {
            vector<vector<int>> block = dropped_blocks.at(b)->getPosition();
            for (size_t p = 0; p < 4; ++p) // loop through each block
            {
                size_t a = block.at(p).at(0);
                size_t b = block.at(p).at(1);
                // cout << "BOARD: " << "pts" << i << ":( x: " << a << ",y:" << b << ")";

                if (a == x && b == y)
                {
                    return false; // is not a valid block
                }
            }
        }
        // cout << endl;
        //<< "1 point checked" << endl;
    }
    upd_board(); // think about it later on
    return true;
}
bool Board::is_mL_valid()
{
    shared_ptr<Block> pts_forshadow = cur_block->p_after_left();
    if (is_block_valid(pts_forshadow))
    {
        cur_block->moveLeft();
        upd_board();
        return true;
    }

    // notifyObservers();
    return false;
}

bool Board::is_mR_valid()
{
    shared_ptr<Block> pts_forshadow = cur_block->p_after_right();
    if (is_block_valid(pts_forshadow))
    {
        cur_block->moveRight();
        upd_board();
        return true;
    }

    // notifyObservers();

    return false;
}

bool Board::is_rotateCW_valid()
{
    shared_ptr<Block> pts_forshadow = cur_block->p_after_rotateCW();
    if (is_block_valid(pts_forshadow))
    {
        cur_block->rotateClockwise();
        upd_board();
        return true;
    }

    // notifyObservers();

    return false;
}

bool Board::is_rotateCCW_valid()
{
    shared_ptr<Block> pts_forshadow = cur_block->p_after_rotateCCW();
    if (is_block_valid(pts_forshadow))
    {
        cur_block->rotateCounterClockwise();
        upd_board();
        return true;
    }

    // notifyObservers();

    return false;
}

//------------------------------------------------------------------------------------------------
void Board::reach_bottom()
{
    // cout << "BOTTOM---------233409258098234905842-5390-" << endl;
    upd_dropped_blocks(cur_block);
    upd_board();
    clear_lines();  // score is updated
    clear_blocks(); // score is updated

    count += 1;
    cur_block = std::move(next_block);
    next_block = level->currentBlock();
    if (!is_block_valid(cur_block))
    {
        // cout << "GAME END" << endl;
        restart();
    }
    upd_board();
}

bool Board::is_mD_valid()
{
    shared_ptr<Block> pts_forshadow = cur_block->p_after_down();

    if (is_block_valid(pts_forshadow))
    {
        cur_block->moveDown();
        upd_board();
        return true;
    }

    // notifyObservers();
    reach_bottom(); //-----TEST
    return false;
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

        vector<vector<int>> &d_block = dropped_blocks.at(i)->getPosition();
        int d_b_c = dropped_blocks.at(i)->get_cells_left(); // dropped block cells
        for (int j = 0; j < 4; ++j)                         // loop through all the points of the dropped block
        {
            vector<int> &point = d_block.at(j);
            int x = point.at(0);
            int y = point.at(1);

            if (y == line)
            { // same row as cleared row
                // cout << "HERE QWIEJQOIJOIJQOERJWOJQWROIE" << endl;
                point.at(0) = -1;
                point.at(1) = -1; // not updated correctly
                // cout << "Y:" << dropped_blocks.at(i)->getPosition().at(j).at(1) << endl;
                dropped_blocks.at(i)->set_cells(); // update cells_left of the block
            }
            else if (y < line && x != -1)
            { // the blocks on the top of cleared down drop down by 1
                point.at(1) = point.at(1) + 1;
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

Board::Board(string fn) : score(0, 0), fileName{fn}, count{0}, level(make_shared<Level0>(fn, 0)), board(18, vector<char>(11, '.')), dropped_blocks{}
{

    gen_blocks(); // Update cur_block and next_block
    upd_board();
}

Board::~Board() = default;
