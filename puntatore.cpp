#include<iostream>
using namespace std;

int main(){
	int A = 1, B = 2;
	int *X, *Z;
	
	X = &A;
    Z = &B;
	
	cout << "L'indirizzo di A in memoria \212: " << &A << endl << " Con valore: " << A << endl;
	cout << "L'indirizzo puntato da X in memoria \212: " << X << endl << " Con valore: " << *X << endl;
	cout << "-------------------" << endl;
	cout << "L'indirizzo di B in memoria \212: " << &B << endl << " Con valore: " << B << endl;
	cout << "L'indirizzo puntato da Z in memoria \212: " << Z << endl << " Con valore: " << *Z << endl;
	cout << endl << "Possiamo verificare che A e B hanno due indirizzi diversi." << endl;
	
	return 0;
}
