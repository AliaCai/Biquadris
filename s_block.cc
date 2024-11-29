#include "s_block.h"
#include <vector>
using namespace std;

SBlock::SBlock(int level): Block{'S', {{0,3},{1,3}, {1,2}, {2,2}}, 
                        {{{0,-2}, {-1,-1}, {0,0}, {-1,1}},
                        {{2,1}, {1,0}, {0,1}, {-1,0}},
                        {{-1,1}, {0,0}, {-1,-1}, {0,-2}},
                        {{-1,0}, {0,1}, {1,0}, {2,1}}}, level} {}

		
