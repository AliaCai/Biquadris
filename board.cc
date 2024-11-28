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
        level = make_unique<Level0>(fileName, count);
    }
    else if (get_level_num() == 1)
    {
        level = make_unique<Level1>();
    }
    else if (get_level_num() == 2)
    {
        level = make_unique<Level2>();
    }
}
void Board::level_up()
{ // 0->1, 1->2
    if (get_level_num() == 0)
    {
        level = make_unique<Level1>();
    }
    else if (get_level_num() == 1)
    {
        level = make_unique<Level2>();
    }
}

void Board::level_down()
{ // 1->0, 2->1
    if (get_level_num() == 1)
    {
        level = make_unique<Level0>(fileName, count);
    }
    else if (get_level_num() == 2)
    {
        level = make_unique<Level1>();
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

void Board::upd_dropped_blocks(unique_ptr<Block> new_dropped_b)
{
    dropped_blocks.emplace_back(std::move(new_dropped_b));
}

void Board::upd_board()
{
    for (auto i = 0; i < dropped_blocks.size(); ++i) // loop through all the dropped block
    {

        vector<vector<int>> d_block = dropped_blocks.at(i)->getPosition();
        char new_type = dropped_blocks.at(i)->get_type();
        for (int j = 0; i < 4; ++i) // loop through all the points of the dropped block
        {

            vector<int> point = d_block.at(j);
            int x = point.at(0);
            int y = point.at(1);

            for (auto a = 0; a < board.size(); ++a)
            {
                vector<char> line = board.at(a);
                for (auto b = 0; b < line.size(); ++b)
                {
                    char old_char = line.at(b);
                    if (a == y && b == x) // the cell equals to the point
                    {
                        board.at(a).at(b) = new_type; // update the character
                    }
                }
            }
        }
    }
}

Board::Board() : board(18, std::vector<char>(11, '.'))
{
    score = Score(0, 0);
    fileName = "";
    count = 0;
    level = make_unique<Level>();
    gen_blocks(); // update cur_block and next_block
}

void Board::restart()
{
    score.resetScore();
    fileName = "";
    count = 0;
    level = make_unique<Level>();
    gen_blocks(); // update cur_block and next_block
    dropped_blocks.clear();
    std::vector<std::vector<char>> new_board(18, std::vector<char>(11, '.'));
    board = new_board;
}

bool Board::is_mL_valid()
{
    vector<vector<int>> pts_forshadow = cur_block->p_after_left();
    for (auto i = 0; i < 4; ++i) // loop through each point
    {

        vector<int> point = pts_forshadow.at(i);

        int x = point.at(0);
        int y = point.at(1);

        for (auto a = 0; a < board.size(); ++a)
        {
            vector<char> line = board.at(a);
            for (auto b = 0; b < line.size(); ++b)
            {
                if (a == y && b == x) // the cell equals to the point
                {
                    return false;
                }
            }
        }
    }

    cur_block->moveLeft(); // the points are not occupied
    return true;
}

bool Board::is_mR_valid()
{
    vector<vector<int>> pts_forshadow = cur_block->p_after_right();
    for (auto i = 0; i < 4; ++i) // loop through each point
    {

        vector<int> point = pts_forshadow.at(i);

        int x = point.at(0);
        int y = point.at(1);

        for (auto a = 0; a < board.size(); ++a)
        {
            vector<char> line = board.at(a);
            for (auto b = 0; b < line.size(); ++b)
            {
                if (a == y && b == x) // the cell equals to the point
                {
                    return false;
                }
            }
        }
    }

    cur_block->moveRight(); // the points are not occupied
    return true;
}

bool Board::is_rotateCW_valid()
{
    vector<vector<int>> pts_forshadow = cur_block->p_after_rotateCW();
    for (auto i = 0; i < 4; ++i) // loop through each point
    {

        vector<int> point = pts_forshadow.at(i);

        int x = point.at(0);
        int y = point.at(1);

        for (auto a = 0; a < board.size(); ++a)
        {
            vector<char> line = board.at(a);
            for (auto b = 0; b < line.size(); ++b)
            {
                if (a == y && b == x) // the cell equals to the point
                {
                    return false;
                }
            }
        }
    }

    cur_block->rotateClockwise(); // the points are not occupied
    return true;
}

bool Board::is_rotateCCW_valid()
{
    vector<vector<int>> pts_forshadow = cur_block->p_after_rotateCCW();
    for (auto i = 0; i < 4; ++i) // loop through each point
    {

        vector<int> point = pts_forshadow.at(i);

        int x = point.at(0);
        int y = point.at(1);

        for (auto a = 0; a < board.size(); ++a)
        {
            vector<char> line = board.at(a);
            for (auto b = 0; b < line.size(); ++b)
            {
                if (a == y && b == x) // the cell equals to the point
                {
                    return false;
                }
            }
        }
    }

    cur_block->rotateCounterClockwise(); // the points are not occupied
    return true;
}