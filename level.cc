#include "level.h"
#include <iostream>
#include <memory>
#include <utility>
#include "block.h"
#include "i_block.h"
#include "j_block.h"
#include "l_block.h"
#include "o_block.h"
#include "s_block.h"
#include "t_block.h"
#include "z_block.h"

using namespace std;

Level::Level(int level, int seed = 0) : level{level}, seed{seed}
{
    // cout << "LEVEL CREATED" << endl;
}

int Level::get_seed()
{
    return seed;
}
void Level::set_seed(int newSeed)
{
    seed = newSeed;
    srand(seed);
    // cout << "Seed changed" << level << " " << seed << endl;
}
int Level::get_level()
{
    return level;
}

void Level::set_level(int new_level)
{
    level = new_level;
}

shared_ptr<Block> Level::createBlock(char type, int level)
{

    if (type == 'I')
    {

        shared_ptr<Block> iblock = make_shared<IBlock>(level);
        return iblock;
    }
    else if (type == 'J')
    {
        shared_ptr<Block> jblock = make_shared<JBlock>(level);
        return jblock;
    }
    else if (type == 'L')
    {
        shared_ptr<Block> lblock = make_shared<LBlock>(level);
        return lblock;
    }
    else if (type == 'O')
    {
        shared_ptr<Block> oblock = make_shared<OBlock>(level);
        return oblock;
    }
    else if (type == 'S')
    {
        shared_ptr<Block> sblock = make_shared<SBlock>(level);
        return sblock;
    }
    else if (type == 'T')
    {
        shared_ptr<Block> tblock = make_shared<TBlock>(level);
        return tblock;
    }
    else if (type == 'Z')
    {
        shared_ptr<Block> zblock = make_shared<ZBlock>(level);
        return zblock;
    }
    else
    {
        return shared_ptr<Block>(); // null-ptr
    }
}