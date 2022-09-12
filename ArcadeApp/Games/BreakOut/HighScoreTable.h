#pragma once
#include <string>
#include <vector>

struct HighScore
{
    std::string name;
    uint32_t score;
};

class HighScoreTable
{
public:
    HighScoreTable();

    void AddHighScore(HighScore highScore);
    inline const std::vector<HighScore>& GetAllHighScores() { return highScores; }
    
private:

    std::vector<HighScore> highScores;
    const int maxScores = 10;
public:
    void WriteHighScores() const;
    void ReadHighScores();
};
