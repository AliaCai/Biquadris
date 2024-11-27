#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <memory>
#include "block.h"
#include "level.h"
#include "game.h"

class Board
{
    int score, highscore;
    string fileName;
    std::unique_ptr<Level> level;
    std::unique_ptr<Block> cur_block;
    std::vector<std::vector<char>> board;
    std::vector<std::unique_ptr<Block>> dropped_blocks;

public:
    // getter
    int get_score();
    int get_level();
    int get_highscore();
    string get_fileName();
    // std::vector<vector<int>> get_curBlock(); -> works after having the newest branch

    // mutator
    void set_fileName(string fileName);
    unique_ptr<Block> gen_curBlock();
    void upd_score();
    void upd_highscore();
    void upd_dropped_blocks();
    void upd_board();

    // functions:
    // 0. init
    // 2. down, drop;
    // 1. validation: move left valid, move right valid, rotate valid, drop valid

    // 2. score: clear_line, clear_blcoks
    // 3. level3: heavy; level4:add extra blocks
    bool is_mL_valid();
    bool is_mR_valid();
    bool is_mD_valid(); // check touch bottom-> next
    bool is_drop_valid();
    bool is_rotate_valid();

    bool is_block_valid(); // not sure how to check this one ??

    bool clear_line_valid();
    void clear_block_valid();
    void clear_line();
    void clear_block();

    void init();
    void restart();
    void next_round();

    void update_display();
    Board();
    ~Board(); // not sure if needed
};

#endif
