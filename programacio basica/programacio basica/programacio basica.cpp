#include <iostream>
using namespace std;

int main() {
    //Declaracio del jugadors amb char
    char jugadors[3][10] = { "Anna", "Marc", "Joan" };
    int puntuacions[3] = { 50, 70, 60 };

    //Buscar el guanyador i declara la puntuació
    int maxPunts = puntuacions[0];
    int Guanyador = 0;

    //Guanyador amb maxim de punts 
    for (int i = 1; i < 3; i++) { //mentre i sigui menor que 3 el bucle continuara i comprova les posicion 1, 2 i 3 i despres i aumenta en +1
        if (puntuacions[i] > maxPunts) { //Puntuacio actual mayor que la maxima 
            maxPunts = puntuacions[i]; //Actualitza la puntuació
            Guanyador = i;  //Guanyador
        }
    }

    //Mostrar resultat amb el jugador amb mes punts 
    cout << "Guanyador: " << jugadors[Guanyador]
        << " amb " << maxPunts << " punts." << endl;

    return 0;
}


