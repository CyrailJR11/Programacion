#include "Game.h"
#include <iostream>

////////////////////////////////////////////////////////
// CONSTRUCTOR
////////////////////////////////////////////////////////
Game::Game() :
    window(VideoMode({ 800, 600 }), "Joc de Plataformes"),
    player(100, 100),
    bob(150, 150),
    font("./fonts/KOMIKAP_.ttf"),
    hud(font)
{
    window.setFramerateLimit(60);

    hud.setFont(font);
    hud.setCharacterSize(16);
    hud.setFillColor(Color::Black);
    hud.setPosition({ 10,10 });

    load();                 // cargar save
    loadLevel(currentLevel);// cargar nivel
}

////////////////////////////////////////////////////////
// DESTRUCTOR
////////////////////////////////////////////////////////
Game::~Game()
{
    for (auto e : enemies)
        delete e;

    save();
}

////////////////////////////////////////////////////////
// LOOP PRINCIPAL
////////////////////////////////////////////////////////
int Game::run()
{
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        handleEvents();
        update(dt);
        draw();
    }
    return 0;
}

////////////////////////////////////////////////////////
// SAVE
////////////////////////////////////////////////////////
void Game::save()
{
    ofstream f("save.txt");
    if (!f.is_open()) return;

    f << currentLevel << endl;
    f << score << endl;
}

////////////////////////////////////////////////////////
// LOAD
////////////////////////////////////////////////////////
void Game::load()
{
    ifstream f("save.txt");

    if (!f.is_open())
    {
        currentLevel = 1;
        score = 0;
        return;
    }

    f >> currentLevel;
    f >> score;

    if (currentLevel < 1)
        currentLevel = 1;
}

////////////////////////////////////////////////////////
// CARGAR NIVEL
////////////////////////////////////////////////////////
void Game::loadLevel(int level)
{
    for (auto e : enemies) delete e;
    enemies.clear();

    gameOver = false;

    string filename = "Level" + to_string(level) + ".txt";

    if (!levelLoader.loadFromFile(filename))
    {
        currentLevel = 1;
        levelLoader.loadFromFile("Level1.txt");
    }

    Vector2f start = levelLoader.getPlayerStartPosition();

    player.setPosition(start.x, start.y);
    bob.setPosition(start.x + 50, start.y);

    for (auto& pos : levelLoader.getEnemySpawns())
        enemies.push_back(new Enemy(pos.x, pos.y));
}

////////////////////////////////////////////////////////
// EVENTOS
////////////////////////////////////////////////////////
void Game::handleEvents()
{
    while (const optional event = window.pollEvent())
    {
        if (event->is<Event::Closed>())
            window.close();

        if (const auto* key = event->getIf<Event::KeyPressed>())
        {
            if (key->scancode == Keyboard::Scancode::P)
                paused = !paused;

            if (key->scancode == Keyboard::Scancode::R && gameOver)
                loadLevel(currentLevel);
        }
    }
}

////////////////////////////////////////////////////////
// UPDATE
////////////////////////////////////////////////////////
void Game::update(float dt)
{
    if (paused || gameOver) return;

    player.handleInput();
    bob.handleInput();

    player.update(dt, window.getSize().x, window.getSize().y);
    bob.update(dt, window.getSize().x, window.getSize().y);

    checkCollisions(player);
    checkCollisions(bob);

    for (auto e : enemies)
    {
        e->ai(window.getSize().x);
        e->update(dt, window.getSize().x, window.getSize().y);

        if (player.getBounds().findIntersection(e->getBounds()) ||
            bob.getBounds().findIntersection(e->getBounds()))
        {
            gameOver = true;
        }
    }
}

////////////////////////////////////////////////////////
// DRAW
////////////////////////////////////////////////////////
void Game::draw()
{
    window.clear(Color::White);

    levelLoader.draw(window);

    player.draw(window);
    bob.draw(window);

    for (auto e : enemies)
        e->draw(window);

    if (gameOver)
    {
        Text t(font);
        t.setString("GAME OVER");
        t.setCharacterSize(60);
        t.setFillColor(Color::Red);
        t.setPosition({ 200,250 });
        window.draw(t);
    }

    window.display();
}


////////////////////////////////////////////////////////
void Game::checkCollisions(Character& c)
{
    const vector<Platform>& plats = levelLoader.getPlatforms();

    FloatRect charBounds = c.getBounds();

    for (auto& platform : plats)
    {
        FloatRect platBounds = platform.getBounds();

        if (charBounds.findIntersection(platBounds))
        {
            c.stopFalling(platBounds.position.y - charBounds.size.y);
        }
    }
}
