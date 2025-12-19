#pragma once
#ifndef MARCEL_H
#define MARCEL_H

// Ejecuta el juego completo
void jugarPartida();

// Permite al jugador hacer un movimiento (pide fila y columna)
bool realizarMovimiento(char tablero[3][3], char turno);

// Muestra el mensaje final según el resultado
void mostrarMensajeFinal(char ganador);

#endif