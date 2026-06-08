#include "CombatManager.hpp"

#include <cmath>

// Calculate distance between two points
float CombatManager::calculateDistance(
    float x1,
    float y1,
    float x2,
    float y2)
{
    return std::sqrt(
        (x2 - x1) * (x2 - x1) +
        (y2 - y1) * (y2 - y1));
}

// Handle tower attacks
void CombatManager::processTowerAttacks(
    std::vector<Tower>& towers,
    std::vector<Enemy>& enemies,
    float deltaTime)
{
    for (Tower& tower : towers)
    {
        // Check if the tower can shoot
        if (!tower.canShoot(deltaTime))
        {
            continue;
        }

        for (Enemy& enemy : enemies)
        {
            // Ignore dead enemies
            if (!enemy.isAlive())
            {
                continue;
            }

            float distance = calculateDistance(
                tower.getX(),
                tower.getY(),
                enemy.x,
                enemy.y);

            // Attack the first enemy in range
            if (distance <= tower.getRange())
            {
                enemy.takeDamage(
                    tower.getDamage());

                break;
            }
        }
    }
}

// Remove dead enemies and give rewards
void CombatManager::cleanDeadEnemies(
    std::vector<Enemy>& enemies,
    GameState& state)
{
    for (auto it = enemies.begin();
         it != enemies.end();)
    {
        if (!it->isAlive())
        {
            // Give coins to the player
            state.addCoins(it->rewardsCoins);

            // Increase player score
            state.addScore(100);

            // Remove enemy from the vector
            it = enemies.erase(it);
        }
        else
        {
            ++it;
        }
    }
}