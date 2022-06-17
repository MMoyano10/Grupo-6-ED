/* 
Universidad de las Fuerzas Armadas "Espe"
Programa: Transformar una expresion infuja en posfija o prefija
Autor: Edwin David Cantuña Morales 
Fecha de creacion: 17/06/2022
Fecha de modificacion: 17/06/2022
Version: 1
Nombre Materia: Estructura de Datos
Nrc: 4683
*/

// 1+(2-3*4^2)/8

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

#include "Nodo.h"
using namespace std;

int main(int argc, char** argv) {
	
	Nodo nd;
	
	Nodo *pila = NULL;
	
	char *expr = new char;
	char dato;
	char rpt;

	do{
		
		cout << "INGRESE LA EXPRESION (INFIJO)" << endl;
		gets(expr);
		fflush(stdin);
		
		cout << "------------------------------" << endl;
		cout << "INFIJO" << endl;
		for(int i = 0; i < strlen(expr); i++){
			cout << expr[i] << " ";
		}
		
		cout << endl;
		cout << "PREFIJO" << endl;
		for(int i = 0; i < strlen(expr); i++){
			switch(expr[i]){
				case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '(':
					nd.push(pila,expr[i]);
					break;
				case '+': case '-': case '*': case '/': case '^':
					cout << expr[i] << ' ';
					break;
				case ')':
					if(pila != NULL){
						dato = nd.pop(pila);
						while(pila != NULL && dato != '('){
							cout << dato << " ";
							dato = nd.pop(pila);
						}
					}
					break;
			}
		}
		while (pila != NULL){
			cout << nd.pop(pila) << " ";
		}
	
		cout << endl;
		cout << "POSFIJO" << endl;
	
		for(int i = 0; i < strlen(expr); i++){
			switch(expr[i]){
				case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
					fflush(stdin);
					cout << expr[i] << ' ';
					break;
				case '+': case '-': case '*': case '/': case '^': case '(':
					fflush(stdin);
					nd.push(pila,expr[i]);
					break;
				case ')':
					if(pila != NULL){
						dato = nd.pop(pila);
						while(pila != NULL && dato != '('){
							cout << dato << " ";
							dato = nd.pop(pila);
						}
					}
					break;
			}
		}
		while (pila != NULL){
			cout <<  nd.pop(pila) << " ";
		}
		
		cout << endl;
		cout << "------------------------------" << endl;

		cout << "DESEA INGRESAR OTRA EXPRESION (S/s)" << endl;
		cin >> rpt;
		fflush(stdin);
		
	}while((rpt=='S')||(rpt=='s'));
	
	return 0;
}