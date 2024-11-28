#include "j_block.h"
#include <vector>
using namespace std;

JBlock::JBlock(int level) : Block{'J',{{0,2}, {0,3}, {1,3}, {2,3}},
                    {{{1,-1}, {0,-2}, {-1,-1}, {-2,0}}, 
                    {{1,2}, {2,1}, {1,0}, {0,-1}}, 
                    {{-2,0}, {-1,1}, {0,0}, {1,-1}}, 
                    {{0,-1}, {-1,0}, {0,1}, {1,2}}}, level} {}