#include<iostream>
#include<string>
#include<cctype>
#include<cstdlib>
using namespace std;

void Caricamento(char* V, int dim){
	for(int i = 0; i<dim; i++){
		cout << i+1 << " - Inserire le lettere dell'alfabeto: ";
		cin >> *(V+i);
		cout << endl;
		while(isdigit(*(V+i)) || *(V+i) == ',' || *(V+i) == '.' || (*(V+i)<65 and *(V+i)>97)){
			cout << "no" << endl;
			cin >> *(V+i);
		}
	}
	return;
}

void VisualizzaVettore(char* V, int dim){
	for(int i = 0; i<dim; i++){
		cout << i+1 << ": " << *(V+i) << endl;
	}
}

void Maiuscolo(char* V, int dim){
	for(int i=0; i<dim; i++){
		*(V+i) = toupper(*(V+i));
	}
}

/* TODO (#1#): revisione non completata*/
void Compattamento(char* V, int& dim, int* Pos){
	int i, j = 0;
	for(i = 0; i<dim; i++){
		if(i == *(Pos+j)){
			j++;
		}
		*(V+i) = *(V+j++);
	}
	return;
}

void SpostaVocale(char* V, int dim, char* V2, int& dim2, int* Pos){
	int j=0, i;
	dim2 = 0;
	for(i = 0; i<dim; i++){
		if(*(V+i) == 'A' || *(V+i) == 'E' || *(V+i) == 'I' || *(V+i) == 'O' || *(V+i) == 'U'){
			*(Pos+dim2) = i;
			dim2++;
			*(V2+j++) = *(V+i);
		}
	}
	return;
}

void SpostaInglesi(char* V, int dim, char* V2, int& dim2, int* Pos){
	int j = 0, i;
	dim2 = 0;
	for(i= 0; i<dim; i++){
		if(*(V+i) == 'J' || *(V+i) == 'K' || *(V+i) == 'X' || *(V+i) == 'Y' || *(V+i) == 'W'){
			*(Pos+dim2) = i;
			dim2++;
			*(V2+j++) = *(V+i);
		}
	}
	return;
}

void Fusione(char* V, int& dim, char* V2, int dim2){
	int i, j;
	j = dim;
	dim = dim+dim2;
	for(i = 0; i<dim; i++){
		*(V+j++) = *(V2+i);
		//cout << "-V2: " << *(V2+i) << endl; 
	}
	return;
}

void BubbleSort(char* A, int dim){
	int i, k, ultimo = dim-1;
	bool scambi = true;
	int Temp;
	
	while(scambi==true){
		
		k = ultimo;
		scambi = false;
		
		for(i=0; i<k; i++){
			if(*(A+i)>*(A+i+1)){
				 scambi=true;
				 ultimo = i;
				 
				 Temp=*(A+i);
				 *(A+i)=*(A+i+1);
				 *(A+i+1) = Temp;
			}
		}
	}
	return;
}



int main(){
	// Punto A
	int dim;
	cout << "dim" << endl;
	cin >> dim;
	while(dim<=0){
		cout << "no" << endl;
		cin >> dim;
	}
	char* V = new char[dim];
	Caricamento(V, dim);
	//VisualizzaVettore(V, dim);
	
	// Rende in maiuscolo le lettere
	Maiuscolo(V, dim);
	//VisualizzaVettore(V, dim);
	
	// Punto B (1)
	int dim2;
	char* V2 = new char[dim2];
	int* Pos = new int[dim2];
	SpostaVocale(V, dim, V2, dim2, Pos);
	Compattamento(V, dim, Pos);
	//VisualizzaVettore(V2, dim2);
	cout << "primo V compattato (vocali)" << endl;
	VisualizzaVettore(V, dim);
	//cout << endl << endl;
	
	// Punto B (2)
	int dim3;
	char* V3 = new char[dim3];
	int* Pos2 = new int[dim3];
	SpostaInglesi(V, dim, V3, dim3, Pos);

	Compattamento(V, dim, Pos2);
	//cout << "V3" << endl;
	//VisualizzaVettore(V3, dim3);
	
	cout << "secondo V Compattato (inglese):" << endl;
	VisualizzaVettore(V, dim);
	
	// Punto C
	Fusione(V2, dim2, V3, dim3);
	cout << "Fusione" << endl;
	VisualizzaVettore(V2, dim2);
	delete V3;
	
	
	// Punto D
	BubbleSort(V, dim);
	BubbleSort(V2, dim);
	//VisualizzaVettore(V, dim);
	//VisualizzaVettore(V2, dim2);
}
