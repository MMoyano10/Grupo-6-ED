#include <iostream>
#include "Lista.h"
#include "Ingreso.h"
using namespace std;

int main(int argc, char** argv) {
	Lista lst;
	int valor;
	string ingreso, bandera;
    int opcion;
    bool repetir = true, continuar = true;
    Ingreso ing;
    do {
        cout << "\n\n Menu " << endl;
        cout << "1. Insertar un elemento lista " << endl;
        cout << "2. Insertar un elemento al inicio de la lista " << endl;
        cout << "3. Eliminar elemento de la lista " << endl;
        cout << "4. Buscar elemento de la lista " << endl;
        cout << "5. Mostrar lista " << endl;
        cout << "0. Salir " << endl;
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 2:
				do{
					cout << "Dijite el numero: " << endl;
					cin >> ingreso;
					try{
						if(ing.esUnNumero(ingreso)==false){
							throw "El dato ingresado contiene letras o caracteres especiales";
						}
				    	valor = ing.convertirDatoEntero(ingreso);
				    	lst.insertarInicio(valor);
					}catch(const char *error){
						cout << "Error: " << error << endl;
					}
					cout << "¿Desea ingresar otro elemento?: (Y/N)" << endl;
					cin >> bandera;
					if(bandera == "N"){
						continuar = false;
					} 
				}while (continuar);
            	system("cls");
                break;
            case 1:
				do{
					cout << "Dijite el numero: " << endl;
					cin >> ingreso;
					try{
						if(ing.esUnNumero(ingreso)==false){
							throw "El dato ingresado contiene letras o caracteres especiales";
						}
				    	valor = ing.convertirDatoEntero(ingreso);
				    	lst.insertarFinal(valor);
					}catch(const char *error){
						cout << "Error: " << error << endl;
					}
					cout << "¿Desea ingresar otro elemento?: (Y/N)" << endl;
					cin >> bandera;
					if(bandera == "N"){
						continuar = false;
					}
				}while (continuar);
            	system("cls");
                break;
            case 3:
				do{
					cout << "Dijite el numero: " << endl;
					cin >> ingreso;
					try{
						if(ing.esUnNumero(ingreso)==false){
							throw "El dato ingresado contiene letras o caracteres especiales";
						}
				    	valor = ing.convertirDatoEntero(ingreso);
				    	lst.eliminarNodo(valor);
					}catch(const char *error){
						cout << "Error: " << error << endl;
					}
					continuar = false;
				}while (continuar);       
                break;
            case 4:
				do{
					cout << "Dijite el numero: " << endl;
					cin >> ingreso;
					try{
						if(ing.esUnNumero(ingreso)==false){
							throw "El dato ingresado contiene letras o caracteres especiales";
						}
				    	valor = ing.convertirDatoEntero(ingreso);
				    	lst.buscarElemento(valor);
					}catch(const char *error){
						cout << "Error: " << error << endl;
					}
					continuar = false;
				} while (continuar);
            	break;
            case 5:
            	lst.mostrar();
            	break;
            case 0:
            	repetir = false;
            	break;
        }        
    } while (repetir);
	return 0; 
}