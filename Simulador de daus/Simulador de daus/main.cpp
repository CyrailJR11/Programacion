#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funcions.h"
using namespace std;

int main() {
    // Inicializamos el generador de números aleatorios con la hora actual
    // Esto asegura que cada ejecución del programa produzca secuencias diferentes
    srand(time(0));

    // Variable para almacenar la opción seleccionada por el usuario
    int op;

    // Mostramos el menú principal con las opciones disponibles
    cout << "1. Tirar dau de 6 cares\n";
    cout << "2. Tirar dau de N cares\n";
    cout << "3. Tirar 4 daus de 6 cares\n";
    cout << "4. Tirar dau de 12 cares\n";
    cout << "Tria una opció: ";
    cin >> op;  // Leemos la opción del usuario
    cout << "\n";

    // ---------------------------
    // Opción 1: lanzar un dado de 6 caras (D6)
    // ---------------------------
    if (op == 1) {
        // Llamamos a la función tirarDau con 6 caras y guardamos el resultado
        int v = tirarDau(6);
        // Mostramos el valor obtenido
        cout << "Has tret: " << v << "\n";
        // Dibujamos la representación visual del dado
        mostrarDau(v, 6);

        // ---------------------------
        // Opción 2: lanzar un dado de N caras (personalizado)
        // ---------------------------
    }
    else if (op == 2) {
        // Variable para almacenar el número de caras del dado
        int n;
        cout << "Quantes cares té el dau? ";
        cin >> n;  // Leemos el número de caras del usuario
        // Realizamos la tirada con el número de caras especificado
        int v = tirarDau(n);
        // Mostramos el resultado indicando el tipo de dado (DN)
        cout << "Has tret: " << v << " (D" << n << ")\n";
        // Dibujamos el dado (representación genérica si no es D6)
        mostrarDau(v, n);

        // ---------------------------
        // Opción 3: lanzar 4 dados de 6 caras
        // ---------------------------
    }
    else if (op == 3) {
        cout << "Tirada de 4 daus de 6 cares:\n\n";
        // Bucle para tirar 4 dados
        for (int i = 0; i < 4; i++) {
            // Tiramos cada dado de 6 caras
            int v = tirarDau(6);
            // Mostramos el número del dado (1-4) y su valor
            cout << "Dau " << i + 1 << ": " << v << "\n";
            // Dibujamos cada dado
            mostrarDau(v, 6);
            cout << "\n";  // Separación entre dados
        }

        // ---------------------------
        // Opción 4: lanzar un dado de 12 caras (D12)
        // ---------------------------
    }
    else if (op == 4) {
        // Tiramos un dado de 12 caras
        int v = tirarDau(12);
        // Mostramos el resultado indicando que es un D12
        cout << "Has tret: " << v << " (D12)\n";
        // Dibujamos el dado (se muestra como número ya que no es D6)
        mostrarDau(v, 12);
    }

    // Fin del programa
    return 0;
}