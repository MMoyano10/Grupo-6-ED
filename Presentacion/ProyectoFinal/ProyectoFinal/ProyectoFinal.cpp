/*
Universidad de las Fuerzas Armadas "Espe"
Programa: Programa de registro de una mecanica con el uso de listas circulares doblemente enlazadas 
Autor: David Cantuña 
Autor: Mathius  Moyano
Fecha de creacion: 09/06/2022
Fecha de modificacion: 09/06/2022
Version: 1
Nombre Materia: Estructura de Datos
Nrc: 4683
*/


#include <iostream>

#include "ListaDobleCircular.h"
#include "Menu.h"
#include "Imagen.h"

using namespace std;

int main()
{
    ListaDobleCircular ldc;
    Menu menu;
	Imagen img;

    int opcion;

    char UsuarioC[] = "admin";
    char ContraC[] = "admin";

    char usuario[30];
    char contrasena[30];
	
	do {
		cin.clear();
		fflush(stdin);
		menu.Marquesina("INGRESE EL USUARIO: ");
		cin.getline(usuario, 30);
		menu.Marquesina("INGRESE LA CONTRASENIA: ");
		cin.getline(contrasena, 30);
	} while (!((strcmp(UsuarioC, usuario) == 0) && (strcmp(ContraC, contrasena) == 0)));
	
	do {
		opcion = menu.MenuCursor();
		switch (opcion)
		{
		case 0:
			ldc.Agregar();
			system("pause>nul");
			break;
		case 1:
			ldc.Mostrar();
			system("pause>nul");
			break;
		case 3:
			ldc.Buscar();
			system("pause>nul");
			break;
		case 4:
			ldc.GenerarArchivo();
			system("pause>nul");
			break;
		case 5:
			img.DrwImage();
			system("pause>nul");
			break;
		default:
			menu.Marquesina("Ejecicion Terminada");
			break;
		}
	}while(opcion != 6);
	
}
