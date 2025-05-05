#include <iostream>
using namespace std;

int main(){
	int x=10;
	int *p;
	
	cout << "Ora x vale: " << x << endl;
	cout << "L'indirizzo di memoria di x e': " << &x << endl;
	
	p = &x;
	
	cout << "L'indirizzo di p e': " << p << endl;
	cout << "Il valore puntato da p e': " << *p << endl;
	
	x = 20;
	cout << "Il valore puntato da p e': " << *p << endl;
	*p = 30;
	cout << "Ora x vale: " << x << endl;
	
	return 0;
}
