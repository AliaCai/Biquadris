#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include "block.h"
#include "game.h"

class Board
{
    int score, level, width, height, highscore;

public:
    int get_score();
    int get_level();
    int get_highscore();
    Block get_nextBlock();
    int get_width();
    int get_height();
    bool is_block_valid();
    void update_display();
    void clear_last_line();
    Board(int score, int level, int width, int height, int highscore);
    ~Board(); // not sure if needed
};

#endif
