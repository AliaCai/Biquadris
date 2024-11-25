#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include "level.h"
#include "level0.h"
#include "block.h"
#include "command_Interpreter.h" //get the level up/down through it

// steps:
// 1. read file (A-1, B-2), other names that are supplied
// 2. go to the end -> hasn't stop playing ->read the file again
using namespace std;

int Level0::get_level()
{
    return 0;
}

Level0::Level0(string fileName)
{
    level = 0;
    char type;
    ifstream f{fileName};
    int num = 0;
    while (f >> type)
    {
        num += 1;
        if (num == count)
        {
            block = createBlock(type);
            count += 1;
            break;
        }
    }
    count = 0;
    num = 0;
    while (f >> type)
    {
        num += 1;
        if (num == count)
        {
            block = createBlock(type);
            count += 1;
            break;
        }
    }
}
