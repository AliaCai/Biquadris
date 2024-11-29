#include "graphical_display.h"
#include "window.h"
using namespace std;

GraphicalDisplay::GraphicalDisplay(vector<shared_ptr<Board>> subject2):
    subject{std::move(subject2)}, w{(11 * 2 + 4) * 20, (18 + 8) * 20} {
       // subject->attach(this);
        
}

GraphicalDisplay::~GraphicalDisplay() {
    //subject->detach(this);
}

void GraphicalDisplay::notify() {
    // Retrieve the boards for Player 1 and Player 2
    vector<vector<char>> p1b = subject.at(0)->getBoard(); // Player 1's board
    vector<vector<char>> p2b = subject.at(1)->getBoard(); // Player 2's board

    const int rows = 18; // Number of rows in the board
    const int cols = 11; // Number of columns in the board

    // Print levels
    w.drawString(0, 0, "Level: " + std::to_string(subject.at(0)->get_level()->get_level())); // Player 1 Level
    w.drawString(0, 20, "Level: " + std::to_string(subject.at(1)->get_level()->get_level())); // Player 2 Level

    // Print scores
    w.drawString(1, 0, "Score: " + std::to_string(subject.at(0)->get_score().get_score())); // Player 1 Score
    w.drawString(1, 20, "Score: " + std::to_string(subject.at(1)->get_score().get_score())); // Player 2 Score

    // Draw the boards row by row
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // Draw Player 1's board
            char c1 = p1b.at(i).at(j);
            w.fillRectangle(j * 20, (i + 2) * 20, 20, 20, getColor(c1)); // Adjust position and size

            // Draw Player 2's board
            char c2 = p2b.at(i).at(j);
            w.fillRectangle((j + cols + 2) * 20, (i + 2) * 20, 20, 20, getColor(c2)); // Adjust for offset
        }
    }

    // Draw "Next" blocks
    char next1 = subject.at(0)->getNextType(); // Player 1
    char next2 = subject.at(1)->getNextType(); // Player 2

    vector<vector<char>> nextBlock1 = blockGrid(next1);
    vector<vector<char>> nextBlock2 = blockGrid(next2);

    w.drawString(rows + 2, 0, "Next:");
    w.drawString(rows + 2, 20, "Next:");

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            // Player 1 Next
            w.fillRectangle(j * 20, (rows + 3 + i) * 20, 20, 20, getColor(nextBlock1[i][j]));

            // Player 2 Next
            w.fillRectangle((j + cols + 2) * 20, (rows + 3 + i) * 20, 20, 20, getColor(nextBlock2[i][j]));
        }
    }
}

int GraphicalDisplay::getColor(char c) {
    switch (c) {
        case 'I': return 1; // Cyan
        case 'J': return 2; // Blue
        case 'L': return 3; // Orange
        case 'O': return 4; // Yellow
        case 'S': return 5; // Green
        case 'T': return 6; // Purple
        case 'Z': return 7; // Red
        default: return 0;  // Background color
    }
}

vector<vector<char>> GraphicalDisplay::blockGrid(char type) {
    vector<vector<char>> blockGrid;
    if (type == 'L') {
        blockGrid = 
        {{' ', ' ', 'L', ' '}, 
        {'L', 'L', 'L', ' '}};
    } else if (type == 'O') {
       blockGrid = 
        {{'O', 'O', ' ', ' '}, 
        {'O', 'O', ' ', ' '}}; 
    } else if (type == 'T') {
       blockGrid = 
        {{'T', 'T', 'T', ' '}, 
        {' ', 'T', ' ', ' '}};  
    } else if (type == 'S') {
        blockGrid = 
        {{' ', 'S', 'S', ' '}, 
        {'S', 'S', ' ', ' '}};  
    } else if (type == 'I') {
        blockGrid = 
        {{'I', 'I', 'I', 'I'}, 
        {' ', ' ', ' ', ' '}};  
    } else if (type == 'J') {
        blockGrid = 
        {{'J', ' ', ' ', ' '}, 
        {'J', 'J', 'J', ' '}};  
    } else if (type == 'Z') {
        blockGrid = 
        {{'Z', 'Z', ' ', ' '}, 
        {' ', 'Z', 'Z', ' '}};  
    }

    return blockGrid;
}


