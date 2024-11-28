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
    // for levels:
    string fileName;
    int count;
    int nonRandome;
    //-------------------
    std::unique_ptr<Level> level; // change to shared pointer if gen_currBlock does not work;
    std::unique_ptr<Block> cur_block;
    std::unique_ptr<Block> next_block;
    std::vector<std::vector<char>> board;
    std::vector<std::unique_ptr<Block>> dropped_blocks;

public:
    // getter
    int get_score();
    Level *get_level();
    int get_level_num();
    int get_highscore();
    string get_fileName();
    std::vector<vector<int>> get_curBlock();
    std::vector<vector<int>> get_nextBlock();

    // setter
    void set_fileName(string fileName);
    unique_ptr<Block> gen_curBlock();
    void upd_score();
    void upd_highscore();
    void upd_dropped_blocks();
    void upd_board();

    // functions:
    // 3. level3: heavy; level4:add extra blocks
    bool is_mL_valid();
    bool is_mR_valid();
    bool is_mD_valid(); // check touch bottom-> next
    bool is_drop_valid();
    bool is_rotate_valid();

    void level_up();
    void level_down();

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
