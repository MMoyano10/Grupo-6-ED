#include <iostream>
using namespace std;

#include "Nodo.h"

void Nodo::insertarLista(Nodo *&lista, int n){
	Nodo *nuevo_nodo=new Nodo();
	nuevo_nodo->valor = n;
	
	Nodo *i=lista;
	
	if(lista==NULL)
		lista=nuevo_nodo;
	else
	{
		while(i->siguiente!=NULL)
			i=i->siguiente;
		i->siguiente=nuevo_nodo;
	}
	
	cout<<"Elemento "<< n <<" insertado a lista correctamente\n";
}

void Nodo::eliminarLista(Nodo *&lista, int n){
	if(lista != NULL){
		Nodo *aux_borrar;
		Nodo *anterior = NULL;
		
		aux_borrar = lista;
		
		while((aux_borrar != NULL) && (aux_borrar->valor != n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar -> siguiente;
		}
		
		if(aux_borrar == NULL){
			cout << "El elemento no existe" << endl;
		}
		else if(anterior != NULL){
			lista = lista -> siguiente;
			delete aux_borrar;
		}
		else{
			anterior -> siguiente == aux_borrar -> siguiente;
			delete aux_borrar;
		}
	}
}

void Nodo::buscarLista(Nodo *lista, int n){
	bool band = false;
	Nodo *actual = new Nodo();
	actual = lista;
	
	while((actual !=NULL) && (actual->valor <= n)){
		if(actual->valor == n){
			band = true;
		}
		actual = actual->siguiente;
	}
	
	if(band == true){
		cout <<"Elemento: " << n << " a sido encontrado en la lista" << endl;
	}
	else{
		cout <<"Elemento: " << n << " no a sido encontrado en la lista" << endl;
	}
}


void Nodo::mostrarLista(Nodo *lista){
	Nodo *actual = new Nodo();
	
//se iguala ese nuevo nodo(actual) a lsita
	actual = lista;
	
//Se recorre la lista de inicio a fin
	while(actual !=NULL){
		cout<<actual->valor<<" -> ";
		actual = actual->siguiente;
	}
}