#include "Character.h"

////////////////////////////////////////////////////////
// Constructor
// Define tamaño fijo del personaje
////////////////////////////////////////////////////////
Character::Character(float x, float y, float spd, float jmp)
    : GameObject(x, y, 40, 60)
{
    velocity = { 0,0 };
    isJumping = false;

    speed = spd;
    jumpForce = jmp;
}

////////////////////////////////////////////////////////
// UPDATE FÍSICO
// - gravedad
// - movimiento
// - límites pantalla
// - suelo
////////////////////////////////////////////////////////
void Character::update(float dt, int MaxX, int MaxY)
{
    // gravedad
    velocity.y += GRAVITY * dt;

    // mover
    position.x += velocity.x * dt;
    position.y += velocity.y * dt;

    float suelo = 140;
    float ancho = shape.getSize().x;

    // colisión suelo
    if (position.y > MaxY - suelo)
    {
        position.y = MaxY - suelo;
        velocity.y = 0;
        isJumping = false;
    }

    // límites izquierda
    if (position.x < 0)
        position.x = 0;

    // límites derecha
    if (position.x > MaxX - ancho)
        position.x = MaxX - ancho;

    shape.setPosition(position);
}

////////////////////////////////////////////////////////
// Forzar posición
////////////////////////////////////////////////////////
void Character::setPosition(float x, float y)
{
    position = { x, y };
    shape.setPosition(position);
}

////////////////////////////////////////////////////////
// Se usa cuando cae sobre plataforma
////////////////////////////////////////////////////////
void Character::stopFalling(float y)
{
    position.y = y;
    velocity.y = 0.f;
    isJumping = false;

    shape.setPosition(position);
}
