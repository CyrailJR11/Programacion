#include "Bob.h"

Bob::Bob(float x, float y)
    : Character(x, y, 250, -450) {
    shape.setFillColor(Color::Blue);
}

////////////////////////////////////////////////////////
// BOB
// Jugador controlado con flechas
////////////////////////////////////////////////////////

void Bob::handleInput() {
    velocity.x = 0;

    if (Keyboard::isKeyPressed(Keyboard::Key::Left))
        velocity.x = -speed;

    if (Keyboard::isKeyPressed(Keyboard::Key::Right))
        velocity.x = speed;

    if (Keyboard::isKeyPressed(Keyboard::Key::Up) && !isJumping) {
        velocity.y = jumpForce;
        isJumping = true;
    }
}
