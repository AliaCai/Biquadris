
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "level.h"
#include "level3.h"
#include "block.h"

using namespace std;

char Level3::rand_gen()
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

char Level3::non_random()
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
}

void Level3::random()
{
    nonRandomOn = false;
}

Block *Level3::currentBlock()
{
    if (nonRandomOn)
    {
        block = createBlock(non_random());
    }
    else
    {
        block = createBlock(rand_gen());
    }
    return block;
}

Level3::Level3(string fileName = "") : Level{3, nullptr}, nonRandomOn{true}, count{0}, fileName{fileName} {}
