#include "Platform.h"

////////////////////////////////////////////////////////
// PLATFORM
////////////////////////////////////////////////////////

Platform::Platform(float x, float y, float w, float h)
    : GameObject(x, y, w, h)
{
    shape.setFillColor(Color(245, 39, 221));
}

void Platform::update(float dt) {}

void Platform::setColor(sf::Color color) {
    shape.setFillColor(color);
}

////////////////////////////////////////////////////////
// PLATFORM MAP
////////////////////////////////////////////////////////

PlatformMap::PlatformMap()
    : goal(150, 150, 40, 40)
{
    playerStartPosition = { 100,100 };
    goal.setColor(Color::Yellow);
}

Platform PlatformMap::getGoal() {
    return goal;
}

////////////////////////////////////////////////////////
// 🔥 CARGA DE MAPA CON ENEMIGOS
////////////////////////////////////////////////////////

bool PlatformMap::loadFromFile(const std::string& filename)
{
    platforms.clear();
    enemySpawns.clear(); // 🔥 limpiar enemigos anteriores

    std::ifstream file(filename);
    if (!file.is_open()) return false;

    std::string line;
    int y = 0;

    while (std::getline(file, line))
    {
        for (int x = 0; x < line.length(); x++)
        {
            char tile = line[x];

            if (tile == '1')
            {
                platforms.emplace_back(
                    (float)(x * TILE_SIZE),
                    (float)(y * TILE_SIZE),
                    (float)TILE_SIZE,
                    (float)TILE_SIZE
                );
            }
            else if (tile == 'P')
            {
                playerStartPosition = {
                    (float)(x * TILE_SIZE),
                    (float)(y * TILE_SIZE)
                };
            }
            else if (tile == 'G')
            {
                goal.setPosition(
                    (float)(x * TILE_SIZE),
                    (float)(y * TILE_SIZE)
                );
            }
            else if (tile == 'E') // 🔥 ENEMIGO
            {
                enemySpawns.emplace_back(
                    (float)(x * TILE_SIZE),
                    (float)(y * TILE_SIZE)
                );
            }
        }

        y++;
    }

    file.close();
    return true;
}

////////////////////////////////////////////////////////

const std::vector<Platform>& PlatformMap::getPlatforms() const {
    return platforms;
}

const std::vector<sf::Vector2f>& PlatformMap::getEnemySpawns() const {
    return enemySpawns;
}

sf::Vector2f PlatformMap::getPlayerStartPosition() const {
    return playerStartPosition;
}

////////////////////////////////////////////////////////

void PlatformMap::draw(sf::RenderWindow& window)
{
    for (auto& p : platforms)
        p.draw(window);

    goal.draw(window);
}

void PlatformMap::update(float dt)
{
    for (auto& p : platforms)
        p.update(dt);
}
