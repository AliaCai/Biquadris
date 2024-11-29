#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <memory>
#include "block.h"
#include "level.h"
#include "score.h"
#include "game.h"
#include "observer.h"
#include "subject.h"

using namespace std;
class Board : public Subject
{
    Score score;
    // for levels:
    string fileName;
    int count; // helper fields
    // int nonRandome;
    //-------------------
    std::shared_ptr<Level> level; // change to shared pointer if gen_currBlock does not work;
    std::shared_ptr<Block> cur_block;
    std::shared_ptr<Block> next_block;

    // boards
    std::vector<std::vector<char>> board;
    std::vector<std::shared_ptr<Block>> dropped_blocks;

public:
    // getter
    Score get_score();
    int score_num();
    int get_highscore();
    int get_count();                               // testing
    std::vector<std::shared_ptr<Block>> get_dBs(); // testing
    vector<vector<char>> getBoard();

    Level *get_level();
    int get_level_num();
    string get_fileName();
    std::vector<vector<int>> get_curBlock();
    shared_ptr<Block> get_cB(); // Alia
    shared_ptr<Block> get_nB(); // Alia
    std::vector<vector<int>> get_nextBlock();
    char getNextType();

    // setter
    // wrok with levels later on---------------------
    void set_cb(shared_ptr<Block> cb); // testing
    void set_nb(shared_ptr<Block> nb); // testing
    void set_fileName(string newFileName);
    void set_seed(int newSeed);
    void set_level();
    void level_up();   // change level field
    void level_down(); // change level field
    //---------------------------------------------------------------
    void gen_blocks();
    void upd_dropped_blocks(shared_ptr<Block> new_dropped_b); // add
    void upd_board();                                         // according to the dropped_blocks()

    void restart();

    // functions:------------------------
    // 3. level3: heavy; level4:add extra blocks
    //------------maybe these 4 can be combined using templates
    bool is_block_valid(shared_ptr<Block> block); // true: can have cur_block, false: lose the game

    bool is_mL_valid();
    bool is_mR_valid();
    bool is_rotateCW_valid();
    bool is_rotateCCW_valid(); // REVIEW TMR
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
    Board(string); // init
    ~Board();      // not sure if needed
};

#endif
