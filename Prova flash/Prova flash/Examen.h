#ifndef EXAMEN_H
#define EXAMEN_H

#include <vector>
#include "Triangle.h"

using namespace std;

class Examen {
private:
    vector<Triangle*> triangles;
    vector<float> respostesArea;
    vector<float> respostesPerimetre;

public:
    void afegirTriangle(Triangle* t);
    void registrarResposta(float area, float perimetre);
    float calcularPuntuacio() const;

    friend float calcularPuntuacioFinal(const Examen& e);
};

#endif
