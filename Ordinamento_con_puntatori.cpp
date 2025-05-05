//Traccia: Ordinare un vettore di numeri interi o reali con l'argoritmo del bubble sort, utilizzando l'artimetica dei puntatori. Senza l'appogio di un altro vettore, invertire i dati inseriti in input senza riordinarli
#include<iostream>
using namespace std;

void Visualizza(int V[], int dim, int *p){
	for (int i = 0; i<dim; i++){
		cout << *(p+i) << endl;
	}
}

void BubbleSort(int V[], int dim, int *p){
	int i, k, ultimo = dim-1;
	bool scambio = true;
	int PT; //Puntatore Temporaneo
	//cout << "V posizione 0: " << *p << endl;
	//cout << "dimensione: " << dim << endl;
	while(scambio==true){
		k = ultimo;
		scambio = false;
		for(i=0; i<k; i++){
			if(*(p+i)>*(p+(i+1))){
				//cout << "Prima -----------------------" << endl;
				//cout << "Ho trovato che " << *p << " \212 maggiore di " << *(p+(i+1)) << " quindi gli scambio tra le loro posizioni." << endl;
				//Visualizza(V, dim, p);
				scambio = true;
				ultimo = i;
				
				PT = *(p+i);
				*(p+i) = *(p+1+i);
				*(p+1+i) = PT;
			}
			//cout << "Dopo -----------------------" << endl;
			//Visualizza(V, dim, p);
		}
	}
	//cout << "-------------------------------------------------" << endl;
}

//void Caricamento


int main(){
	int Vettore[] = { 84, 214, 31, 13, 6, 1, 8 ,10}; // ordine corretto 1,6,8,10,13,31,84,214
	int *p;
	int dim = 8; // da cambiare in caso si cambiano i numeri e sono stati inseriti un numero differente
	p = Vettore;
	BubbleSort(Vettore, dim, p);
	Visualizza(Vettore, dim, p);
	
	return 0;
}
