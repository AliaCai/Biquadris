#include "z_block.h"
#include <vector>
using namespace std;

ZBlock::ZBlock(int level) : Block{'Z', {{0,2}, {1,2}, {1,3}, {2,3}}, 
                    {{{1,-1}, {0,0}, {-1,-1}, {-2,0}},
                    {{1,2}, {0,1}, {1,0}, {0,-1}}, 
                    {{-2,0}, {-1,-1}, {0,0}, {1,-1}},
                    {{0,-1}, {1,0}, {0,1}, {1,2}}}, level} {}
