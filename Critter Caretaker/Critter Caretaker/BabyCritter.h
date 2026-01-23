#ifndef BABYCRITTER_H
#define BABYCRITTER_H

#include "Critter.h"

// Classe filla de Critter amb comportament mes basic
class BabyCritter : public Critter
{
public:
    // Constructor que assigna el nom al nadó
    BabyCritter(const string& name);

    // Jugar amb menys efecte que un Critter normal
    void Play(int fun = 2);
};

#endif
