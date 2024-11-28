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

int Level0::get_count()
{
    return count;
}

string Level0::get_fileName()
{
    return fileName;
}

void Level0::set_count(int count)
{
    count = count;
}

void Level0::set_fileName(string fileName)
{
    fileName = fileName;
}

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

unique_ptr<Block> Level0::currentBlock()
{
    return createBlock(read_file(), 0);
}

Level0::Level0(string fileName = "", int count = 0) : Level{0}, fileName{fileName}, count{count}
{
}
