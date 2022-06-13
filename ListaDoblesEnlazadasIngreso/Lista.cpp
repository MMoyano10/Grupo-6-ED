#include "Lista.h"
#include <iostream>
using namespace std;

bool Lista::listaVacia(){
	return (this->primero == NULL);	
}

void Lista::insertarInicio(int v){
	Nodo *nuevo = new Nodo(v);
	nuevo -> siguiente = primero;
	primero = nuevo;
}

void Lista::insertarFinal(int v){
	Nodo *nuevo = new Nodo(v);
	if (listaVacia()){
		this->primero = nuevo;
	}
	else{
		this->actual->siguiente  = nuevo;
	}
	this->actual = nuevo;	
}

void Lista::eliminarNodo(int v){
	Nodo *actual = primero;
	Nodo *anterior = NULL;
	
	while((actual != NULL) && (actual->valor != v)){
		anterior = actual;
		actual = actual -> siguiente;
	}
		
	if(actual == NULL){
		cout << "El elemento no se encuentra en la lista" << endl;
	}
	else{
		if(primero == actual){
			primero = actual -> siguiente;
		}
		else{
			anterior -> siguiente = actual -> siguiente;
			delete actual;
		}
	}
}

void Lista::buscarElemento(int v){
	bool band = false;
	
	Nodo *actual = primero;
	Nodo *anterior = NULL;
	
	while((actual != NULL) && (actual->valor != v)){
		anterior = actual;
		actual = actual -> siguiente;
	}
		
	if(actual == NULL){
		cout << "El nodo: " << v << " no esta en la lista" << endl;
	}
	else{
		if(primero == actual){
			primero = actual -> siguiente;
		}
		else{
			anterior -> siguiente = actual -> siguiente;
			cout << "El nodo: " << v << " esta en la lista" << endl;
		}
	}
} 	

void Lista::mostrar(){
	Nodo *tmp = this ->primero;
	while (tmp) {
		cout << tmp->valor << "--->";
		tmp = tmp->siguiente;		
	}
	cout << "NULL\n";
}
