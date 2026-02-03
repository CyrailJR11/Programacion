#pragma once
#include "Character.h"

////////////////////////////////////////////////////////
// ENEMY
// -----------------------------------------------------
// Enemigo automático.
// No usa teclado.
// Patrulla izquierda ↔ derecha.
////////////////////////////////////////////////////////

class Enemy : public Character {

private:
    int direction = 1; // 1 derecha, -1 izquierda

public:
    Enemy(float x, float y);

    void handleInput() override; // vacío

    // IA simple
    void ai(int MaxX);
};
