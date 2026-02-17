#include <iostream>
#include "Triangle.h"
#include "TriangleEquilater.h"
#include "Examen.h"

using namespace std;

int main() {
	Examen examen;

	Triangle triangle1("Triangle rectangle", 10, 5, { 6, 8, 10 });
	TriangleEquilater triangle2(6);

	examen.afegirTriangle(&triangle1);
	examen.afegirTriangle(&triangle2);

	cout << "=== EXAMEN DE TRIANGLES ===\n\n";

	float area, perimetre;

	cout << "Figura 1:\n";
	triangle1.mostrarInfo();
	cout << "Introdueix l'area: ";
	cin >> area;
	cout << "Introdueix el perimetre: ";
	cin >> perimetre;
	examen.registrarResposta(area, perimetre);

	cout << "\nFigura 2:\n";
	triangle2.mostrarInfo();
	cout << "Introdueix l'area: ";
	cin >> area;
	cout << "Introdueix el perimetre: ";
	cin >> perimetre;
	examen.registrarResposta(area, perimetre);

	cout << "\nPuntuacio final: "
		<< calcularPuntuacioFinal(examen)
		<< " punts\n";

	return 0;
}
