#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include "block.h"
#include "game.h"

class Board {
    int score, level, highscore;
    std::vector<std::vector<char>> board;

    public:
    int get_score();
    int get_level();
    int get_highscore();
    Block get_nextBlock();

    bool is_res_row_empty(std::vector<std::vector<char>> &board); // check if in reserve 3 rows
    bool is_move_valid(vector<vector<int>> *b, char cmd, char type);  // checks if we can do right/left
                                             // cmd = L or R
    bool is_rotation_valid(vector<vector<int>> *b); // checks if rotation can be done



    void update_display();
    void clear_last_line();
    Board(int score, int level, int width, int height, int highscore);
    ~Board(); //not sure if needed

};

#endif
