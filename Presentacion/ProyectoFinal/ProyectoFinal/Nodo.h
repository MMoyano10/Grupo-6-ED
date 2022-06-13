/***********************************************************************
 * Module:  Nodo.h
 * Author:  USER
 * Modified: viernes, 10 de junio de 2022 1:25:20
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#pragma once
#include <iostream>

#if !defined(__Class_Diagram_1_Nodo_h)
#define __Class_Diagram_1_Nodo_h

class Nodo {
private:
	char nombreCliente[30];
	char cedulaCliente[30];
	char fechaIngreso[30];
	char marcaA[30];
	char placaA[30];
	Nodo* siguiente;
	Nodo* anterior;

friend class ListaDobleCircular;
};

#endif