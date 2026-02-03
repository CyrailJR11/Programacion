#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>

using namespace sf;

////////////////////////////////////////////////////////
// PLATFORM NORMAL
////////////////////////////////////////////////////////

class Platform : public GameObject {
public:
    Platform(float x, float y, float w, float h);
    void update(float dt) override;
    void setColor(sf::Color color);
};

////////////////////////////////////////////////////////
// PLATFORM MAP CON ENEMIGOS
////////////////////////////////////////////////////////

class PlatformMap {
private:
    std::vector<Platform> platforms;

    // 🔥 NUEVO → posiciones donde crear enemigos
    std::vector<sf::Vector2f> enemySpawns;

    const int TILE_SIZE = 40;

    sf::Vector2f playerStartPosition;
    Platform goal;

public:
    PlatformMap();

    bool loadFromFile(const std::string& filename);

    const std::vector<Platform>& getPlatforms() const;
    const std::vector<sf::Vector2f>& getEnemySpawns() const; // 🔥

    sf::Vector2f getPlayerStartPosition() const;
    Platform getGoal();

    void draw(sf::RenderWindow& window);
    void update(float dt);
};
