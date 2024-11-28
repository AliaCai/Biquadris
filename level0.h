#ifndef LEVEL0_H
#define LEVEL0_H
#include <string>
#include <iostream>
#include <cstdlib>
#include "level.h"

class Level0 : public Level
{
    int count;
    string fileName;

public:
    int get_count();
    string get_fileName();
    void set_count(int count) override;
    void set_fileName(string fileName) override;

    char read_file();
    virtual unique_ptr<Block> currentBlock() override;
    Level0(std::string, int);
};

#endif

// Level *L= &Level0(fileName, count);
// currentBlock= std::move (L->currentBlock());
