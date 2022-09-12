#include "HighScoreTable.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

#include "../../App/App.h"

HighScoreTable::HighScoreTable()
{
    
}

void HighScoreTable::AddHighScore(HighScore highScore)
{
    highScores.emplace_back(highScore);
    
    std::sort(highScores.begin(), highScores.end(), [](const HighScore& highScoreA, const HighScore& highScoreB)
    {
        return highScoreA.score > highScoreB.score;
    });
    
    if(highScores.size() > maxScores)
    {
        highScores.resize(maxScores);
    }
}

void HighScoreTable::WriteHighScores() const
{
    const std::string& filePath = App::GetBasePath() + "Saves/Scores.txt";
    
    std::ofstream inFile;

    inFile.open(filePath, std::fstream::out);
    
    if(!inFile.is_open())
    {
        std::cout << "Could not open the file for writing : " << filePath << std::endl;
        return;
    }

    for (auto& highscore : highScores)
    {
 
        inFile << ":" << highscore.name << "," << highscore.score << ";" << std::endl;
    }
    
    inFile.close();
}

void HighScoreTable::ReadHighScores()
{
    const std::string& filePath = App::GetBasePath() + "Saves/Scores.txt";
    
    std::ifstream inFile;

    inFile.open(filePath);

    std::string line = "";

    if(!inFile.is_open())
    {
        std::cout << "Could not open the file for reading : " << filePath << std::endl;
        return;
    }

    while(!inFile.eof())
    {
        std::getline(inFile, line);
        size_t namePos = std::string::npos;
        if((namePos = line.find(":")) != std::string::npos)
        {
            HighScore highScore;
            highScore.name = line.substr(namePos+1, 3);
            size_t scorePos = std::string::npos;
            if((scorePos = line.find(",")) != std::string::npos)
            {
                size_t endPos = std::string::npos;
                if((endPos = line.find(";")) != std::string::npos)
                {
                    if(endPos >= scorePos)
                    {
                        highScore.score = std::stoi(line.substr(scorePos+1, endPos-1));
                    }
                }
            }

            highScores.emplace_back(highScore);
        }
    }
}
