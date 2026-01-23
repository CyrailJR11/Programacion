#include "Granja.h"

// Afegeix una mascota a la granja
void Granja::Afegir(Critter* c)
{
    critters.push_back(c);
}

// Busca una mascota pel seu nom
Critter* Granja::Buscar(const string& name)
{
    for (auto c : critters)
        if (c->GetName() == name)
            return c;

    return nullptr;
}
