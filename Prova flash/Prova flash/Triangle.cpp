#include "Triangle.h"
#include <iostream>

Triangle::Triangle() {
    descripcio = "Triangle generic";
    base = 0;
    alcada = 0;
    costats = { 0, 0, 0 };
}

Triangle::Triangle(string desc, int b, int h, vector<float> c) {
    descripcio = desc;
    base = b;
    alcada = h;
    costats = c;
}

float Triangle::calcularArea() {
    return (base * alcada) / 2.0f;
}

float Triangle::calcularPerimetre() {
    float suma = 0;
    for (float c : costats) suma += c;
    return suma;
}

float Triangle::getArea() {
    return calcularArea();
}

float Triangle::getPerimetre() {
    return calcularPerimetre();
}

void Triangle::mostrarInfo() {
    cout << "Descripcio: " << descripcio << endl;
    cout << "Costats: ";
    for (float c : costats) cout << c << " ";
    cout << endl;
    cout << "Area: " << calcularArea() << endl;
    cout << "Perimetre: " << calcularPerimetre() << endl;
}
