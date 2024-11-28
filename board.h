#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <memory>
#include "block.h"
#include "level.h"
#include "score.h"
#include "game.h"

using namespace std;
class Board
{
    Score score;
    // for levels:
    string fileName;
    int count; // helper fields
    // int nonRandome;
    //-------------------
    std::unique_ptr<Level> level; // change to shared pointer if gen_currBlock does not work;
    std::unique_ptr<Block> cur_block;
    std::unique_ptr<Block> next_block;

    // boards
    std::vector<std::vector<char>> board;
    std::vector<std::unique_ptr<Block>> dropped_blocks;

public:
    // getter
    Score get_score();
    int score_num();
    int get_highscore();

    Level *get_level();
    int get_level_num();
    string get_fileName();
    std::vector<vector<int>> get_curBlock();
    std::vector<vector<int>> get_nextBlock();

    // setter
    void set_fileName(string newFileName);
    void set_seed(int newSeed);
    void set_level();
    void level_up();   // change level field
    void level_down(); // change level field
    void gen_blocks();
    void upd_dropped_blocks(unique_ptr<Block> new_dropped_b); // add
    void upd_board();                                         // according to the dropped_blocks()

    void restart();

    // functions:------------------------
    // 3. level3: heavy; level4:add extra blocks
    //------------maybe these 4 can be combined using templates
    bool is_block_valid(); // true: can have cur_block, false: lose the game

    bool is_mL_valid();
    bool is_mR_valid();
    bool is_rotateCW_valid();
    bool is_rotateCCW_valid();
    //------------------------------------
    void reach_bottom();
    bool is_mD_valid();
    bool is_drop_valid();

    // clears:------------------------------------
    vector<int> clear_line_valid();    // return the indexes of cleared line
    void clear_block_points(int line); // change the point of block after a line is removed
    void clear_blocks();               // upd score ////clear blocks from dropped_blocks
    void clear_lines();                // upd score // //change cordinates of points

    // void update_display(); //I aussumsed it is used to update block
    Board();            // init
    ~Board(); // not sure if needed
};

#endif
