#include <iostream>
using namespace std;

#include "Nodo.h"


int main(int argc, char** argv) {
	Nodo *lista = NULL;
	Nodo n;
	int dato;
	char rpt;
	
	int op;
	
	do{
		cout<< "\n\t .:MENU:." <<endl;
		cout<<"1. Insertar elemento en la lista"<< endl;
		cout<<"2. Mostrar elementos de la lista"<< endl;
		cout<<"3. Eliminar elemento de la lista"<< endl;
		cout<<"3. Buscar elemento de un lista"<< endl;
		cout<<"4. Salir"<< endl;
		cout<<"Opcion: "<< endl;
		cin>>op;
		system("CLS");
		switch(op){
			case 1: 
				cout<<"\n Dijite un numero: "<<endl;
				cin>>dato;
				n.insertarLista(lista,dato);
				break;
			case 2:
				n.mostrarLista(lista);
				break;
			case 3:
				cout<<"\n Dijite el numero que desea eliminar: "<<endl;
				cin>>dato;
				n.eliminarLista(lista,dato);
				break;
			case 4:
				cout<<"\n Dijite el numero que desea buscar: "<<endl;
				cin>>dato;
				n.buscarLista(lista,dato);
				break;
		}
	}while(op != 4);
	

	return 0;
}