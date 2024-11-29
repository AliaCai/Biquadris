#include "board.h"
#include "i_block.h"
#include "o_block.h"
#include "l_block.h"
#include "s_block.h"
#include "t_block.h"
#include "z_block.h"
#include "j_block.h"
#include "block.h"
#include "score.h"
#include "level.h"
#include "level0.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "game.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
    // Create the game instance
    Game game{argv[1], argv[2]};

    // Print initial state of the boards
    game.printBoards();

    // Main game loop
    cout << "Starting the game! Player 1 begins." << endl;
    // Display whose turn it is
    cout << "Player " << game.get_turn() << "'s turn." << endl;

    // Allow the player to take their turn
    game.take_turn();

    return 0;
}

