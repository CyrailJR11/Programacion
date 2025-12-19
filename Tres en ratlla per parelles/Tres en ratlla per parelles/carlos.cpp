#include "carlos.h"      // Incluye el archivo de cabecera "carlos.h" (probablemente con funciones o definiciones del proyecto)
#include "marcel.h"      // Incluye el archivo de cabecera "marcel.h" (igual, con funciones o estructuras adicionales)
#include <iostream>      // Biblioteca estándar para entrada y salida (permite usar cout y cin)
using namespace std;     // Permite usar nombres estándar (cout, endl, etc.) sin prefijo std::

// ------------------------------------------------------------
// Función: inicializarTablero
// Objetivo: Rellena el tablero 3x3 con espacios vacíos
// ------------------------------------------------------------
void inicializarTablero(char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {          // Recorre las filas del tablero
        for (int j = 0; j < 3; j++) {      // Recorre las columnas del tablero
            tablero[i][j] = ' ';           // Asigna un espacio en blanco a cada celda
        }
    }
}

// ------------------------------------------------------------
// Función: mostrarTablero
// Objetivo: Muestra el tablero actual por pantalla
// ------------------------------------------------------------
void mostrarTablero(char tablero[3][3]) {
    cout << "\n";                          // Imprime una línea en blanco antes del tablero
    for (int i = 0; i < 3; i++) {          // Recorre las filas del tablero
        cout << " ";                       // Espaciado inicial de la fila
        for (int j = 0; j < 3; j++) {      // Recorre las columnas
            cout << tablero[i][j];         // Muestra el valor de la celda (X, O o vacío)
            if (j < 2) cout << " | ";      // Si no es la última columna, imprime separadores verticales
        }
        cout << "\n";                      // Salta a la siguiente línea al final de la fila
        if (i < 2) cout << "---+---+---\n"; // Dibuja líneas divisorias entre filas (excepto la última)
    }
    cout << "\n";                          // Línea en blanco al final del tablero
}

// ------------------------------------------------------------
// Función: cambiarTurno
// Objetivo: Cambia el turno entre los jugadores 'X' y 'O'
// ------------------------------------------------------------
void cambiarTurno(char& turno) {
    if (turno == 'X') turno = 'O';         // Si el turno actual es 'X', pasa a 'O'
    else turno = 'X';                      // Si el turno actual es 'O', pasa a 'X'
}

// ------------------------------------------------------------
// Función: hayGanador
// Objetivo: Comprueba si algún jugador ha ganado el juego
// ------------------------------------------------------------
bool hayGanador(char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {          // Recorre filas y columnas
        // --- Comprobación de filas ---
        if (tablero[i][0] != ' ' &&        // Si la primera celda de la fila no está vacía
            tablero[i][0] == tablero[i][1] &&  // Y las tres celdas son iguales
            tablero[i][1] == tablero[i][2])
            return true;                   // Entonces hay un ganador en esa fila

        // --- Comprobación de columnas ---
        if (tablero[0][i] != ' ' &&        // Si la primera celda de la columna no está vacía
            tablero[0][i] == tablero[1][i] &&  // Y las tres celdas son iguales
            tablero[1][i] == tablero[2][i])
            return true;                   // Entonces hay un ganador en esa columna
    }

    // --- Comprobación de diagonales ---
    if (tablero[0][0] != ' ' &&            // Diagonal principal (de arriba izquierda a abajo derecha)
        tablero[0][0] == tablero[1][1] &&
        tablero[1][1] == tablero[2][2])
        return true;                       // Hay un ganador en la diagonal principal

    if (tablero[0][2] != ' ' &&            // Diagonal secundaria (de arriba derecha a abajo izquierda)
        tablero[0][2] == tablero[1][1] &&
        tablero[1][1] == tablero[2][0])
        return true;                       // Hay un ganador en la diagonal secundaria

    return false;                          // Si ninguna condición se cumple, no hay ganador
}

// ------------------------------------------------------------
// Función: tableroLleno
// Objetivo: Comprueba si el tablero está completamente lleno
// (indica un empate si no hay ganador)
// ------------------------------------------------------------
bool tableroLleno(char tablero[3][3]) {
    for (int i = 0; i < 3; i++) {          // Recorre las filas
        for (int j = 0; j < 3; j++) {      // Recorre las columnas
            if (tablero[i][j] == ' ')      // Si encuentra una celda vacía
                return false;               // El tablero no está lleno
        }
    }
    return true;                           // Si no hay espacios vacíos, el tablero está lleno
}
