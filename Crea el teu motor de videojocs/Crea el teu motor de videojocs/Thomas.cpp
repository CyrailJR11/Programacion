#include "Thomas.h"

Thomas::Thomas(float x, float y)
    : Character(x, y, 250, -450) {
    shape.setFillColor(sf::Color::Green);
}

////////////////////////////////////////////////////////
// THOMAS
// Jugador controlado con WASD
////////////////////////////////////////////////////////

void Thomas::handleInput() {
    velocity.x = 0;

    if (sf::Keyboard::isKeyPressed(Keyboard::Key::A))
        velocity.x = -speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        velocity.x = speed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && !isJumping) {
        velocity.y = jumpForce;
        isJumping = true;
    }
}
