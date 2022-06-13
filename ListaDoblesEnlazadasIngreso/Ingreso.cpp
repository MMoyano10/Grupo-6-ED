#include <iostream>
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

int Ingreso::convertirDatoEntero(std::string cad){
	int longitud = cad.length();
	char conver[longitud];
	strcpy(conver,cad.c_str());
	return atoi(conver);
}