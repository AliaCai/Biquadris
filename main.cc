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
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main()
{
    /*
    vector<unique_ptr<Block>> blocks;



    blocks.push_back(make_unique<IBlock>());
    blocks.push_back(make_unique<OBlock>());
    blocks.push_back(make_unique<LBlock>());
    blocks.push_back(make_unique<SBlock>());
    blocks.push_back(make_unique<TBlock>());
    blocks.push_back(make_unique<ZBlock>());
    blocks.push_back(make_unique<JBlock>());
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
    cout << "print" << endl;
    /*
unique_ptr<Level> level = make_unique<Level2>();
for (int i = 0; i < 10; i++)
{
    unique_ptr<Block> cur_block = level->currentBlock();
    level->set_seed(i);
    cout << "i:" << i << " seed:" << level->get_seed() << " block:" << cur_block->get_type() << endl;
}
*/
    /*
        // level0 testing---------------------------------
        unique_ptr<Level> level = make_unique<Level0>("sequence2.txt", 0);

        for (int i = 0; i < 20; ++i)
        {
            level->set_count(13);
            cout << i % 8 << level->currentBlock()->get_type() << " end" << endl;
        }
    */

    /*
    //more level0 testing---------------------------------
    unique_ptr<Block> cur_block = level->currentBlock();
    cout << cur_block->get_type() << " end" << endl;

    level->set_count(13);
    unique_ptr<Block> next_block1 = level->currentBlock();
    cout << next_block1->get_type() << " end" << endl;

    level->set_count(15);
    unique_ptr<Block> next_block2 = level->currentBlock();
    cout << next_block2->get_type() << " end" << endl;*/
}
