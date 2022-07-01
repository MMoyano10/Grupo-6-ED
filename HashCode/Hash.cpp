#include "Hash.h"
#include <iostream>
using namespace std;

void Hash::inicio() {
	int i;
	for (i = 0; i < tam; i++) {
		cadena[i] = nullptr;
	}
}

void  Hash::ingreso(int valor) {

	// Creacion de un nuevo nodo con el valor
	Hash* nuevoNodo = new Hash();
	nuevoNodo->datos = valor;
	nuevoNodo->siguiente = nullptr;

	// Calculo clave
	int clave = valor % tam;

	// Comprueba si la cadena [clave] esta vacia
	if (cadena[clave] == nullptr) {
		cadena[clave] = nuevoNodo;
		//Ccolision
	}
	else {
		// Agregar el nodo al final de la cadena [clave]d
		Hash* temp = cadena[clave];
		while (temp->siguiente) {
			temp = temp->siguiente;
		}

		temp->siguiente = nuevoNodo;

	}

}

int Hash::busqueda(int valor) {
	int clave = valor % tam;
	Hash* temp = cadena[clave];
	while (temp) {
		if (temp->datos == valor) {
			return 1;
		}
		temp = temp->siguiente;
	}
	return 0;
}

int  Hash::eliminar(int valor) {
	int clave = valor % tam;
	Hash* temp = cadena[clave], * nuevo;
	if (temp != nullptr) {
		if (temp->datos == valor) {
			nuevo = temp;
			temp = temp->siguiente;
			free(nuevo);
			return 1;
		}
		else {
			while (temp->siguiente) {
				if (temp->siguiente->datos == valor) {
					nuevo = temp->siguiente;
					temp->siguiente = temp->siguiente->siguiente;
					free(nuevo);
					return 1;
				}
				temp = temp->siguiente;
			}
		}
	}
	return 0;
}


void  Hash::impresion() {
	int i;
	for (i = 0; i < tam; i++) {
		Hash* temp = cadena[i];
		cout << "cadena [" << i << "] -> ";
		while (temp) {
			cout << temp->datos << " -> ";
			temp = temp->siguiente;
		}
		cout << "NULL  " << endl;
	}
}