#include <iostream>
#include <cstdlib>  //Libreria para rand() 
#include <ctime>    //Libreria Para time()
using namespace std;

int main() {
    cout << "EJERCICIO 1: " << endl;
    //Variables 
    int peus = 0;
    int polzadas = 0;

    cout << "Peus: " << peus << endl;
    cout << "Polzadas: " << polzadas << endl;
    cout << endl;

    cout << "EJERCICIO 2: " << endl;
    //srand para que no genere los mismos numeros y los genere aleatorios 
    srand(time(0));

    //rand que genera los numeros aleatorios
    int var1 = rand();
    int var2 = rand();
    int var3 = rand();
    int var4 = rand();
    int var5 = rand();
    int var6 = rand();

    cout << "var1: " << var1 << endl;
    cout << "var2: " << var2 << endl;
    cout << "var3: " << var3 << endl;
    cout << "var4: " << var4 << endl;
    cout << "var5: " << var5 << endl;
    cout << "var6: " << var6 << endl;
    cout << endl;

    //Conversion Fahrenheit a Celsius
    cout << "EJERCICIO 3: " << endl;
    cout << "Conversion Fahrenheit a Celsius" << endl;
    
    //double para que almacene bien los numeros
    double ftemp, ctemp;

    cout << "Introduce la temperatura en Fahrenheit: ";
    cin >> ftemp;

    //Formula de conversión: ctemp = (ftemp - 32) / 1.8
    ctemp = (ftemp - 32) / 1.8;

    cout << "Temperatura en Fahrenheit: " << ftemp << "°F" << endl;
    cout << "Temperatura en Celsius: " << ctemp << "°C" << endl;

    return 0;
}