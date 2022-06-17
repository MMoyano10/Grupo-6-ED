#include "Nodo.h"
#include <iostream>
using namespace std;

void Nodo::push(Nodo *&pila, char s){
	Nodo *nodo = new Nodo();
	if(nodo != NULL){
		nodo->simbolo = s;
		nodo->siguiente = pila;
		pila = nodo;
	}
}

char Nodo::pop(Nodo *&pila){
	Nodo *nodo;
	char s;
	nodo = pila;
	s = (pila)->simbolo;
	pila = (pila)->siguiente;
	free(nodo);
	return s;
}

int Nodo::pila_vacia(Nodo *&pila){
	return (pila == NULL ? 1:0);
}

