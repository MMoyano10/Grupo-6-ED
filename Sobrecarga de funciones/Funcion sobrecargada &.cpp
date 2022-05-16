#include <iostream>
#include <conio.h>
using namespace std;

void direccion(int a,int b){
	
	cout<< "Memoria de a y b:" << endl;
	cout<<"Memoria a:"<<&a<<endl;
	cout<<"Memoria b:"<<&b<<endl;
	cout<<"***______***"<<endl;
}



void direccion(int a,int b,int c){
	
	cout<< "Memoria de a,b y c:" << endl;
	cout<<"Memoria a:"<<&a<<endl;
	cout<<"Memoria b:"<<&b<<endl;
	cout<<"Memoria c:"<<&c<<endl;
	cout<<"***______***"<<endl;
}

void direccion(int a,int b,string c){
	
	cout<< "Memoria de a,b y c:" << endl;
	cout<<"Memoria a:"<<&a<<endl;
	cout<<"Memoria b:"<<&b<<endl;
	cout<<"Memoria c:"<<&c<<endl;
	cout<<"***______***"<<endl;
}

int main(){
	direccion(20,20);
	direccion(25,15,10);
	direccion(25,15,10);
	direccion(25,15,"Cincuenta");
_getch();	
}