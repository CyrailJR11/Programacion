#pragma once
#include "Character.h"

////////////////////////////////////////////////////////
// BOB
// Jugador controlado con flechas
////////////////////////////////////////////////////////
class Bob : public Character {
public:
    Bob(float x, float y);
    void handleInput() override;
};
