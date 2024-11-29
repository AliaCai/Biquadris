#include "i_block.h"
#include <vector>
using namespace std;

IBlock::IBlock(int level): Block{'I', {{0,3}, {1,3}, {2,3}, {3,3}},
                        {{{0,-3}, {-1,-2}, {-2,-1}, {-3,0}},
                        {{3,3}, {2,2}, {1,1}, {0,0}}, 
                        {{-3,0}, {-2,-1}, {-1,-2}, {0,-3}},
                        {{0,0}, {1,1}, {2,2}, {3,3}}}, level} {}
                 