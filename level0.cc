#import <fstream>;
#include <iostream>
#include <cstdlib>
#include "level.h"
#include "level0.h"
#include "block.h"
#include "command_Interpreter.h" //get the level up/down through it

// steps:
// 1. read file (A-1, B-2), other names that are supplied
// 2. go to the end -> hasn't stop playing ->read the file again

int Level0::get_level()
{
    level = 0;
}

void Level0::read_file(string fileName)
{
}
