#include "l_block.h"
#include <vector>
using namespace std;

LBlock::LBlock(int level) : Block{'L', {{0, 3}, {1, 3}, {2, 3}, {2, 2}}, {{{0, -2}, {-1, -1}, {-2, 0}, {-1, 1}}, {{-2, 1}, {1, 0}, {0, -1}, {-1, 0}}, {{-1, 1}, {0, 0}, {1, -1}, {0, -2}}, {{-1, 0}, {0, 1}, {1, 2}, {2, 1}}}, level} {}
