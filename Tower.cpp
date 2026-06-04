#include "Tower.hpp"

Tower::Tower(float posX, float posY)
{
    x = posX;
    y = posY;

    range = 120.f;
    damage = 10;

    fireRate = 1.0f;
    cooldownTimer = 0.f;

    level = 1;
    upgradeCost = 50;
}

bool Tower::canShoot(float deltaTime)
{
    cooldownTimer -= deltaTime;

    if (cooldownTimer <= 0.f)
    {
        cooldownTimer = fireRate;
        return true;
    }

    return false;
}

void Tower::upgrade()
{
    level++;

    damage += 5;

    range += 10.f;

    if (fireRate > 0.2f)
    {
        fireRate -= 0.1f;
    }

    upgradeCost += 50;
}

float Tower::getX() const
{
    return x;
}

float Tower::getY() const
{
    return y;
}

int Tower::getDamage() const
{
    return damage;
}

float Tower::getRange() const
{
    return range;
}