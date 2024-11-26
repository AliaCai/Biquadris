#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include "level.h"
#include "level0.h"
#include "block.h"
// #include "command_Interpreter.h" //get the level up/down through it

// steps:
// 1. read file (A-1, B-2), other names that are supplied
// 2. go to the end -> hasn't stop playing ->read the file again
using namespace std;

char Level0::read_file()
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
Block *Level0::currentBlock()
{
    block = createBlock(read_file());
    return block;
}

Level0::Level0(string fileName = "") : Level{0, nullptr}, fileName{fileName}, count{0}
{
}
