
#include <iostream>
#include <cstdlib>
#include "level.h"
#include "level2.h"
#include "block.h"

using namespace std;

char Level2::rand_gen()
{
    srand(seed);
    seed += 1;

    int num = rand() % 7 + 1;

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
    else if (num == 6)
    {
        return 'S';
    }
    else if (num == 7)
    {
        return 'Z';
    }
}

unique_ptr<Block> Level2::currentBlock()
{
    return createBlock(rand_gen(), 2);
}
Level2::Level2() : Level{2}, seed{0} {};
