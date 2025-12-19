#include <iostream>  
using namespace std;
int main() { 
    //Variables
    int edat;
    int anyActual, Naixement;
    int vida, dany;

    //Demana l'edat i indica quan es pot entrar a Instagram
    cout << "Introdueix la teva edat: ";
    cin >> edat; //introduim l'edat

    if (edat >= 14) { //Si l'edat es major que 14 pot entrar a instagram
        cout << "Ja pots tenir Instagram" << endl;
    }
    else {
        cout << "Podras entrar a Instagram d'aqui a " << (14 - edat) << " anys." << endl; //Si es menor de 14 no podra crear la compte 
    }

    cout << "---------------------------------" << endl;
        
    cout << "Introdueix l'any actual: ";
    cin >> anyActual; //Demana l'any actual
    cout << "Introdueix el teu any de naixement: ";
    cin >> Naixement; //Demana la data de naixement 

    edat = anyActual - Naixement; //Calcula l'edat 
    cout << "La teva edat es: " << edat << " anys." << endl; 

    cout << "---------------------------------" << endl;

    //Algoritme de vida del jugador
    cout << "Introdueix la vida actual del jugador: ";
    cin >> vida;
    cout << "Introdueix el dany rebut: ";
    cin >> dany;

    vida = vida - dany; //resta vida amb el dany rebut

    if (vida <= 0) { //if si la vida arriba a 0
        cout << "Game Over" << endl; 
    }
    else {
        cout << "Encara tens " << vida << " punts de vida." << endl; //si te 1 de vida encara pot jugar 
    }

    return 0;
}
