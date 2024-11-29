#include "game.h"
#include <iostream>
#include "board.h"
#include "block.h"
#include <memory>
#include "level0.h"
using namespace std;

Game::Game(string fn1, string fn2) : player1{true}, fn1{fn1}, fn2{fn2}
{
    b1 = make_unique<Board>(fn1);
    b2 = make_unique<Board>(fn2);
    interpreter1 = make_unique<Interpreter>(b1.get());
    interpreter2 = make_unique<Interpreter>(b2.get());
    // td1 = make_unique<TextDisplay>(b1);
    // gd1 = make_unique<GraphicalDisplay>(b1);
    // td2 = make_unique<TextDisplay>(b2);
    // gd2 = make_unique<GraphicalDisplay>(b2);
}

void Game::take_turn()
{
    string command;

    while(cin >> command){

    Interpreter::Command cmd;

    if (command == "left")
        cmd = Interpreter::Command::Left;
    else if (command == "right")
        cmd = Interpreter::Command::Right;
    else if (command == "down")
        cmd = Interpreter::Command::Down;
    else if (command == "clockwise")
        cmd = Interpreter::Command::Clockwise;
    else if (command == "counterclockwise")
        cmd = Interpreter::Command::CounterClockwise;
    else if (command == "drop")
        cmd = Interpreter::Command::Drop;
    else if (command == "levelup")
        cmd = Interpreter::Command::LevelUp;
    else if (command == "leveldown")
        cmd = Interpreter::Command::LevelDown;
    else if (command == "restart")
        cmd = Interpreter::Command::Restart;
    else
    {
        cout << "please enter a valid command" << endl;
        continue;
    }

    if (player1)
    {
        interpreter1->executeCommand(cmd);
    }
    else
    {
        interpreter2->executeCommand(cmd);
    }

    printBoards();
    if (command == "drop") player1 = !player1;

    
    }
}

bool Game::has_won()
{
    if (player1)
    {
        return b1->is_block_valid();
    }
    else
    {
        return b2->is_block_valid();
    }
}

void Game::reset()
{
    b1->restart();
    b2->restart();
    player1 = true;
}

int Game::get_turn()
{
    return player1 ? 1 : 2;
}

void Game::printBoards() {
    vector<vector<char>> p1b = b1->getBoard(); // Player 1's board
    vector<vector<char>> p2b = b2->getBoard(); // Player 2's board

    const int rows = 18; // Number of rows in the board
    const int cols = 11; // Number of columns in the board

    // Print levels and scores
    cout << "Level:    " << b1->get_level()->get_level() << "     ";
    cout << "Level:    " << b2->get_level()->get_level() << endl;
    cout << "Score:    " << b1->get_score().get_score() << "     ";
    cout << "Score:    " << b2->get_score().get_score() << endl;
    cout << "------------     ------------" << endl; // Top border of the grid

    // Print the boards row by row, side by side
    for (int i = 0; i < rows; ++i) {
        // Print Player 1's board row
        for (int j = 0; j < cols; ++j) {
            cout << p1b.at(i).at(j);
        }

        cout << "     "; // Space between Player 1 and Player 2 boards

        // Print Player 2's board row
        for (int j = 0; j < cols; ++j) {
            cout << p2b.at(i).at(j);
        }

        cout << endl; // Move to the next row
    }

    // Print a separator line between the boards and the "Next" block
    cout << "------------     ------------" << endl;

    // Print the "Next" block section
    cout << "Next:     "; 
    cout << "Next:" << endl;

    // Get the "Next" blocks for both players
    vector<vector<int>> p1Next = b1->get_nextBlock();
    vector<vector<int>> p2Next = b2->get_nextBlock();

    // Helper lambda to print a block shape
    auto printNextBlock = [](const vector<vector<int>>& block, char blockChar) {
        // Calculate the bounding box for the block
        int minRow = 18, maxRow = 0, minCol = 11, maxCol = 0;
        for (const auto& coord : block) {
            minRow = min(minRow, coord[0]);
            maxRow = max(maxRow, coord[0]);
            minCol = min(minCol, coord[1]);
            maxCol = max(maxCol, coord[1]);
        }

        // Create a grid to represent the shape
        int height = maxRow - minRow + 1;
        int width = maxCol - minCol + 1;
        vector<vector<char>> grid(height, vector<char>(width, ' '));

        // Fill the grid with the block's character
        for (const auto& coord : block) {
            grid[coord[0] - minRow][coord[1] - minCol] = blockChar;
        }

        // Print the grid
        for (const auto& row : grid) {
            for (char cell : row) {
                cout << cell;
            }
            cout << endl;
        }
    };

    // Print Player 1's "Next" block
    printNextBlock(p1Next, b1->getNextType()); // Replace 'J' with actual block type if available

    cout << "     "; // Space between Player 1 and Player 2's "Next" blocks

    // Print Player 2's "Next" block
    printNextBlock(p2Next, b2->getNextType()); // Replace 'J' with actual block type if available
}
