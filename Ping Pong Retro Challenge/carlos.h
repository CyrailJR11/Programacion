#pragma once
#ifndef CARLOS_H
#define CARLOS_H
#include <SFML/Graphics.hpp>

// Estructura de la pala
// Define el tipo de dato personalizado que representa una pala del juego
struct Pala {
    // Forma rectangular de SFML que representa visualmente la pala
    sf::RectangleShape forma;

    // Velocidad de movimiento de la pala en píxeles por segundo
    float velocidad;
};

// Declaración de funciones (prototipos)

// Inicialización
// Configura los valores iniciales de una pala en la posición (x, y)
void inicializarPala(Pala& pala, float x, float y);

// Movimiento
// Mueve la pala verticalmente según el tiempo transcurrido (deltaTime) y la dirección (subir)
// Respeta los límites superior e inferior de la pantalla
void moverPala(Pala& pala, float deltaTime, bool subir,
    float limiteSuperior, float limiteInferior);

// Dibujo
// Renderiza la pala en la ventana de SFML especificada
void dibujarPala(sf::RenderWindow& window, Pala& pala);

// Fin de la guarda de inclusión
#endif