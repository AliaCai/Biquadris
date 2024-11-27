#include "j_block.h"
#include <vector>
using namespace std;

JBlock::JBlock() : num_rot{0}, cells_left{4}, type{'J'}, curPosition{{0,2}, {0,3}, {1,3}, {2,3}},
                    {{{1,-1}, {0,-2}, {-1,-1}, {-2,0}}, 
                    {{1,3}, {2,2}, {1,1}, {0,0}}, 
                    {{-2,-1}, {-1,0}, {0,-1}, {1,-2}}, 
                    {{0,-1}, {-1,0}, {0,1}, {1,2}}} {}