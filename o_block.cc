#include "o_block.h"
#include <vector>
using namespace std;

OBlock::OBlock(int level): Block{'O', {{0,2}, {1,2}, {0,3}, {1,3}}, 
                        {{{0,0}, {0,0}, {0,0}, {0,0}}, 
                        {{0,0}, {0,0}, {0,0}, {0,0}}, 
                        {{0,0}, {0,0}, {0,0}, {0,0}}, 
                        {{0,0}, {0,0}, {0,0}, {0,0}}}, level} {}


