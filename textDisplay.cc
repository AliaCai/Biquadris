#include "textDisplay.h"
#include <iostream>
using namespace std;

TextDisplay::TextDisplay(Board* subject): subject{subject} {
   // grid = vector<vector<char>>(18, vector<char>(11, ' '));
    subject->attach(this);
}

TextDisplay::~TextDisplay(){
    subject->detach(this);
}

// void notify() {
//         // Update the `grid` based on the `subject`'s state
//         auto boardState = subject->getState(); // Assuming `Board` provides this method
//         for (int r = 0; r < 18; ++r) {
//             for (int c = 0; c < 11; ++c) {
//                 grid[r][c] = boardState[r][c]; // Sync grid with board state
//             }
//         }
//         display(); // Render the display after updates
//     }

void TextDisplay::notify() {
    // Display the game board with the level, score, and next block
    cout << "Level: " << (subject->get_level())->get_level() << endl; // Assuming `Board` provides `getLevel()`
    cout << "Score: " << (subject->get_score()).get_score() << endl; // Assuming `Board` provides `getScore()`
    cout << "------------" << endl; // Top border of the grid
    for (const auto& row : subject->getBoard()) {
        for (const auto& cell : row) {
            cout << cell;
        }
        cout << endl;
    }

    cout << "------------" << endl; // Bottom border of the grid
    cout << "Next:" << endl;
    auto nextBlock = subject->get_nextBlock(); // Assuming `Board` provides `getNextBlock()`
    for (const auto& row : nextBlock) {       // Render the next block
        for (const auto& cell : row) {
            cout << cell;
        }
        cout << endl;
    }
}
