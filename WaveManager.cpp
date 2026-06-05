#include <iostream>
#include "WaveManager.hpp"

WaveManager::WaveManager(){
    currentWaveNumber=0;
    enemiesRemainingInWave=0;
    spawnInterval=1;
    spawnTimer=0.0f;
    isWaveActive=false;
}

void WaveManager::startNextWave(){
    currentWaveNumber++;
    isWaveActive=true;
    enemiesRemainingInWave=currentWaveNumber*5;
}

void WaveManager::updateWave(const float deltaTime){
    

}

