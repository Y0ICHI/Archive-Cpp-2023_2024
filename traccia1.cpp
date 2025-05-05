#include<iostream>
#include <string>
#include <cctype>
using namespace std;

//Caricamento Caratteri
void Caricamento(int dim, char* C){
	for(int i=0; i<dim; i++){
		cout << i+1 << " - Inserire il carattere." << endl;
		cin >> *(C+i);
	}
}

//Visualizzazione Caratteri
void Visualizza(int dim, char* C){
	for(int i=0; i<dim; i++){
		cout << *(C+i) << endl;
	}
}

//Trasformazione possibili caratteri in minuscolo in maiuscolo
void Maiuscolo(int dim, char* C){
	for(int i=0; i<dim; i++){
		*(C+i) = toupper(*(C+i));
	}
}

//Conta i Caratteri che sono vocali
int ContatoreVocali(int dim, char* C){
	int Conta = 0;
	for(int i=0; i<dim; i++){
		//Controlla se sono dei numeri, se lo sono, gli ignora
		if (!isdigit(*(C+i))) {
			if(*(C+i)=='A' || *(C+i)=='E' || *(C+i)=='I' || *(C+i)=='O' || *(C+i)=='U'){
				Conta++;
			}
		}
	}
	//Riporta il valore
	return Conta;
}

//Contatore delle Consonsanti
int ContatoreConsonanti(int dim, char* C){
	int Conta = 0;
	for(int i=0; i<dim; i++){
		//Controlla se sono dei numeri, se lo sono, gli ignora
		if (!isdigit(*(C+i))) {
			//Controlla se non ci sono vocali
			if(*(C+i)!='A' and *(C+i)!='E' and *(C+i)!='I' and *(C+i)!='O' and *(C+i)!='U'){
				Conta++;
			}
		}
	}
	//Riporta il valore
	return Conta;
}

int main(){
	int dim;
	cout << "Quanti caratteri vuoi inserire?" << endl;
	cin >> dim;
	while(dim<=0){
		cout << "Errore, riprovare." << endl;
		cin >> dim;
	}
	char* Car = new char[dim]; // Allocazione dinamica
	Caricamento(dim, Car);
	Maiuscolo(dim, Car);
	int Vocali = ContatoreVocali(dim, Car);
	cout << "Numero vocali: " << Vocali << endl;
	int Consonanti = ContatoreConsonanti(dim, Car);
	cout << "Numero consonanti: " << Consonanti << endl;
	delete[] Car; // Deallocazione dinamica
	return 0;
}
