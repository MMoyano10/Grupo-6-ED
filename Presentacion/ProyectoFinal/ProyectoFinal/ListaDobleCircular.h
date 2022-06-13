#pragma once

/***********************************************************************
 * Module:  ListaDobleCircular.h
 * Author:  USER
 * Modified: viernes, 10 de junio de 2022 1:25:56
 * Purpose: Declaration of the class ListaDobleCircular
 ***********************************************************************/

#if !defined(__Class_Diagram_1_ListaDobleCircular_h)
#define __Class_Diagram_1_ListaDobleCircular_h

#include "Nodo.h"


class ListaDobleCircular {
private:
	Nodo* primero;
	Nodo* ultimo;
public:
	ListaDobleCircular();
	void Agregar();
	void Mostrar();
	void Borrar();
	void Buscar();
	void GenerarArchivo();
};


#endif