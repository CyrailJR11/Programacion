#include <iostream>
using namespace std;
int main()
{
	int n1;     //
	int n2;     //
	int sum1;   // Variables 
	int sum2;   //
	int suma3;   //
	string resposta;
	//Ejercicio 1
	srand((unsigned)time(NULL)); //Genera numeros pseudoaleatorios 

	int random = 1 + (rand() % 99); //Genera un numero entre 1 y 99

	n1 = random; //Primer numero 

	random = 1 + (rand() % 99);

	n2 = random; //Segundo numero

	suma3 = n1 + n2; //Suma de ambos numeros

	random = 10 + (rand() % 198);
	sum1 = random;

	random = 10 + (rand() % 198);
	sum2 = random;


	cout << "Cual es el resultado de la suma de " << n1 << " + " << n2 << ". "; //Pregunta en la consola una suma

	//Ejercicio 2
	if (suma3 > sum1)
	{
		if (suma3 > sum2)
		{
			if (sum1 > sum2)
			{
				cout << "\n\nA." << suma3 << " B." << sum1 << " C." << sum2 << "\n\n"; //Opciones a elegir entre los 3 numeros 
				cin >> resposta;
				if (resposta == "a") //Opciones de respuesta
				{
					cout << "Correcto!";
				}
				else
				{
					cout << "Incorrecto";
				}
			}
			else
			{
				cout << "\n\nA." << suma3 << " B." << sum2 << " C." << sum1 << "\n\n"; //Opciones a elegir entre los 3 numeros 
				cin >> resposta;
				if (resposta == "a") //Opciones de respuesta
				{
					cout << "Correcto!";
				}
				else
				{
					cout << "Incorrecto";
				}

			}
		}
		else
		{
			cout << "\n\nA." << sum2 << " B." << suma3 << " C." << sum1 << "\n\n"; //Opciones a elegir entre los 3 numeros 
			cin >> resposta;
			if (resposta == "b") //Opciones de respuesta
			{
				cout << "Correcto!";
			}
			else
			{
				cout << "Incorrecto";
			}
		}

	}
	else if (sum1 > sum2) //Suma los 2 numeros
	{
		if (suma3 > sum2)
		{
			cout << "\n\nA." << sum1 << " B." << suma3 << " C." << sum2 << "\n\n"; //Opciones a elegir entre los 3 numeros 
			cin >> resposta;
			if (resposta == "b") //Opciones de respuesta
			{
				cout << "Correcto!";
			}
			else
			{
				cout << "Incorrecto";
			}
		}
		else
		{
			cout << "\n\nA." << sum1 << " B." << sum2 << " C." << suma3 << "\n\n"; //Opciones a elegir entre los 3 numeros 
			cin >> resposta;
			if (resposta == "c") //Opciones de respuesta
			{
				cout << "Correcto!";
			}
			else
			{
				cout << "Incorrecto";
			}
		}
	}
	else if (sum2 > suma3) //Suma los 2 numeros
	{
		if (sum1 > suma3)
		{
			cout << "\n\nA." << sum2 << " B." << sum1 << " C." << suma3 << "\n\n"; //Opciones a elegir entre los 3 numeros 
			cin >> resposta;
			if (resposta == "c") //Opciones de respuesta
			{
				cout << "Correcto!";
			}
			else
			{
				cout << "Incorrecto";
			}
		}
	}
	//Ejercicio 3
	cout << "\n";
	cout << "Counting forward: \n";
	{
		for (int i = 0; i < 10; i++) { //Muestra los numeros desde el 0 hasta el 9 
			cout << i << " ";
		}
		cout << endl;


	}
	cout << "\n";
	cout << "Counting backward: \n";
	{
		for (int i = 9; i >= 0; i--) { //Muestra los numeros de manera reversa desde el 9 hasta el 0
			cout << i << " ";
		}
		cout << endl;


	}
	cout << "\n";
	cout << "Counting by fives: \n";
	{
		for (int i = 0; i <= 50; i += 5) { //Muestra los numeros de 5 en 5 desde el 0 hasta el 50
			cout << i << " ";
		}
		cout << endl;
	}
	cout << "\n";
	cout << "Counting with null statements: \n";

	{
		int i = 0;
		bool continuar = true; //Comienza el bucle
		while (continuar) {
			cout << i++ << " ";
			if (i == 9) {
				continuar = false; // Detener el bucle después del 9
				break; // Salir del bucle for
			}
		}
		cout << endl;

		// Continuar con la siguiente línea de código
		cout << endl;

	}
	cout << "\n";
	cout << "Counting with nested for loops: \n";
	{
		int X = 5; //Cantidad de filas
		int Y = 3; //Cantidad de columnas


		for (int fila = 0; fila < X; fila++) { //El numero de filas incrementa en 1 mientras sea menor que X
			for (int columna = 0; columna < Y; columna++) { //Numero de columnas que se van a mostrar 
				cout << fila << "," << columna << " "; //Separacion de las filas y columnas por una , 
			}
			cout << endl;
		};
		return 0;
	}
}