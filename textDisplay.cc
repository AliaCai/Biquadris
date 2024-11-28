#include "textDisplay.h"
using namespace std;

TextDisplay::TextDisplay(Board* subject, int top, int bottom, int left, int right): subject{subject}, top{top}, bottom{bottom}, left{left}, right{right} {
    grid = vector<vector<char>>(18, vector<char>(11, ' '));
    subject->attach(this);
}

TextDisplay::~TextDisplay(){
    subject->detach(this);
}

void notify() override {
        // Update the `grid` based on the `subject`'s state
        auto boardState = subject->getState(); // Assuming `Board` provides this method
        for (int r = 0; r < 18; ++r) {
            for (int c = 0; c < 11; ++c) {
                grid[r][c] = boardState[r][c]; // Sync grid with board state
            }
        }
        display(); // Render the display after updates
    }

void display() {
    // Display the game board with the level, score, and next block
    cout << "Level: " << subject->getLevel() << endl; // Assuming `Board` provides `getLevel()`
    cout << "Score: " << subject->getScore() << endl; // Assuming `Board` provides `getScore()`
    cout << "------------" << endl; // Top border of the grid
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            cout << cell;
        }
        cout << endl;
    }

    cout << "------------" << endl; // Bottom border of the grid
    cout << "Next:" << endl;
    auto nextBlock = subject->getNextBlock(); // Assuming `Board` provides `getNextBlock()`
    for (const auto& row : nextBlock) {       // Render the next block
        cout << row << endl;
    }
}