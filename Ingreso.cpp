#include <iostream>
#include <cstdlib>
#include <string>
#include "Ingreso.h"
using namespace std;

bool Ingreso::esUnNumero(std::string cad){
	int longitud = cad.length();
	char dato[longitud];
	strcpy(dato,cad.c_str());
    for(int j=0;j<cad.length();j++){
    	if(dato[0]=='.'){
    		return false;
		}
        if(!((dato[j]>='0' && dato[j]<='9')||dato[j]=='.')){
           return false;
        }
    }
    return true;
}

bool Ingreso::esUnFloat(std::string cad){
	int longitud = cad.length();
	char dato[longitud];
	int i=0, cont=0;
	strcpy(dato,cad.c_str());
    for(int j=0;j<cad.length();j++){
        if(dato[j]=='.'){ 
			cont += 1; 
        }
    }
    if(cont >= 2){
    	return false;
	}
    return true;
}
   
int Ingreso::convertirDatoEntero(std::string cad){
	int longitud = cad.length();
	char conver[longitud];
	strcpy(conver,cad.c_str());
	return atoi(conver);
}

float Ingreso::convertirDatoDecimal(std::string cad){
	int longitud = cad.length();
	char conver[longitud];
	strcpy(conver,cad.c_str());
	return atof(conver);
}

char Ingreso::convertirDatoCaracter(std::string cad){
	int longitud = cad.length();
	char conver[longitud]; 
    strcpy(conver, cad.c_str());
    for (int i = 0; i < longitud; i++){
    	cout << conver[i];
	}
    return 0;
}