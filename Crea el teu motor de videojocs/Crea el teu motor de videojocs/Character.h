#pragma once
#include "GameObject.h"

using namespace sf;

////////////////////////////////////////////////////////
// CHARACTER (CLASE BASE DE ENTIDADES VIVAS)
// -----------------------------------------------------
// Padre de:
//   - Thomas
//   - Bob
//   - Enemy
//
// Añade:
//  - física (gravedad)
//  - velocidad
//  - salto
//  - límites de pantalla
////////////////////////////////////////////////////////

class Character : public GameObject {

protected:

    Vector2f velocity; // movimiento actual
    bool isJumping;    // evita doble salto

    const float GRAVITY = 800.0f;

    float speed;       // velocidad horizontal
    float jumpForce;   // fuerza de salto

private:

    // no se usa (GameObject obliga a implementarlo)
    void update(float dt) override {}

public:

    Character(float x, float y, float spd, float jmp);

    // cada hijo define su input
    virtual void handleInput() = 0;

    // update con física
    void update(float dt, int MaxX, int MaxY);

    void setPosition(float x, float y);

    // usado al tocar plataformas
    void stopFalling(float y);
};
