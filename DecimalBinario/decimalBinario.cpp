#include <iostream>
#define BIN 2
#include "decimalBinario.h"
using namespace std;

void decimalABinario::decimalBinario(int val, char cad[]){
	if(val>=1){
		decimalBinario((val/BIN),cad);
		strcpy(cad,itoa((val%BIN),cad,10));
	}
	strcat(cad,"\0");
	cout<<cad;
}

