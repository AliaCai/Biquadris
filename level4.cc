
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "level.h"
#include "level4.h"
#include "block.h"

using namespace std;

char Level4::rand_gen()
{
    int num = rand() % 9 + 1;

    if (num == 1)
    {
        return 'I';
    }
    else if (num == 2)
    {
        return 'O';
    }
    else if (num == 3)
    {
        return 'L';
    }
    else if (num == 4)
    {
        return 'J';
    }
    else if (num == 5)
    {
        return 'T';
    }
    else if (num == 6 || num == 7)
    {
        return 'S';
    }
    else if (num == 8 || num == 9)
    {
        return 'Z';
    }
}

char Level4::non_random()
{
    char type;
    ifstream f{fileName};
    int num = 0;
    while (f >> type)
    {
        num += 1;
        if (num == count)
        {
            count += 1;
            return type;
        }
    }
    count = 0;
    num = 0;
    while (f >> type)
    {
        num += 1;
        if (num == count)
        {

            count += 1;
            return type;
        }
    }
    return '_';
}

void Level4::random()
{
    nonRandomOn = false;
}

unique_ptr<Block> Level4::currentBlock()
{
    if (nonRandomOn)
    {
        return createBlock(non_random(), 4);
    }
    else
    {
        return createBlock(rand_gen(), 4);
    }
}

Level4::Level4(bool nonRandom = true, int count = 0, string fileName = "") : Level{4}, nonRandomOn{nonRandomOn}, count{count}, fileName{fileName} {}
