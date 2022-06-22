#include <iostream>
#include <stdio.h>

#include "Arreglo.h"

using namespace std;

void Arreglo::encerar(int *vec, int tam){
	for(int i=0; i<tam; i++){
		*(vec+i)=0;
	}
}

void Arreglo::ingresar(int *vec, int tam){
	for(int i=0; i<tam; i++){
		scanf("%d", *(&vec)+i);
	}
}

void Arreglo::imprimir(int *vec, int tam){
	for(int i=0; i<tam; i++){
		printf("%d - ", *(&(*vec)));
		*(vec++);
	}
}

void Arreglo::procesar(int *vec, int tam, int e){
	for(int i=0; i<tam; i++){
		*vec=(*(&(*vec)))*e;
		*(vec++);
	}
}

int Arreglo::maximoElemento(int *vec, int tam){ // 56,89,451 saber cuantas veces hay que recorrer (3 veces)
	int max = vec[0];
	for(int i=0; i<tam; i++){
		if(vec[i] > max){
			max = vec[i];
		}
	}
	return max;
}

void Arreglo::ordenamientoRadix(int *vec, int tam){

	const int N = 10;
	int *output = new int[tam];  //contener el resultado ordenado
	int *count = new int[N];   // llevar cuantas veces se repiten los dijitos y las posiciones 
	
	int max = maximoElemento(vec, tam);
	int posicion = 1;
	
	while((max/posicion) > 0){
		
	    for (int i = 0; i < N; ++i){
	    	count[i] = 0;
		}
	  
	    for (int i = 0; i < tam; i++){
	    	count[(vec[i] / posicion) % 10]++;
		}
	        
	    for (int i = 1; i < N; i++){
	    	count[i] += count[i - 1];
		}
	        
	    for (int i = tam - 1; i >= 0; i--) {
	        output[count[(vec[i] / posicion) % 10] - 1] = vec[i];
	        count[(vec[i] / posicion) % 10]--;
	        
	    }
	
	    for (int i = 0; i < tam; i++){
	    	vec[i] = output[i];
		}
	        
		posicion *= 10; // subir las unidades, decenas, centenas
		
	}

}
