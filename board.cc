#include "board.h"

// ctor
Board::Board(int score, int level, int width, int height, int highscore)
    : score(score), 
    level(level), 
    highscore(highscore),
    board(18, std::vector<char>(11, '.')) {}


// getters
int Board::get_score() {
    return score;
}

int Board::get_level() {
    return level;
}

int Board::get_highscore() {
    return highscore;
}

// NEED TO COMPLETE
Block Board::get_nextBlock() {
    // how are we storing blocks? vectors? 2D or 3D
}

// checks if first three rows empty
bool Board::is_res_row_empty(std::vector<std::vector<char>> &board) {
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 11; ++j) {
            if (board[i][j] == '.') {    // '' = '.' = 0
                continue;
            } else {
                return false;
            }
        }
    }
    return true;
}

// ****************
// QESTION: DO I CALL DROP AND THEN CHECK THESE FNS? 
bool Board::is_move_valid(vector<vector<int>> *b, char cmd, char type) {
    std::vector<std::vector<char>> temp_board = board;

    // adds block b into the tempo_board
    for (int row = 0; row < 18; ++row) {
        for (int col = 0; col < 11; ++col) {
            if (b->at(row).at(col) != '.' || b->at(row).at(col) != ' ') {
                temp_board[row][col] = type; // put block in board
            } else if (b->at(row).at(col) == ' ') {
                temp_board[row][col] = ' ';  // for spaces
            }
        }
    }

    // checks L and R
    // for R
    if (cmd == 'R') {
        for (int row = 0; row < 18; ++row) {
            for (int col = 10; col >= 0; --col) {   // col=10 for last element in each row
                if (temp_board[row][col] != '.'){
                    // check if out of boundary of board or if it already has a block at that cell
                    if (col + 1 > 10 || temp_board[row][col + 1] != 0) {
                        return false;
                    }

                    // if not out of boundary then add block in temp_board
                    temp_board[row][col + 1] = temp_board[row][col];
                    temp_board[row][col] = '.';
                }
            }
        }
    } else if (cmd == 'L') {
        for (int row = 0; row < 18; ++row) {
            for (int col = 0; col <= 10; ++col) {    // start from left
                if (temp_board[row][col] != '.') {
                    // check boundary
                    if(col - 1 < 0 || temp_board[row][col - 1] != '.') {
                        return false;
                    }

                    // if not out of boundary then add block in temp_board
                    temp_board[row][col - 1] = temp_board[row][col];
                    temp_board[row][col] = '.';
                }
            }
        }
    }
    return true;
}


bool Board::is_rotation_valid(vector<vector<int>> *b) {
    std::vector<std::vector<char>> temp_board = board;

    // adds block b into the tempo_board
    for (int row = 0; row < 18; ++row) {
        for (int col = 0; col < 11; ++col) {
            if (b->at(row).at(col) != '.' || b->at(row).at(col) != ' ') {
                temp_board[row][col] = b->get_type(); // put block in board
            } else if (b->at(row).at(col) == ' ') {
                temp_board[row][col] = ' ';  // for spaces
            }
        }
    }
    return is_res_row_empty(temp_board);
}

void Board::update_display() {

}

void Board::clear_last_line() {

}
