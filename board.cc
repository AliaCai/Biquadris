#include <iostream>
#include <memory>
#include "block.h"
#include "level.h"  //fils
#include "level0.h" //fils
#include "level1.h" //fils
#include "level2.h" //fils
#include "level3.h" //fils
#include "level4.h" //fils
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

int Board::get_level()
{
    return level->get_level();
}

vector<vector<int>> Board::get_curBlock()
{
    return cur_block->getPosition();
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
    if (get_level() == 0)
    {
        Level0 l0 = new Level0{fileName};
        level = &L0;
    }
    else if (get_level() == 1)
    {
        Level1 L1{1, nullptr};
        level = &L1;
    }
    else if (get_level() == 2)
    {
        Level1 L2{2, nullptr, fileName};
        level = &L2;
    }
    else if (get_level() == 3)
    {
        Level1 L3{3, nullptr, fileName};
        level = &L3;
    }
    else if (get_level() == 4)
    {
        Level1 L4{4, nullptr, fileName};
        level = &L4;
    }
    return level.currentBlock();
};

void Board::init()
{
    score = 0;
    highscore = 0;
    fileName = "";
    level{0, nullptr};          // edit level fields later on
    cur_block = gen_curBlock(); // cur_block is updated
}
