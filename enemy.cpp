#include "enemy.hpp"
#include <iostream>

void Enemy::move(const float nextY, const float nextX){
    x=nextX;
    y=nextY;
}
Enemy::Enemy(const int waveLevel, const float spawnX, const float spawnY){
 x=spawnX;
 y=spawnY;
 maxHp=100+(waveLevel*20);
 hp=maxHp;
 speed=2.0f;
 rewardsCoins=1;

}

bool Enemy::takeDamage(const int amount){
     hp-=amount;
     if (hp<=0){
        return true;
     } return false;
}

bool Enemy::isAlive(){
    if (hp<=0){
        return false;
    }return true;

}