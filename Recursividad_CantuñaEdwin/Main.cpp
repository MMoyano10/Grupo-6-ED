/* 
Universidad de las Fuerzas Armadas "Espe"
Programa: Utilizacion de recursividad para el calculo del factorial de un numero entero y la suma del mismo
Autor: Edwin David Cantuña Morales 
Fecha de creacion: 16/05/2022
Fecha de modificacion: 16/05/2022
Version: 1
Nombre Materia: Estructura de Datos
Nrc: 4683
*/

#include <iostream>
#include "Factorial.h"
#include "Suma.h"
#include "Ingreso.h"
using namespace std;

int main(int argc, char** argv) {
	Factorial ftl;
	Suma sum;
	Ingreso ing;
	string ingreso;
	bool bandera = false;
	while(bandera == false){
		cout<<"Ingrese un dato numerico de tipo entero: " ;
		cin>>ingreso;
		try{
			if(ing.esUnNumero(ingreso)==false){
				throw "El dato ingresado contiene letras o caracteres especiales";
			}
			bandera = true;
			int n = ing.convertirDatoEntero(ingreso);
			for(int i=1;i<=n;i++){
				cout<< "\nSuma = " <<sum.suma(i);
				cout<< "\t\t Factorial = " << ftl.factorial(i);
			}
		}catch(const char *error){
			cout << "Error: " << error << endl;
		}
	}
	return 0;
}

