#include <iostream>
#include "TorreHanoi.h"
#include "Ingreso.h"
using namespace std;

int main(int argc, char** argv) {
	torreHanoi th;
	Ingreso ing;
	string ingreso;
	bool bandera = false;
	while(bandera == false){
		cout<<"Ingrese el numero de discos que desea para jugar: " ;
		cin>>ingreso;
		try{
			if(ing.esUnNumero(ingreso)==false){
				throw "El dato ingresado no es un numero entero";
			}
			bandera = true;
			int n = ing.convertirDatoEntero(ingreso);
			th.movimientos(n, 'A', 'B', 'C');
		}catch(const char *error){
			cout << "Error: " << error << endl;
		}
	}
	return 0;
}

