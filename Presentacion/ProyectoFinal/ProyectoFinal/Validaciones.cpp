/***********************************************************************
 * Module:  Validaciones.cpp
 * Author:  Moyano W
 * Modified: jueves, 9 de junio de 2022 22:19:45
 * Purpose: Implementation of the class Validaciones
 ***********************************************************************/

#include <iostream>
#include <regex>

#include "Validaciones.h"

using namespace std;

////////////////////////////////////////////////////////////////////////
// Name:       Validaciones::ValidarCadenas(char* cadena)
// Purpose:    Implementation of Validaciones::ValidarCadenas()
// Parameters:
// - cadena
// Return:     int
////////////////////////////////////////////////////////////////////////

int Validaciones::ValidarCadenas(char cadena[30])
{
	int i = 0, validandoL = 0, j;
	j = strlen(cadena); //se asigna el numero de caracteres que tiene la cadena a J

	while (i < j && validandoL == 0) {

		if (isalpha(cadena[i]) != 0 || cadena[i] == 32) // 32 para que acepte espacios tambien 
		{
			i++; //si es una letra avanza de lo contrario entra al else para salirse del ciclo
		}
		else {
			validandoL = 1;
		}
	}
	return validandoL;
}

////////////////////////////////////////////////////////////////////////
// Name:       Validaciones::ValidarMatriculaEc(char* matricula)
// Purpose:    Implementation of Validaciones::ValidarMatriculaEc()
// Parameters:
// - matricula
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Validaciones::ValidarMatriculaEc(char matricula[30])
{
	std::regex expReg("[A-Z]{3}\\d{4}");
	return regex_match(matricula, expReg);
}

////////////////////////////////////////////////////////////////////////
// Name:       Validaciones::ValidarCedulaEc(char* cedula)
// Purpose:    Implementation of Validaciones::ValidarCedulaEc()
// Parameters:
// - cedula
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Validaciones::ValidarCedulaEc(char cedula[30])
{
	int v[10];
	int num = 0;
	int limite = 0;

	limite = strlen(cedula);

	if (limite != 10)
		return false;

	if (limite == 10) {

		for (int i = 0; i < 10; i++) {
			num = cedula[i] - 48;
			v[i] = num;
		}

		//VALIDACION CEDULA PROCESO

		int vec[10];
		int suma = 0;
		int ultimo = 0;
		int ultimon = 0;
		if (v[0] == 1 || v[0] == 2) {
			if (v[2] > 0 && v[2] < 6) {

				for (int i = 0; i < 9; i += 2) {
					vec[i] = v[i] * 2;
					if (vec[i] >= 10)
						vec[i] -= 9;
				}

				for (int i = 1; i < 9; i += 2) {
					vec[i] = v[i];

				}

				suma = 0;
				for (int i = 0; i < 10; i++) {
					suma = suma + vec[i];
				}

				if (suma == 10)
					ultimo = 0;
				else if (suma > 10 && suma < 20)
					ultimo = 20;
				else if (suma > 20 && suma < 30)
					ultimo = 30;
				else if (suma > 30 && suma < 40)
					ultimo = 40;
				else return true;


				ultimon = ultimo - suma;

				if (ultimon == v[9])
					return true;
				else
					return false;


			}

			else
				return false;

		}
	}
	return false;
}

////////////////////////////////////////////////////////////////////////
// Name:       Validaciones::ValidarFecha(char* fecha)
// Purpose:    Implementation of Validaciones::ValidarFecha()
// Parameters:
// - fecha
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Validaciones::ValidarFecha(char fecha[30])
{
	std::regex expRegF("(0?[1-9]|[12][0-9]|3[01])[\\/](0?[1-9]|1[012])[\\/]([012][0-9])\\d{2}");
	return regex_match(fecha, expRegF);
}



