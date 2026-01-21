#pragma once
#ifndef DAU_H
#define DAU_H


// Dibuja un dado de 6 caras con puntos ASCII
void dibujarDau6(int valor);

// Dibuja un dado genérico para cuando NO es de 6 caras
// (muestra un recuadro con el número)
void dibujarDauGenerico(int valor);

// Selecciona automáticamente qué tipo de dibujo usar
// dependiendo de cuántas caras tenga el dado
void mostrarDau(int valor, int caras);

// Función general para tirar un dado de N caras
int tirarDau(int caras);

#endif
