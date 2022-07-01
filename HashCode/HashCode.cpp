#include <iostream>
#include "Hash.h"
#include "Validacion.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <cstring>
#include <istream>
using namespace std;

int menu();

int main() {

	Hash objt;
	Validacion v;
	objt.inicio();
	int opc, dim;
	char val[10];
	do {
		system("cls");
		opc = menu();
		switch (opc)
		{
		case 1: {
			char* mensaje = (char*)"\nIngrese un valor: ";
			strcpy_s(val, v.ingresarDato(mensaje));
			dim = atoi(val);
			objt.ingreso(dim);
			cout << endl;
			break;
		}
		case 2: {
			char* mensaje = (char*)"\nIngrese el valor que desea buscar: ";
			strcpy_s(val, v.ingresarDato(mensaje));
			dim = atoi(val);
			cout << endl;
			if (objt.busqueda(dim)) {
				cout << "El valor ha sido encontrado" << endl;
			}
			else {
				cout << "Valor no encontrado" << endl;
			};
			break;
		}
		case 3: {
			char* mensaje = (char*)"\nIngrese el valor que desea eliminar: ";
			strcpy_s(val, v.ingresarDato(mensaje));
			dim = atoi(val);
			cout << endl;
			if (objt.eliminar(dim)) {
				cout << "Despues de la eliminacion" << endl;
				objt.impresion();
			}
			else {
				cout << "Valor no encontrado" << endl;
			};
			break;
		}
		case 4: {
			objt.impresion();
			break;
		}
		case 0: {
			cout << "\nAdios, Gracias por usar el programa :D " << endl;
			break;
		}
		default: {
			cout << "\nError. Opcion incorrecta" << endl;
			break;
		}
		}
		system("pause");
	} while (opc != 0);

	return 0;
}

int menu()
{
	int opc;
	cout << "\n****************************MENU****************************\n" << endl
		<< "1. Ingresar un elemento a la tabla" << endl
		<< "2. Buscar un elemento en la tabla" << endl
		<< "3. Eliminar un elemento en la tabla" << endl
		<< "4. Imprimir tabla" << endl
		<< "0. Salir" << endl
		<< "\nEscoja una opcion: ";
	cin >> opc;
	return opc;
}