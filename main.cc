#include "i_block.h"
#include "o_block.h"
#include "l_block.h"
#include "s_block.h"
#include "t_block.h"
#include "z_block.h"
#include "j_block.h"
#include "block.h"
#include "score.h"
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
    cout << "print" << endl;

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
}