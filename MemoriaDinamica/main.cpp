#include <iostream>
#include "Arreglo.h"
using namespace std;

int main(int argc, char** argv) {
	int tamanio, e;
	cout<<"Ingrese el tamanio del arreglo: ";
	cin >> tamanio;
	//cout<<"Ingrese el dato con el que se procesara: ";
	//cin >> e;
	int *vector = new int[tamanio];
	Arreglo proceso;
	//proceso.encerar(vector, tamanio);
	//proceso.imprimir(vector, tamanio);
	cout<<endl;
	cout<<"Ingrese los datos: "<<endl;
	proceso.ingresar(vector, tamanio);
	cout<<endl;
	proceso.imprimir(vector, tamanio);
	//proceso.procesar(vector, tamanio, e);
	cout<<endl;
	//proceso.imprimir(vector, tamanio);
	proceso.ordenamientoRadix(vector, tamanio);
	cout<<endl;
	proceso.imprimir(vector, tamanio);
	return 0;
}