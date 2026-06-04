#ifndef TOWER_HPP
#define TOWER_HPP

// Tower class: handles tower stats and upgrades
class Tower
{
private:
    // Tower position on the map
    float x;
    float y;

    // Attack range
    float range;

    // Damage dealt per shot
    int damage;

    // Shooting speed and cooldown timer
    float fireRate;
    float cooldownTimer;

    // Upgrade system
    int level;
    int upgradeCost;

public:
    // Create a tower at a specific position
    Tower(float posX, float posY);

    // Check if the tower is ready to shoot
    bool canShoot(float deltaTime);

    // Upgrade tower statistics
    void upgrade();

    // Position getters
    float getX() const;
    float getY() const;

    // Combat getters
    int getDamage() const;
    float getRange() const;
};

#endif