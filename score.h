#ifndef SCORE_H
#define SCORE_H
#include <iostream>

class Score {
    int score;
    int highscore;

    public:
    int cumulative_hs();
    Score(int score, int highscore);
};

#endif