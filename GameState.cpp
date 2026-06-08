#include "GameState.hpp"

#include <fstream>

// Constructor: initialize default values
GameState::GameState()
{
    coins = 100;
    score = 0;

    waveId = 1;

    gameTimer = 0.0f;

    volume = 50;

    difficulty = "Medium";
}

// Add coins to the player balance
void GameState::addCoins(int amount)
{
    coins += amount;
}

// Spend coins if possible
bool GameState::spendCoins(int amount)
{
    if (coins >= amount)
    {
        coins -= amount;
        return true;
    }

    return false;
}

// Add points to the score
void GameState::addScore(int amount)
{
    score += amount;
}

// Save the current score to a file
void GameState::saveHighScore()
{
    std::ofstream file("highscores.txt", std::ios::app);

    if (file.is_open())
    {
        file << score << std::endl;
        file.close();
    }
}

// Return player coins
int GameState::getCoins() const
{
    return coins;
}

// Return current score
int GameState::getScore() const
{
    return score;
}

// Return current wave
int GameState::getWaveId() const
{
    return waveId;
}

// Return game timer
float GameState::getGameTimer() const
{
    return gameTimer;
}

// Return sound volume
int GameState::getVolume() const
{
    return volume;
}

// Return selected difficulty
std::string GameState::getDifficulty() const
{
    return difficulty;
}

// Return high score list
std::vector<int> GameState::getHighScores() const
{
    return highScores;
}