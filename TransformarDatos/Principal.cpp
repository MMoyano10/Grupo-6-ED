/* 
Universidad de las Fuerzas Armadas "Espe"
Programa para: transformar un dato tipo string a un entero, decimal y char
Autores: David Cantuña y Mathius Moyano
Fecha de creacion: 12/05/2022
Fecha de modificacion: 12/05/2022
Version: 1
Nombre Materia: Estructura de Datos
Nrc: 4683
*/

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Ingreso.h"
#include "UnicoIngreso.h"
using namespace std;

int main(int argc, char** argv) {
	string ingreso;
    int opcion;
    bool repetir = true;
    Ingreso ing;
	cout<<"Ingrese el dato que desea transformar: " ;
	cin>>ingreso;
    do {
        cout << "\n\n Transformar numero a: " << endl;
        cout << "1. Entero " << endl;
        cout << "2. Decimal " << endl;
        cout << "3. Caracter " << endl;
        cout << "0. Salir " << endl;
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
				try{
					if(ing.esUnNumero(ingreso)==false){
						throw "El dato ingresado contiene letras o caracteres especiales";
					}
				    cout << ing.convertirDatoEntero(ingreso);
				}catch(const char *error){
					cout << "Error: " << error << endl;
				}
                system("pause>nul"); 
                break;
            case 2:
				try{
					if(ing.esUnNumero(ingreso)==false || ing.esUnFloat(ingreso)==false){
						throw "El dato ingresado contiene letras o mas de dos puntos";
					}
				    cout << ing.convertirDatoDecimal(ingreso);
				}catch(const char *error){
					cout << "Error: " << error << endl;
				}
                system("pause>nul"); 
                break;
            case 3:
            	cout << ing.convertirDatoCaracter(ingreso);
                system("pause>nul");            
                break;   
            case 0:
            	repetir = false;
            	break;
        }        
    } while (repetir);
	return 0; 
}