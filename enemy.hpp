#include <iostream>

float move;
int takeDamage(const int amount);

class Enemy{
    public:
    Enemy(const int waveLevel, const float spawnX, const float spawnY);
    int hp;
    int maxHp;
    float speed;
    float x,y;
    int rewardsCoins;
    int pathIndex;

    void move(const float nextY, const float nextX);
    bool takeDamage(const int amount);
    bool isAlive();

};