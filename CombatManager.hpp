#ifndef COMBATMANAGER_HPP
#define COMBATMANAGER_HPP

#include <vector>

#include "Tower.hpp"
#include "Enemy.hpp"
#include "GameState.hpp"

class CombatManager
{
public:
    // Calculate distance between two points
    static float calculateDistance(
        float x1,
        float y1,
        float x2,
        float y2);

    // Handle tower attacks
    static void processTowerAttacks(
        std::vector<Tower>& towers,
        std::vector<Enemy>& enemies,
        float deltaTime);

    // Remove dead enemies and give rewards
    static void cleanDeadEnemies(
        std::vector<Enemy>& enemies,
        GameState& state);
};

#endif