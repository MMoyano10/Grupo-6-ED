/***********************************************************************
 * Module:  Validaciones.h
 * Author:  Moyano W
 * Modified: jueves, 9 de junio de 2022 22:19:45
 * Purpose: Declaration of the class Validaciones
 ***********************************************************************/

#pragma once

#if !defined(__Class_Diagram_1_Validaciones_h)
#define __Class_Diagram_1_Validaciones_h

class Validaciones {
public:
	int ValidarCadenas(char cadena[30]);
	bool ValidarMatriculaEc(char matricula[30]);
	bool ValidarCedulaEc(char cedula[30]);
	bool ValidarFecha(char fecha[30]);
};

#endif