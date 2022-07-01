#include <iostream>
#include "Radix.h"
using namespace std;

int main()
{
	Radix proceso;
	Arreglo vector;
	int tamanio;

	cout << "INGRESE EL TAMANIO DEL ARREGLO: ";
	cin >> tamanio;
	vector.setArreglo(new int[tamanio]);
	proceso.encerarArreglo(vector, tamanio);
	cout << endl;
	cout << "INGRESE LOS DATOS: " << endl;
	proceso.ingresar(vector, tamanio);
	cout << "INGRESADO: " << endl;
	proceso.imprimirArreglo(vector, tamanio);
	cout << endl;
	cout << "ORDENAMIENTO RADIX: " << endl;
	proceso.radixsort(vector, tamanio);
	proceso.imprimirArreglo(vector, tamanio);
}

