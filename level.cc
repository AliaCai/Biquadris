#include "level.h"
#include <iostream>
#include "block.h"

#include "i_block.h"
#include "j_block.h"
#include "l_block.h"
#include "o_block.h"
#include "s_block.h"
#include "t_block.h"
#include "z_block.h"

using namespace std;

Level::Level(int level, Block *block) : level{level}, block{block}
{
}

void Level::set_level(int new_level)
{
    level = new_level;
}

Block *Level::createBlock(char type)
{

    if (type == 'I')
    {
        return new IBlock();
    }
    else if (type == 'J')
    {
        return new JBlock();
    }
    else if (type == 'L')
    {
        return new LBlock();
    }
    else if (type == 'O')
    {
        return new OBlock();
    }
    else if (type == 'S')
    {
        return new SBlock();
    }
    else if (type == 'T')
    {
        return new TBlock();
    }
    else if (type == 'Z')
    {
        return new ZBlock();
    }
    else
    {
        return nullptr;
    }
}