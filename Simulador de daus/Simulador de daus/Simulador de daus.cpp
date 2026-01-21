#include <iostream>
#include <cstdlib>
#include "funcions.h"

using namespace std;

// -----------------------------------------------------
// Dibujo gráfico para un dado clásico de 6 caras.
// Usamos un switch con cada patrón de puntos (*).
// -----------------------------------------------------
void dibujarDau6(int valor) {
    cout << "+-------+\n";

    switch (valor) {
    case 1:
        cout << "|       |\n";
        cout << "|   *   |\n";   // punto en el centro
        cout << "|       |\n";
        break;
    case 2:
        cout << "| *     |\n";   // esquina superior izquierda
        cout << "|       |\n";
        cout << "|     * |\n";   // esquina inferior derecha
        break;
    case 3:
        cout << "| *     |\n";
        cout << "|   *   |\n";   // centro
        cout << "|     * |\n";
        break;
    case 4:
        cout << "| *   * |\n";   // dos puntos arriba
        cout << "|       |\n";
        cout << "| *   * |\n";   // dos puntos abajo
        break;
    case 5:
        cout << "| *   * |\n";
        cout << "|   *   |\n";   // centro
        cout << "| *   * |\n";
        break;
    case 6:
        cout << "| *   * |\n";
        cout << "| *   * |\n";   // tres filas de dos puntos
        cout << "| *   * |\n";
        break;
    }

    cout << "+-------+\n";
}

// -----------------------------------------------------
// Dibujo genérico para dados que NO son de 6 caras.
// Se muestra el número dentro de un recuadro ASCII.
// -----------------------------------------------------
void dibujarDauGenerico(int valor) {
    cout << "+-------+\n";
    cout << "|       |\n";

    // Centramos el número visualmente
    if (valor < 10)
        cout << "|   " << valor << "   |\n";
    else
        cout << "|  " << valor << "   |\n";

    cout << "|       |\n";
    cout << "+-------+\n";
}

// -----------------------------------------------------
// Función que decide QUÉ tipo de dibujo mostrar.
// Si el dado es de 6, usa dibujo con puntos.
// Si no, usa el dibujo genérico.
// -----------------------------------------------------
void mostrarDau(int valor, int caras) {
    if (caras == 6)
        dibujarDau6(valor);
    else
        dibujarDauGenerico(valor);
}

// -----------------------------------------------------
// Función que genera un número aleatorio entre 1 y N.
// Representa el lanzamiento real de un dado.
// -----------------------------------------------------
int tirarDau(int caras) {
    return rand() % caras + 1;
}