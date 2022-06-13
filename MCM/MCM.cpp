#include "MCM.h"

long MCM::mcd(int a,int b){
	if(a%b==0)
		return b;
	else
		return mcd(b,a%b);
}