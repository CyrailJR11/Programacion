#include <iostream>
using namespace std;

int main()
{
	//EXERCICI 1
	//Dibuja un triangulo de asteriscos alineado a la izquierda
	int lineas;
	cout << "¿Numero de lineas?";
	cin >> lineas; //Introduce el número de lineas 

	//Bucle controla el numero de filas (de 0 a lineas-1)
	for (int i = 0; i < lineas; i++) {
		//Imprime asteriscos segun el numero de fila actual
		//En la fila 0 imprime 0 asteriscos, en la fila 1 imprime 1, etc.
		for (int j = 0; j < i; j++) {
			cout << " *"; //Imprime asterisco con espacio delante
		}
		cout << endl; //Salto de línea despues de cada fila
	}

	//EXERCICI 2
	//Dibuja 5 asteriscos por linea
	cout << "Ex 2\n";
	for (int i = 0; i < lineas; i++) {
		//Imprime espacios en blanco para desplazar los asteriscos
		//Cada fila tiene mas espacios que la anterior
		for (int j = 0; j < lineas - i - 1; j++) {
			cout << " ";
		}
		//Siempre imprime exactamente 5 asteriscos por linea
		for (int j = 0; j < 5; j++) {
			cout << "*";
		}
		cout << endl;
	}

	//EXERCICI 3
	int i, x;
	cout << "Numero de Filas" << endl;

	//Bucle externo: recorre las filas de 1 a lineas
	for (i = 1; i <= lineas; ++i) {
		//Imprime espacios para alinear a la derecha
		//Los espacios disminuyen conforme avanzamos en las filas
		for (int x = i; x <= lineas; ++x) {
			cout << " ";
		}
		//Controla las columnas de asteriscos
		for (int x = 1; x <= lineas; ++x) {
			// Solo imprime asterisco si estamos en:
			// - La última fila (i == lineas) - base del triangulo
			// - La primera columna (x == 1) - lado izquierdo
			// - La diagonal (x == i)
			if (i == lineas || x == 1 || x == i) {
				cout << "*";
			}
			else {
				cout << " "; //Espacios internos (el "hueco" del triangulo)
			}
		}
		cout << "\n";
	}

	//EXERCICI 4
	//Triangulo creciente (igual que ejercicio 1)
	for (int i = 0; i < lineas; i++) {
		for (int j = 0; j < i; j++) {
			cout << " *";
		}
		cout << endl;
	}
	//Triangulo decreciente (invertido)
	//Empieza con lineas asteriscos y va disminuyendo hasta 1
	for (int i = lineas; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			cout << " *";
		}
		cout << endl;
	}

	//EXERCICI 5
	for (int j = 0; j < lineas; ++j) {
		//Imprime espacios para centrar la piramide
		//Los espacios disminuyen conforme subimos
		for (int i = 0; i < lineas - j - 1; ++i)
			cout << " ";
		//Imprime asteriscos
		for (int i = 0; i < 2 * j + 1; ++i)
			cout << "*";
		cout << endl;
	}
	//piramide decreciente (mitad inferior del rombo)
	//Empieza desde la penultima fila (lineas-2) y va descendiendo hasta 0
	for (int j = lineas - 2; j >= 0; --j) {
		//Espacios para centrar
		for (int i = 0; i < lineas - j - 1; ++i)
			cout << " ";
		//Asteriscos decrecientes misma formula (2*j + 1)
		for (int i = 0; i < 2 * j + 1; ++i)
			cout << "*";
		cout << endl;
	}

	return 0;
}
