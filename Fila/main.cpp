#include <iostream>
#include "Lista.h"
using namespace std;
int main(int argc, char** argv) {
	Lista lst;
	
	lst.Insertar(1);
	lst.Insertar(3);
	lst.Insertar(100);
	lst.Insertar(5);
	lst.Insertar(6);
	lst.Mostrar();
	return 0;
};
