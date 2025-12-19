#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Función que decide aleatoriamente si un carácter será una "luz" decorativa
char randomLight(char treeChar) {
    // 1 de cada 5 caracteres será una luz (20% de probabilidad)
    if (rand() % 5 == 0) {
        // Array con los diferentes tipos de luces disponibles
        char lights[] = { 'o', '*', '@' };
        // Retorna una luz aleatoria del array
        return lights[rand() % 3];
    }
    // Si no es una luz, retorna el carácter original del árbol
    return treeChar;
}

int main() {
    char cTree;  // Carácter que el usuario elige para dibujar el árbol
    int iSize;   // Altura del árbol

    // Inicializar el generador de números aleatorios con la hora actual
    srand(time(0));

    // Solicitar datos al usuario
    cout << "Christmas Tree Application" << endl;
    cout << "Enter the height of your christmas tree: ";
    cin >> iSize;
    cout << "Enter the character you would like to use for your tree: ";
    cin >> cTree;

    // COPA DEL ÁRBOL - Dibuja un triángulo con la base hacia abajo
    for (int i = 0; i < iSize; i++) {
        // Calcula los espacios necesarios para centrar cada fila
        int spaces = iSize - i - 1;
        // Calcula cuántos caracteres hay en cada fila (aumenta de 1, 3, 5, 7...)
        int chars = (2 * i) + 1;

        // Imprime los espacios de relleno a la izquierda
        cout << string(spaces, ' ');

        // Imprime los caracteres del árbol con posibles luces decorativas
        for (int j = 0; j < chars; j++) {
            cout << randomLight(cTree);
        }
        cout << endl;
    }

    // TRONCO - Dibuja la base rectangular del árbol
    // El ancho del tronco es aproximadamente 1/3 de la altura del árbol
    int trunkWidth = iSize / 3;
    // Asegurar que el ancho del tronco sea impar para centrarlo mejor
    if (trunkWidth % 2 == 0) trunkWidth++;
    // La altura del tronco también es 1/3 de la altura total
    int trunkHeight = iSize / 3;
    // Calcula los espacios para centrar el tronco
    int trunkSpaces = iSize - (trunkWidth / 2) - 1;

    // Dibuja cada línea del tronco
    for (int i = 0; i < trunkHeight; i++) {
        // Espacios para centrar el tronco
        cout << string(trunkSpaces, ' ');
        // Dibuja el tronco con el carácter '|'
        cout << string(trunkWidth, '|') << endl;
    }


    //    _________              .__                
    //    \_   ___ \_____ _______|  |   ____  ______
    //    /    \  \/\__  \\_  __ \  |  /  _ \/  ___/
    //    \     \____/ __ \|  | \/  |_(  <_> )___ \ 
    //     \______  (____  /__|  |____/\____/____  >
    //            \/     \/                      \/ 


    return 0;
}