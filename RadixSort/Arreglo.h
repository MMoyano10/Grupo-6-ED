#pragma once

class Arreglo {
private:
	int* vector;
public:
	Arreglo() = default;
	Arreglo(int*);
	void setArreglo(int*);
	int* getArreglo();

};
