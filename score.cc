#include "score.h"

Score::Score(int highscore, int score): score{score}, highscore{highscore} {}

void Score::resetScore() {
    score = 0;
}

int Score::get_highScore() const {
    return highscore;
}

int Score::get_score() const {
    return score;
}

void Score::cumulative_hs(int addBy) {
    highscore += addBy;
}