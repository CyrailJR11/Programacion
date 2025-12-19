#pragma once

#include <iostream>
using namespace std;
// Inicializa el tablero vacío (' ')
void inicializarTablero(char tablero[3][3]);

// Muestra el tablero por pantalla
void mostrarTablero(char tablero[3][3]);

// Cambia el turno actual ('X' -> 'O' o 'O' -> 'X')
void cambiarTurno(char& turno);

// Comprueba si hay un ganador
bool hayGanador(char tablero[3][3]);

// Comprueba si el tablero está lleno (empate)
bool tableroLleno(char tablero[3][3]);

