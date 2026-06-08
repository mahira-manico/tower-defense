#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include <string>
#include <vector>

class GameState
{
private:
    // Player resources
    int coins;
    int score;

    // Current wave number
    int waveId;

    // Game timer
    float gameTimer;

    // Sound volume (0 - 100)
    int volume;

    // Selected difficulty
    std::string difficulty;

    // High score list
    std::vector<int> highScores;

public:
    // Constructor
    GameState();

    // Manage player coins
    void addCoins(int amount);
    bool spendCoins(int amount);

    // Increase player score
    void addScore(int amount);

    // Save the final score
    void saveHighScore();

    // Getters
    int getCoins() const;
    int getScore() const;
    int getWaveId() const;
    float getGameTimer() const;
    int getVolume() const;
    std::string getDifficulty() const;
    std::vector<int> getHighScores() const;
};

#endif