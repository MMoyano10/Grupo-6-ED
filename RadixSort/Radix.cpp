#include "Radix.h"

#include <iostream>

void Radix::encerarArreglo(Arreglo vector, int tam) {
	for (int i = 0; i < tam; i++) {
		*(vector.getArreglo() + i) = 0;
	}
}

void Radix::ingresar(Arreglo vector, int tam) {
	int dato = 0;
	for (int i = 0; i < tam; i++) {
		cin >> dato;
		*(vector.getArreglo() + i) = dato;
	}
}

void Radix::imprimirArreglo(Arreglo vector, int tam) {
	for (int i = 0; i < tam; i++) {
		cout << *(vector.getArreglo() + i) << " - ";
	}
}


int Radix::maxm(Arreglo vector, int tam) { // 56,89,451 saber cuantas veces hay que recorrer (3 veces)
	int max = *vector.getArreglo();
	for (int i = 1; i < tam; i++)
	{
		if (*(vector.getArreglo() + i) > max)
		{
			max = *(vector.getArreglo() + i);
		}
	}
	return max;
}

void Radix::rad(Arreglo vector, int tam, int posicion) {
	int* output = new int[tam];   //contener el resultado ordenado
	int count[10];                // llevar cuantas veces se repiten los dijitos y las posiciones(auxiliar) 

	for (int i = 0; i < 10; ++i)  // encerando el vecotr auxiliar
		count[i] = 0;

	// vec = {170, 45, 75, 90, 802, 24, 2, 66}

	for (int i = 0; i < tam; i++)                       // se le suma 1 en el indice correspondiente
		count[(*(vector.getArreglo() + i) / posicion) % 10]++;				// place tiene el valor de 1	
	 // count = {2, 0, 2, 0, 1, 2, 1, 0, 0, 0}

	for (int i = 1; i < 10; i++)       // sumar la posicion actual + la posicion anterior
		count[i] += count[i - 1];
	// count = {2, 2, 4, 4, 5, 7, 8, 8, 8, 8}


   // vec = {170, 45, 75, 90, 802, 24, 2, 66}  derecha a izquierda
	for (int i = tam - 1; i >= 0; i--) {
		output[count[(*(vector.getArreglo() + i) / posicion) % 10] - 1] = *(vector.getArreglo() + i);
		//                              count[66/1] % 10     =  66 
		//                              count[6]-1           =  66 
		//     count = {2, 2, 4, 4, 5, 7, 8, 8, 8, 8}
		//     count = {2, 2, 3, 4, 5, 7, 7, 8, 8, 8}
		//     output = {   ,   ,   ,  2,   ,   ,   , 66}  // posicion 7
		//     output = {170, 90, 802, 2, 24, 45, 75, 66}
		count[(*(vector.getArreglo() + i) / posicion) % 10]--;
	}

	// copiamos los elementos del output al vec
	for (int i = 0; i < tam; i++)
		*(vector.getArreglo() + i) = output[i];
	// vec = {170, 90, 802, 2, 24, 45, 75, 66}
}


void Radix::radixsort(Arreglo vector, int tam) {
	int max = maxm(vector, tam);
	for (int posicion = 1; max / posicion > 0; posicion *= 10)  // por cada ciclo posicion aumenta 1 10 100 ...
		rad(vector, tam, posicion);
}

//  posicion *= 10; subir las unidades, decenas, centenas

//  vec = {170, 90, 802, 2, 24, 45, 75, 66}
//  vec = {802, 2, 24, 45, 66, 170, 75, 90}
//  vec = {2, 24, 45, 66, 75, 90, 170, 802}