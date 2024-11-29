#ifndef SCORE_H
#define SCORE_H
#include <iostream>

class Score
{
    int score;
    int highscore;

public:
    void cumulative_s(int cur_level, int num_lines, int ori_level, int num_blocks);
    int get_score() const;
    int get_highScore() const;
    void resetScore();
    Score(int score, int highscore);
};

#endif
