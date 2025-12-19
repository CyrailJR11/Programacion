#include <iostream>
#include "marcel.h"
#include "carlos.h" // Usas las funciones de Alumne 1
using namespace std;

// Pide al jugador una posición y actualiza el tablero
bool realizarMovimiento(char tablero[3][3], char turno) {
    int fila, columna;

    cout << "Turno del jugador " << turno << endl;
    cout << "Introduce fila (1-3): ";
    cin >> fila;
    cout << "Introduce columna (1-3): ";
    cin >> columna;

    // Validación de entrada
    if (fila < 1 || fila > 3 || columna < 1 || columna > 3) {
        cout << "Posición no válida. Inténtalo otra vez.\n";
        return false;
    }

    // Verificar si la celda está libre
    if (tablero[fila - 1][columna - 1] != ' ') {
        cout << "Esa casilla ya está ocupada. Elige otra.\n";
        return false;
    }

    // Realizar movimiento
    tablero[fila - 1][columna - 1] = turno;
    return true;
}

// Muestra un mensaje según el resultado final
void mostrarMensajeFinal(char ganador) {
    if (ganador == 'E') cout << "¡Empate!\n";
    else cout << "¡El jugador " << ganador << " ha ganado!\n";
}

// Controla todo el flujo del juego
void jugarPartida() {
    char tablero[3][3];
    char turno = 'X';
    bool terminado = false;

    inicializarTablero(tablero);

    while (!terminado) {
        mostrarTablero(tablero);

        // Pedir y validar movimiento
        bool movimientoValido = false;
        do {
            movimientoValido = realizarMovimiento(tablero, turno);
        } while (!movimientoValido);

        // Comprobar si hay ganador
        if (hayGanador(tablero)) {
            mostrarTablero(tablero);
            mostrarMensajeFinal(turno);
            terminado = true;
        }
        // Comprobar si hay empate
        else if (tableroLleno(tablero)) {
            mostrarTablero(tablero);
            mostrarMensajeFinal('E');
            terminado = true;
        }
        // Cambiar turno
        else {
            cambiarTurno(turno);
        }
    }
}
