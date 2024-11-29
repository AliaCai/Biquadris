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

int main(int argc, char* argv[]) {
    // Create the game instance
//     Game game{argv[1], argv[2]};

//     // Print initial state of the boards
//     game.printBoards();

//     // Main game loop
//     cout << "Starting the game! Player 1 begins." << endl;
//     while (true) {
//         // Display whose turn it is
//         cout << "Player " << game.get_turn() << "'s turn." << endl;

//         // Allow the player to take their turn
//         game.take_turn();

//         // Print updated boards
//         game.printBoards();

//         // Check for a win condition
//         if (!game.has_won()) {
//             cout << "Player " << game.get_turn() << " has lost!" << endl;
//             cout << "Game over!" << endl;
//             break;
//         }
//     }

//     // Reset the game after it ends (optional)
//     game.reset();
//     return 0;
// }
    /*
    vector<shared_ptr<Block>> blocks;



    blocks.push_back(make_shared<IBlock>());
    blocks.push_back(make_shared<OBlock>());
    blocks.push_back(make_shared<LBlock>());
    blocks.push_back(make_shared<SBlock>());
    blocks.push_back(make_shared<TBlock>());
    blocks.push_back(make_shared<ZBlock>());
    blocks.push_back(make_shared<JBlock>());
    // Print the initial shape
    for (auto it = blocks.begin(); it != blocks.end(); ++it) {
        char type = (*it)->get_type();
        cout << type << endl;

        auto shape = (*it)->getShape();
        for (const auto& row : shape) {
            for (int cell : row) {
                if (cell == 1) cout << type;
                else if (cell == -1) cout << " ";
            }
            cout << endl;
        }


    //     cout << endl;



        // Rotate the block and print the new shape
        (*it)->rotateClockwise();
        (*it)->rotateClockwise();
        (*it)->rotateClockwise();
        (*it)->rotateClockwise();
        (*it)->rotateCounterClockwise();
        (*it)->rotateCounterClockwise();
        shape = (*it)->get_curShape();
        std::cout << "After rotation:\n";
        for (const auto& row : shape) {
            for (int cell : row) {
                if (cell == 1) cout << type;
                else if (cell == -1) cout << " ";
            }
            cout << endl;
        }
        cout << endl;
    }


    return 0;
    */

    /*
    //score testing
    Score s{1, 2};
    cout << s.get_score() << " " << s.get_highScore() << endl;
    s.resetScore();
    cout << s.get_score() << " " << s.get_highScore() << endl;
    s.cumulative_s(1, 2, 3, 4);
    cout << s.get_score() << " " << s.get_highScore() << endl;
    s.resetScore();
    cout << s.get_score() << " " << s.get_highScore() << endl;
    */

    // level2 testing---------------------------------
    //cout << "print" << endl;
    
shared_ptr<Level> level = make_shared<Level2>();
for (int i = 0; i < 10; i++)
{
    shared_ptr<Block> cur_block = level->currentBlock();
    level->set_seed(i);
    cout << "i:" << i << " seed:" << level->get_seed() << " block:" << cur_block->get_type() << endl;
}

    
        // level0 testing---------------------------------
        shared_ptr<Level> level0 = make_shared<Level0>("sequence2.txt", 0);

        for (int i = 0; i < 20; ++i)
        {
            level0->set_count(13);
            cout << i % 8 << level0->currentBlock()->get_type() << " end" << endl;
        }
    

    
    //more level0 testing---------------------------------
    shared_ptr<Block> cur_block = level->currentBlock();
    cout << cur_block->get_type() << " end" << endl;

    level->set_count(13);
    shared_ptr<Block> next_block1 = level->currentBlock();
    cout << next_block1->get_type() << " end" << endl;

    level->set_count(15);
    shared_ptr<Block> next_block2 = level->currentBlock();
    cout << next_block2->get_type() << " end" << endl;
}
