#include "game.h"
#include <iostream>
#include "board.h"
#include "block.h"
#include <memory>
#include "level0.h"
using namespace std;

Game::Game() : player1{true}
{
    b1 = make_unique<Board>();
    b2 = make_unique<Board>();
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
        cout << "Invalid command." << endl;
        return;
    }

    if (player1)
    {
        interpreter1->executeCommand(cmd);
    }
    else
    {
        interpreter2->executeCommand(cmd);
    }

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
    vector<vector<char>> p1b = b1->getBoard();
    vector<vector<char>> p2b = b2->getBoard();

    //width = 11, height = 18 
    cout << "Level:    " << b1->get_level()->get_level() << "     ";
    cout << "Level:    " << b2->get_level()->get_level() << endl;
    cout << "Score:    " << b1->get_score().get_score() << "     ";
    cout << "Score:    " << b2->get_score().get_score() <<endl;
    cout << "------------     ------------" << endl; // Top border of the grid
}

