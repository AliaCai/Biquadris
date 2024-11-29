#include "game.h"
#include <iostream>
#include "board.h"
#include "block.h"
#include <memory>
#include "level0.h"
using namespace std;

Game::Game(string fn1, string fn2) : player1{true}, fn1{fn1}, fn2{fn2}
{
    b1 = make_shared<Board>(fn1);
    b2 = make_shared<Board>(fn2);
    interpreter1 = make_shared<Interpreter>(b1.get());
    interpreter2 = make_shared<Interpreter>(b2.get());
    // td1 = make_unique<TextDisplay>(b1);
    //gd1 = make_shared<GraphicalDisplay>(b1);
    // td2 = make_unique<TextDisplay>(b2);
    //gd2 = make_shared<GraphicalDisplay>(b2);

    vector<shared_ptr<Board>> boards = {b1,b2};
    shared_ptr<Observer> gd = make_shared<GraphicalDisplay>(boards);

}

void Game::take_turn()
{
    string command;

    while(!cin.eof() && cin >> command){

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
        else if (command == "quit") break;
        else
        {
            cout << "please enter a valid command" << endl;
            continue;
        }
        // Check for a win condition
        if (!has_won()) {
            cout << "Player " << get_turn() << " has lost!" << endl;
            cout << "Game over!" << endl;
            break;
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
        b1->notifyObservers();
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
    cout << "Level:    " << b1->get_level()->get_level() << "      ";
    cout << "Level:    " << b2->get_level()->get_level() << endl;
    cout << "Score:    " << b1->get_score().get_score() << "      ";
    cout << "Score:    " << b2->get_score().get_score() << endl;
    cout << "------------     ------------" << endl; // Top border of the grid

    // Print the boards row by row, side by side
    for (int i = 0; i < rows; ++i) {
        // Print Player 1's board row
        for (int j = 0; j < cols; ++j) {
            cout << p1b.at(i).at(j);
        }

        cout << "      "; // Space between Player 1 and Player 2 boards

        // Print Player 2's board row
        for (int j = 0; j < cols; ++j) {
            cout << p2b.at(i).at(j);
        }

        cout << endl; // Move to the next row
    }

    // Print a separator line between the boards and the "Next" block
    cout << "------------     ------------" << endl;

    // Print the "Next" block section
    cout << "Next:             "; 
    cout << "Next:" << endl;

    char char1 = b1->getNextType();
    char char2 = b2->getNextType();

    vector<vector<char>> nb1 = blockGrid(char1);
    vector<vector<char>> nb2 = blockGrid(char2);

    for (int i = 0; i < 2; ++i) {
        // Print Player 1's board row
        for (int j = 0; j < 4; ++j) {
            cout << nb1.at(i).at(j);
        }

        cout << "               "; // Space between Player 1 and Player 2 boards

        // Print Player 2's board row
        for (int j = 0; j < 4; ++j) {
            cout << nb2.at(i).at(j);
        }

        cout << endl; // Move to the next row
    }

    cout << endl;

    
}

vector<vector<char>> Game::blockGrid(char type) {
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
