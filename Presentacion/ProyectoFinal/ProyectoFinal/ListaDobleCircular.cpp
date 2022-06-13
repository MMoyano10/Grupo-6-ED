#include <iostream>
#include <fstream>

/***********************************************************************
 * Module:  ListaDobleCircular.cpp
 * Author:  USER
 * Modified: viernes, 10 de junio de 2022 1:25:56
 * Purpose: Implementation of the class ListaDobleCircular
 ***********************************************************************/

#include "ListaDobleCircular.h"
 /***********************************************************************
  * Module:  ListaDobleCircular.cpp
  * Author:  USER
  * Modified: viernes, 10 de junio de 2022 1:25:56
  * Purpose: Implementation of the class Validaciones
  ***********************************************************************/

#include "Validaciones.h"

Validaciones val;

using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::ListaDobleCircular()
// Purpose:    Implementation of ListaDobleCircular::ListaDobleCircular()
// Return:     
////////////////////////////////////////////////////////////////////////

ListaDobleCircular::ListaDobleCircular()
{
	primero = NULL;
	ultimo = NULL;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::Agregar()
// Purpose:    Implementation of ListaDobleCircular::Agregar()
// Return:     void
////////////////////////////////////////////////////////////////////////
void ListaDobleCircular::Agregar()
{
	Nodo* nuevo = new Nodo();
	cout << "\t\t\t-------------------" << endl;
	cout << "\t\t\t|REGISTRO DE DATOS|" << endl;
	cout << "\t\t\t-------------------" << endl;
	cout << endl;

	do {
		cin.clear();
		rewind(stdin);
		cout << "\t\t|NOMBRE CLIENTE: ";
		cin.getline(nuevo->nombreCliente, 30);
	} while (val.ValidarCadenas(nuevo->nombreCliente) != 0);

	do {
		cin.clear();
		rewind(stdin);
		cout << "\t\t|CEDULA CLIENTE: ";
		cin.getline(nuevo->cedulaCliente, 30);
	} while ((val.ValidarCedulaEc(nuevo->cedulaCliente)==false));
	
	do {
		cin.clear();
		rewind(stdin);
		cout << "\t\t|MARCAR AUTO: ";
		cin.getline(nuevo->marcaA, 30);
	} while (val.ValidarCadenas(nuevo->marcaA) != 0);

	do {
		cin.clear();
		rewind(stdin);
		cout << "\t\t|NUMERO DE PLACA (AAA1234):  ";
		cin.getline(nuevo->placaA, 30);
	} while ((val.ValidarMatriculaEc(nuevo->placaA)) == false);

	do {
		cin.clear();
		rewind(stdin);
		cout << "\t\t|FECHA DE INGRESO (DD/MM/AA):  ";
		cin.getline(nuevo->fechaIngreso, 30);
	} while ((val.ValidarFecha(nuevo->fechaIngreso)) == false);
	
	if (primero == NULL) {
		primero = nuevo;
		ultimo = nuevo;
		primero->siguiente = primero;
		primero->anterior = ultimo;
	}
	else {
		ultimo->siguiente = nuevo;
		nuevo->anterior = ultimo;
		nuevo->siguiente = primero;
		ultimo = nuevo;
		primero->anterior = ultimo;
	}
}


////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::Mostrar()
// Purpose:    Implementation of ListaDobleCircular::Mostrar()
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::Mostrar()
{
	Nodo* actual = new Nodo();
	actual = primero;

	if (primero == NULL) {
		cout << "\t\tNO HAY AUTOS REGISTRADOS" << endl;
	}
	else {


		cout << "\t\t\t--------------------------" << endl;
		cout << "\t\t\t|      REGISTROS         |" << endl;
		cout << "\t\t\t--------------------------" << endl;
		do {
			cout << endl;
			cout << "\t\t--------------------------------------------" << endl;
			cout << "\t\tNOMBRE DEL PROPIETARIO:   " << actual->nombreCliente << endl;
			cout << "\t\tNUMERO DE CEDULA:         " << actual->cedulaCliente << endl;
			cout << "\t\tMARCA DEL AUTO:           " << actual->marcaA << endl;
			cout << "\t\tNUMERO DE PLACA:          " << actual->placaA << endl;
			cout << "\t\tFECHA DE INGRESO:         " << actual->fechaIngreso << endl;
			cout << "\t\t--------------------------------------------" << endl;
			actual = actual->siguiente;
		} while (actual != primero);

	}
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::Borrar()
// Purpose:    Implementation of ListaDobleCircular::Borrar()
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::Borrar()
{
	Nodo* actual = new Nodo();
	actual = primero;
	Nodo* antr = new Nodo();
	antr = NULL;

	bool encontrado = false;

	char nodoBuscado[20];
	fflush(stdin);
	cout << "INGRESE EL NOMBRE DEL CLIENTE: ";
	cin.getline(nodoBuscado, 20);
	fflush(stdin);
	if (primero != NULL) {
		do {
			if (strcmp(actual->nombreCliente, nodoBuscado) == 0) {
				cout << "\n EL CLIENTE ( " << nodoBuscado << " ) HA SIDO ENCONTRADO";
				if (actual == primero) {
					primero = primero->siguiente;
					primero->anterior = ultimo;
					ultimo->siguiente = primero;
				}
				else if (actual == ultimo) {
					ultimo = antr;
					ultimo->siguiente = primero;
					primero->anterior = ultimo;
				}
				else {
					antr->siguiente = actual->siguiente;
					actual->siguiente->anterior = antr;
				}
				cout << "\n EL REGISTRO SE ELIMINO CON EXITO \n\n";
				encontrado = true;
			}
			antr = actual;
			actual = actual->siguiente;
		} while (actual != primero && encontrado != true);

		if (!encontrado) {
			cout << "\n CLIENTE NO ENCONTRADO \n\n";
		}
	}
	else {
		cout << "\n LA LISTA SE ENCUENTRA VACIA \n\n";
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::Buscar()
// Purpose:    Implementation of ListaDobleCircular::Buscar()
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::Buscar()
{
	Nodo* recor = new Nodo();
	recor = primero;
	char opcionBuscar[2];
	int convertir;

	if (primero == NULL) {
		cout << "\t\t NO EXISTEN REGISTROS " << endl;
	}
	else {
		cout << "\t\t\t---------------------------" << endl;
		cout << "\t\t\t  |BUSQUEDA DE REGISTROS|" << endl;
		cout << "\t\t\t---------------------------" << endl;
		cout << "\n\n";

		cout << "\t\t-----------------------------" << endl;
		cout << "\t\tPOR MARCA AUTO.................[1]" << endl;
		cout << "\t\tPOR PLACA AUTO.................[2]" << endl;
		cout << "\t\t-----------------------------" << endl;
		cout << "\t\tINGRESE LA OPCION:";
		cin >> opcionBuscar;

		convertir = atoi(opcionBuscar);

		system("cls");
		switch (convertir) {
		case 1:
			char nombre[30];
			cout << "\t\t\t--------------------------" << endl;
			cout << "\t\t\t|      REGISTROS         |" << endl;
			cout << "\t\t\t--------------------------" << endl;
			cout << "\t\tNOMBRE: ";
			fflush(stdin);
			cin.getline(nombre, 30);
			fflush(stdin);
			do {
				if (strcmp(recor->marcaA, nombre) == 0) {
					cout << endl;
					cout << "\t\t*********************************" << endl;
					cout << "\t\tNOMBRE DEL PROPIETARIO:   " << recor->nombreCliente << endl;
					cout << "\t\tNUMERO DE CEDULA:         " << recor->cedulaCliente << endl;
					cout << "\t\tMARCA DEL AUTO:           " << recor->marcaA << endl;
					cout << "\t\tNUMERO DE PLACA:          " << recor->placaA << endl;
					cout << "\t\tFECHA DE INGRESO:         " << recor->fechaIngreso << endl;
					cout << "\t\t*********************************" << endl;
				}
				recor = recor->siguiente;
			} while (recor != primero);
			break;

		case 2:
			char apellidos[20];
			cout << "\t\t\t--------------------------" << endl;
			cout << "\t\t\t|      REGISTROS         |" << endl;
			cout << "\t\t\t--------------------------" << endl;
			cout << "\t\tPLACA: ";
			fflush(stdin);
			cin.getline(apellidos, 20);
			fflush(stdin);
			do {
				if (strcmp(recor->placaA, apellidos) == 0) {
					cout << endl;
					cout << "\t\t*********************************" << endl;
					cout << "\t\tNOMBRE DEL PROPIETARIO:   " << recor->nombreCliente << endl;
					cout << "\t\tNUMERO DE CEDULA:         " << recor->cedulaCliente << endl;
					cout << "\t\tMARCA DEL AUTO:           " << recor->marcaA << endl;
					cout << "\t\tNUMERO DE PLACA:          " << recor->placaA << endl;
					cout << "\t\tFECHA DE INGRESO:         " << recor->fechaIngreso << endl;
					cout << "\t\t*********************************" << endl;
				}
				recor = recor->siguiente;
			} while (recor != primero);
			break;
		}
	}
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::GenerarArchivo()
// Purpose:    Implementation of ListaDobleCircular::GenerarArchivo()
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::GenerarArchivo()
{
	Nodo* actual = new Nodo();
	actual = primero;

	ofstream archivo;
	archivo.open("registro.txt", ios::out);

	if (archivo.fail()) {
		cout << "NO SE PUDO GENERAR EL ARCHIVO";
		return;
	}

	if (primero == NULL) {
		cout << "\t\tNO HAY AUTOS REGISTRADOS" << endl;
	}
	else {
		archivo << "\t\t\t--------------------------" << endl;
		archivo << "\t\t\t|      REGISTROS         |" << endl;
		archivo << "\t\t\t--------------------------" << endl;
		do {
			archivo << endl;
			archivo << "\t\t--------------------------------------------" << endl;
			archivo << "\t\tNOMBRE DEL PROPIETARIO:   " << actual->nombreCliente << endl;
			archivo << "\t\tNUMERO DE CEDULA:         " << actual->cedulaCliente << endl;
			archivo << "\t\tMARCA DEL AUTO:           " << actual->marcaA << endl;
			archivo << "\t\tNUMERO DE PLACA:          " << actual->placaA << endl;
			archivo << "\t\tFECHA DE INGRESO:         " << actual->fechaIngreso << endl;
			archivo << "\t\t--------------------------------------------" << endl;
			actual = actual->siguiente;
		} while (actual != primero);
	}
}
