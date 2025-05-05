//============================================================================
// Name        : liste.cpp
// Author      : Cosimo Farinola
// Version     :
// Copyright   : Your copyright notice
// Description : Liste dinamiche in C++ (esempio 2)
//============================================================================

#include <iostream>
using namespace std;

struct elemento{
	string cognome;
	string nome;
	elemento *next;
};

bool AggiungiElemento(string, string, elemento * &);
void VisualizzaLista();
void CancellaLista();

elemento *primo = NULL;

int main() {

	short n, numAlunni;
	string cogn, nom;
	bool esito;
	elemento *ultimo = NULL;

	cout << "Quanti alunni vuoi inserire? ";
	cin >> numAlunni;
	n = 0;

	for (n=1; n<=numAlunni; n++) {
		cout << "inserisci il cognome: ";
		cin >> cogn;
		cout << "inserisci il nome: ";
		cin >> nom;
		esito = AggiungiElemento(cogn, nom, ultimo);
		if (!esito){
			cout << "Memoria insufficiente!";
			return -1;
		}
	}
	
	/*
	cout << ultimo->cognome << endl;
	cout << ultimo->nome << endl;
	*/

	VisualizzaLista();

	CancellaLista();

	return 0;
}

bool AggiungiElemento(string newCogn, string newNome, elemento * &last) {
    // Creiamo un nuovo nodo
    elemento *nuovoElemento = new elemento;
    if (nuovoElemento == NULL) {
        return false; // Controllo di memoria
    }

    // Assegniamo i valori al nuovo nodo
    nuovoElemento->cognome = newCogn;
    nuovoElemento->nome = newNome;

    // Inseriamo il nuovo nodo in testa alla lista
    nuovoElemento->next = primo; // Il nuovo nodo punta al vecchio primo nodo
    primo = nuovoElemento; // Aggiorniamo il puntatore primo per puntare al nuovo nodo

    // Se la lista era vuota, aggiorniamo anche last
    if (last == NULL) {
        last = nuovoElemento;
    }

    return true;
}


void VisualizzaLista(){
	elemento *temp;  // Utilizza un puntatore ausiliario
	temp = primo;    // Punta temp al primo nodo della lista
	while ( temp != NULL ) {    // fintantoche' temp punta a un elemento (non siamo alla fine della lista)
	  cout << temp->cognome << '\n';  // scrivi l'informazione contenuta nel nodo
	  cout << temp->nome << '\n';
	  temp = temp->next;       // sposta il puntatore temp al prossimo nodo.
	}
	return;
}

void CancellaLista(){

	while ( primo != NULL ) {    // fintantoche' la lista contiene elementi
		elemento * temp = primo;    // Punta temp al primo nodo della lista
	  	primo = primo->next;       // sposta il puntatore temp al prossimo nodo.
	  	delete temp;
	}
	return;
}
