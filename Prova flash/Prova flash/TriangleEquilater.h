#ifndef TRIANGLEEQUILATER_H
#define TRIANGLEEQUILATER_H

#include "Triangle.h"

class TriangleEquilater : public Triangle {
public:
    TriangleEquilater(float costat);

    float calcularArea() override;
    float calcularPerimetre() override;
    void mostrarInfo() override;
};

#endif
