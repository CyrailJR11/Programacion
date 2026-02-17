#include "Examen.h"
#include <cmath>

void Examen::afegirTriangle(Triangle* t) {
    triangles.push_back(t);
}

void Examen::registrarResposta(float area, float perimetre) {
    respostesArea.push_back(area);
    respostesPerimetre.push_back(perimetre);
}

float Examen::calcularPuntuacio() const {
    float punts = 0;
    for (size_t i = 0; i < triangles.size(); i++) {
        if (fabs(triangles[i]->getArea() - respostesArea[i]) < 0.01)
            punts += 0.5;
        if (fabs(triangles[i]->getPerimetre() - respostesPerimetre[i]) < 0.01)
            punts += 0.5;
    }
    return punts;
}

float calcularPuntuacioFinal(const Examen& e) {
    return e.calcularPuntuacio();
}
