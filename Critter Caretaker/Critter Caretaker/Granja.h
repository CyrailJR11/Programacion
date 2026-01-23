#ifndef GRANJA_H
#define GRANJA_H

#include <vector>
#include "Critter.h"

// Classe Granja que emmagatzema mascotes Critter
class Granja
{
private:
    // Vector dinamic de Critter
    vector<Critter*> critters;

public:
    // Afegeix una mascota a la granja
    void Afegir(Critter* c);

    // Busca una mascota pel seu nom
    Critter* Buscar(const string& name);
};

#endif
