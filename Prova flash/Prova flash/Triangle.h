#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <string>
#include <vector>

using namespace std;

class Triangle {
protected:

	string descripcio;
	int base;
	int alcada;
	vector<float> costats;

public:
	Triangle();
	Triangle(string desc, int b, int h, vector<float> c);

	virtual float calcularArea();
	virtual float calcularPerimetre();
	virtual void mostrarInfo();

	float getArea();
	float getPerimetre();

	virtual ~Triangle() {}

};

#endif