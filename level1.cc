
#include <iostream>
#include <cstdlib>
#include "level.h"
#include "level1.h"
#include "block.h"

using namespace std;

int Level1::get_level()
{
    return 1;
}

char Level1::rand_gen()
{
    level = 1;
    int num = rand() % 12 + 1;
    // 1,2 (I),3,4(O),5,6(L),7,8(J),9,10(T),11(S),12(Z)
    if (num == 1 || num == 2)
    {
        return 'I';
    }
    else if (num == 3 || num == 4)
    {
        return 'O';
    }
    else if (num == 5 || num == 6)
    {
        return 'L';
    }
    else if (num == 7 || num == 8)
    {
        return 'J';
    }
    else if (num == 9 || num == 10)
    {
        return 'T';
    }
    else if (num == 11)
    {
        return 'S';
    }
    else if (num == 12)
    {
        return 'Z';
    }
}
Level1::Level1()
{
    block = createBlock(rand_gen());
}