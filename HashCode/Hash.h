#pragma once
#include <iostream>
#define tam  7 

class Hash{
private:
	int datos;
	Hash* siguiente;
	Hash* cadena[tam];
public:
	void inicio();
	void ingreso(int valor);
	int busqueda(int valor);
	int eliminar(int valor);
	void impresion();
};

