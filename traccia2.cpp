#include<iostream>
#include <string>
#include <cctype>
using namespace std;

//Caricamento
void Caricamento(int dim, int* V){
	for(int i=0; i<dim; i++){
		cout << i+1 << " - Inserire il numero" << endl;
		cin >> *(V+i);
	}
}

//Visualizzazzione
void Visualizza(int dim, int* V){
	for(int i = 0; i<dim; i++){
		cout << *(V+i) << endl;
	}
}

//Ordinamento di tipo SelectionSort
void SelectionSort(int dim, int* V){
	int i, j, min;
	int Temp;
	for(i=0; i<dim-1; i++){
		min = i;
		for(j=i+1;j<dim;j++)
			if(*(V+j)<*(V+min))
					min = j;
					
		Temp = *(V+min);
		*(V+min) = *(V+i);
		*(V+i) = Temp;
	}
}

//Fusione di due Vettori
void Fondi(int dimT, int* VT, int* V1, int dimV1, int* V2, int dimV2){ //dimT = Dimensione totale; dimV1 = dimensione Vettore1, ...
	int i, j;
	for(i=0; i<dimV1; i++){
		*(VT+i) = *(V1+i);
	}
	j = i;
	for(i=0; i<dimV2; i++){
		*(VT+j++) = *(V2+i);
	}
}



int main(){
	int dimX, dimY;
	cout << "Inserire la dimensione di X: ";
	cin >> dimX;
	while(dimX<=0){
		cout << "Errore." << endl;
		cin >> dimX;
	}
	cout << endl << "Inserire la dimensione di Y: ";
	cin >> dimY;
	while(dimY<=0){
		cout << "Errore." << endl;
		cin >> dimY;
	}
	int* X = new int[dimX];
	int* Y = new int[dimY];
	
	Caricamento(dimX, X);
	cout << "------------------------" << endl;
	Caricamento(dimY, Y);
	cout << "-----------------------" << endl;
	
	int dimZ = dimX + dimY;
	
	int* Z = new int[dimZ];
	
	Fondi(dimZ, Z, X, dimX, Y, dimY);
	
	SelectionSort(dimZ, Z);
	
	Visualizza(dimZ, Z);
	
	delete[] X, Y, Z;
	
	return 0;
}
