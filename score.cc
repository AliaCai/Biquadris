#include "score.h"

Score::Score(int score = 0, int highscore = 0) : score{score}, highscore{highscore} {}

int Score::get_highScore() const
{
    return highscore;
}

int Score::get_score() const
{
    return score;
}

void Score::resetScore()
{
    if (score > highscore)
    {
        highscore = score;
    }
    score = 0;
}

void Score::cumulative_s(int cur_level = 0, int num_lines = 0, int ori_level = 0, int num_blocks = 0)
{
    score += (cur_level + num_lines) * (cur_level + num_lines);
    score += (ori_level + num_blocks) * (ori_level + num_blocks);
}