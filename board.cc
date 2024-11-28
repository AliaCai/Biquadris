#include <iostream>
#include <memory>
#include "block.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "score.h"
#include "game.h"

using namespace std;

// getters
int Board::get_score()
{
    return score;
}

int Board::get_highscore()
{
    return get_highscore();
}

Level *Board::get_level()
{
    return level.get(); // why it does not work?
}

int Board::get_level_num()
{
    return level->get_level();
}

vector<vector<int>> Board::get_curBlock()
{
    return cur_block->getPosition();
}

vector<vector<int>> Board::get_nextBlock()
{
    return next_block->getPosition();
}

string Board::get_fileName()
{
    return fileName;
}

// mutator
void Board::set_fileName(string fileName)
{
    fileName = fileName;
}

unique_ptr<Block> Board::gen_curBlock() // need to fix level, curBlock type + fields
{
    if (get_level_num() == 0)
    {
        Level0 L0{fileName, count};
        level = make_unique<Level>(&L0);
    }

    else if (get_level_num() == 1)
    {
        Level1 L1{};
        level = make_unique<Level>(&L1);
    }
    else if (get_level_num() == 2)
    {
        Level2 L2{};
        level = make_unique<Level>(&L2);
    }

    /* girls I am doomed, I am just going to work with lev 0-2 first
    else if (get_level_num() == 3)
    {
        Level3 L3{};
        level = make_unique<Level>(&L3);
    }
    else if (get_level_num() == 4)
    {
        Level4 L4{};
        level = make_unique<Level>(&L4);
    }*/
};
}
;
}
;

void Board::init()
{
    score = 0;
    highscore = 0;
    fileName = "";
    level{0, nullptr};          // edit level fields later on
    cur_block = gen_curBlock(); // cur_block is updated
}
