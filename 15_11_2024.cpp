#include<iostream>

using namespace std;

struct Elemento{
	string nome;
	string cognome;
	Elemento* next;
};

Elemento* Primo = NULL;
Elemento* Ultimo = NULL;

void AggiungiInTesta(string Nome, string Cognome){
	if(Primo == NULL){
		Primo = new Elemento;
		Primo->nome = Nome;
		Primo->cognome = Cognome;
		Primo->next=NULL;
	} else {
		Elemento* temp = new Elemento;
		temp->nome = Nome;
		temp->cognome = Cognome;
		temp->next = Primo;
		Primo = temp;
	}
}

void Visualizza(){
	Elemento* temp = Primo;
	int i=1;
	while(temp!=NULL){
		cout << i++ << " - Elemento" <<endl << endl;
		cout << "Nome: " << temp->nome << endl;
		cout << "Cognome: " << temp->cognome << endl;
		temp = temp->next;
	}
	return;
}





int main(){
	int N;
	string Nome, Cognome;
	cout << "N" << endl;
	cin >> N;
	for(int i=0; i<N; i++){
	cout << i << " Inserimento" << endl;
	cout << "Nome" << endl;
	cin >> Nome;
	cout << "Cognome" << endl;
	cin >> Cognome;
	AggiungiInTesta(Nome, Cognome);
	}
	
	cout << "Prima: " << endl;
	Visualizza();
	cout << "Nome" << endl;
	cin >> Nome;
	cout << "Cognome" << endl;
	cin >> Cognome;
	AggiungiInTesta(Nome, Cognome);
	cout << "Dopo: " << endl;
	Visualizza();
}
