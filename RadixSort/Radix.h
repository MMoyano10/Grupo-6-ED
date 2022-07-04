#pragma once
#include "Arreglo.h"

using namespace std;
class Radix {
public:
	void ingresar(Arreglo, int);
	void imprimirArreglo(Arreglo, int);
	void encerarArreglo(Arreglo, int);
	int maxm(Arreglo, int);
	void rad(Arreglo, int , int);
	void radixsort(Arreglo, int);
};