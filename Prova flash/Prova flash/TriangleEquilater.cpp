#include "TriangleEquilater.h"
#include <iostream>
#include <cmath>

TriangleEquilater::TriangleEquilater(float costat) {
    descripcio = "Triangle Equilater";
    base = costat;
    alcada = (1.732 * costat) / 2;
    costats = { costat, costat, costat };
}

float TriangleEquilater::calcularArea() {
    return (1.732 / 4) * base * base;
}

float TriangleEquilater::calcularPerimetre() {
    return costats[0]*3;
}

void TriangleEquilater::mostrarInfo() {
    cout << "Descripcio: " << descripcio << endl;
    cout << "Costat: " << base << endl;
    cout << "Area: " << calcularArea() << endl;
    cout << "Perimetre: " << calcularPerimetre() << endl;
}
