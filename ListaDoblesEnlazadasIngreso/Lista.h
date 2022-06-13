#include "Nodo.h"
#include <iostream>
using namespace std;

class Lista{
	private:
		Nodo *primero;
		Nodo *actual;
		
	public:
		Lista(){
			this ->primero = NULL;
			this->actual = NULL;				
		}
		
		void insertarInicio(int v);
		void insertarFinal(int v);
		void eliminarNodo(int v);
		void buscarElemento(int v);
		void mostrar();
		bool listaVacia();
};