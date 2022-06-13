#include "TorreHanoi.h"
#include <iostream>
using namespace std;

void torreHanoi::movimientos(int elementos, char a, char b, char c){
	if(elementos > 0){
		movimientos(elementos-1,a,c,b);
		cout << "Mover el disco: " << elementos << " de la barra: " << a << " hasta la: " << c << endl;
		movimientos(elementos-1,b,a,c);
	}
}
