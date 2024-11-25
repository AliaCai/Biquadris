
#include <iostream>
#include <cstdlib>
#include "level.h"
#include "level2.h"
#include "block.h"

using namespace std;

int Level2::get_level()
{
    return 2;
}

char Leve2::rand_gen()
{
    level = 2;
    int num = rand() % 7;

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
Level2::Level2()
{
    block = createBlock(rand_gen());
}