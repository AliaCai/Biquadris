#ifndef SCORE_H
#define SCORE_H
#include <iostream>

class Score {
    int score;
    int highscore;

    public:
    void cumulative_hs(int addBy);
    int get_score() const;
    int get_highScore() const;
    void resetScore();
    Score(int score, int highscore);
};

#endif