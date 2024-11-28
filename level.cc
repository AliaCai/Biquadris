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

Level::Level(int level) : level{level}
{
}

int Level::get_level()
{
    return level;
}

void Level::set_level(int new_level)
{
    level = new_level;
}

unique_ptr<Block> Level::createBlock(char type, int level)
{

    if (type == 'I')
    {

        unique_ptr<Block> iblock = make_unique<IBlock>(level);
        return iblock;
    }
    else if (type == 'J')
    {
        unique_ptr<Block> jblock = make_unique<JBlock>(level);
        return jblock;
    }
    else if (type == 'L')
    {
        unique_ptr<Block> lblock = make_unique<LBlock>(level);
        return lblock;
    }
    else if (type == 'O')
    {
        unique_ptr<Block> oblock = make_unique<OBlock>(level);
        return oblock;
    }
    else if (type == 'S')
    {
        unique_ptr<Block> sblock = make_unique<SBlock>(level);
        return sblock;
    }
    else if (type == 'T')
    {
        unique_ptr<Block> tblock = make_unique<TBlock>(level);
        return tblock;
    }
    else if (type == 'Z')
    {
        unique_ptr<Block> zblock = make_unique<ZBlock>(level);
        return zblock;
    }
    else
    {
        return unique_ptr<Block>(); // null-ptr
    }
}