#include<iostream>
#include<cstdlib>

using namespace std;

struct Elemento{
	int dato;
	Elemento* next;
};

Elemento* Primo;
Elemento* Ultimo;

void AggiungiInCoda(int newDato){
	Elemento* temp = new Elemento;
	temp->dato=newDato;
	temp->next=NULL;
	if(Primo==NULL){
		Primo=temp;
		Ultimo = Primo;
	} else {
		Ultimo->next=temp;
		Ultimo = temp;
	}
}

void Visualizza(){
	Elemento* temp = Primo;
	int i=1;
	while(temp!=NULL){
		cout << i++ << " - " << temp->dato << endl;
		temp=temp->next; 
	}
}



int main(){
	int N, dato;
	cout << "Inserire i numero di dati." << endl;
	cin >> N;
	for(int i=0; i<N; i++){
		cout << i+1 << " - Inserire l'elemento." << endl;
		cin >> dato;
		AggiungiInCoda(dato);
	}
	cout << "Visualizza:" << endl;
	Visualizza();
}
