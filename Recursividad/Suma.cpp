#include "Suma.h"

int Suma::suma(int num){
	if(num == 0){
 		return 0;
	} else{
		return num+suma(num-1);
	}
 }
