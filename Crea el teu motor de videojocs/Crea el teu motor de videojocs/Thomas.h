#pragma once
#include "Character.h"

////////////////////////////////////////////////////////
// THOMAS
// Jugador controlado con WASD
////////////////////////////////////////////////////////
class Thomas : public Character {
public:
    Thomas(float x, float y);
    void handleInput() override;
};
