#include <iostream>

float move;
int takeDamage(int amount);

class Enemy{
    public:
    Enemy(int wave);
    int hp;
    int maxHp;
    float speed;
    float x,y;
    int rewardsCoins;
    int pathIndex;

    void move(float nextY, float nextX);
    bool takeDamage(int amount);

};