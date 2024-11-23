#include "i_block.h"
#include "block.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

int main() {
    unique_ptr<Block> iblock = make_unique<IBlock>();

    // Print the initial shape
    auto shape = iblock->getShape(); //vector<vector<int>> 
    for (const auto& row : shape) {
        for (int cell : row) {
            if (cell == 1) std::cout << cell << " ";
        }
        std::cout << std::endl;
    }

    cout << endl;

    // Rotate the block and print the new shape
    shape = iblock->find_rotation(1);
    std::cout << "After rotation:\n";
    for (const auto& row : shape) {
        for (int cell : row) {
            if (cell == 1) std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
    cout << endl;

    return 0;
}