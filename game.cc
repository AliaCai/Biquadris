#include "game.h"
#include <iostream>
#include "board.h"
#include "block.h"
#include <memory>
#include "level0.h"           
using namespace std;

Game::Game():player1{true} {
    b1 = make_unique<Board>(0,0,0);
    b2 = make_unique<Board>(0,0,0);

    if (level )
    

}