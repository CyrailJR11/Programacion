#include "BabyCritter.h"
#include <iostream>

// Constructor del BabyCritter
// Crida al constructor de la classe base Critter
BabyCritter::BabyCritter(const string& name)
    : Critter(name)
{
}

// Funció Play redefinida
// El nadó juga però amb un efecte menor
void BabyCritter::Play(int fun)
{
    cout << "El nado juga una mica..." << endl;
    Critter::Play(fun);
}
