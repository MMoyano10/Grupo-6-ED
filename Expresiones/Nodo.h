#include <iostream>

class Nodo{
	private:
		char simbolo;
		Nodo *siguiente;
	public:
		void push(Nodo *&pila, char s);
		char pop(Nodo *&pila);
		int pila_vacia(Nodo *&pila);
};