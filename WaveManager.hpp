#include "enemy.hpp"
#include <vector>
#include <iostream>

class WaveManager{
    public:

    int currentWaveNumber;          
    int enemiesRemainingInWave;    
    float spawnInterval;           
    float spawnTimer;            
    bool isWaveActive;          
    std::vector<Enemy> activeEnemies;

    WaveManager();

    void startNextWave();
    void updateWave(float deltaTime);
    void spawnEnemy();
};
