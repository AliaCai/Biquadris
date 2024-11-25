#include "level.h"
#include <iostream>
#include "block.h"

using namespace std;

Level::Level(int level, Block *block) : level{level}, block{block}
{
}

void Level::set_level(int new_level)
{
    level = new_level;
}