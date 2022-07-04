#include "Arreglo.h"


Arreglo::Arreglo(int* nuevo_arreglo) {
    this->vector = nuevo_arreglo;
}

void Arreglo::setArreglo(int* nuevo_arreglo) {
    this->vector = nuevo_arreglo;
}

int* Arreglo::getArreglo() {
    return vector;
}