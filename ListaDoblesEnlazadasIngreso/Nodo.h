#include <iostream>
using namespace std;

class Nodo{
	private:
		int valor;
		Nodo *siguiente;
	public:
		Nodo(int v, Nodo*sig=NULL){
			this->valor = v;
			this->siguiente = sig;
		}
		Nodo();
	friend class Lista;
};