#include <iostream>
#include "Critter.h"
#include "BabyCritter.h"
#include "Granja.h"

using namespace std;

int main()
{
    // Creacio de mascotes
    Critter c1("Rex");
    Critter c2("Luna");

    // Interaccio amb la mascota
    // Jugar i menjar per mantenir-la contenta
    c1.Eat();
    c1.Play();
    c1.Talk();
    ShowCritterStatus(c1);

    // Creacio d'una nova mascota amb l'operador +
    Critter baby = c1 + c2;
    ShowCritterStatus(baby);

    // Mascota nadó amb comportament basic
    BabyCritter b("Petit");
    b.Play();
    b.Eat();
    b.Talk();

    // Creacio de la granja
    Granja g;
    g.Afegir(&c1);
    g.Afegir(&baby);
    g.Afegir(&b);

    // Buscar una mascota per nom
    Critter* found = g.Buscar("Rex");
    if (found)
        found->Talk();

    //Codigo ASCII
    cout << R"(                                                                                                                                  
  _____         __       
 / ___/__ _____/ /__  ___
/ /__/ _ `/ __/ / _ \(_-<
\___/\_,_/_/ /_/\___/___/

		)";

    return 0;
}
