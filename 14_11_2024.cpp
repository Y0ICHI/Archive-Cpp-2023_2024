#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Elemento {
    int dato;
    Elemento *next;
};

Elemento* Testa = NULL;

void inserisciInTesta(Elemento*& testa, int valore) {
    Elemento* nuovoElemento = new Elemento; // Crea un nuovo nodo
    nuovoElemento->dato = valore; // Imposta il valore del nodo
    nuovoElemento->next = testa; // Il nuovo nodo punta all'attuale testa
    testa = nuovoElemento; // Aggiorna la testa per puntare al nuovo nodo
}

Elemento* MinPari(){
	Elemento* temp = Testa;
	Elemento* trovato = temp;
	while(temp!=NULL){
	if(temp->dato%2==0){
		//cout << "Il numero " << temp->dato << " \212 pari, YIPPEEE :D" << endl;
		if(trovato->dato>temp->dato)
		trovato = temp;
	}
	temp = temp->next;
	}
	
	if(trovato->dato%2!=0){
		trovato = NULL;
	}
	return trovato;
}

void SterminaDispari() {
    Elemento* temp = Testa;
    Elemento* precendete = NULL;

    while (temp != NULL) {
        if (temp->dato % 2 != 0) {
            if (precendete == NULL) {
                Testa = temp->next;
            } else {
                precendete->next = temp->next;
            }
            Elemento* corrente = temp;
            temp = temp->next;
            delete corrente;
        } else {
            precendete = temp;
            temp = temp->next;
        }
    }
}


int main() {
    int i = 0;
    do {
        cout << i << " - Inserire l'elemento: ";
        Elemento* N = new Elemento;
        cin >> N->dato;
        N->next = NULL;

        if (Testa == NULL) {
            Testa = N; // Se la lista è vuota, il nuovo elemento diventa la testa
        } else {
            Elemento *temp = Testa;
            while (temp->next != NULL) {
                temp = temp->next; // Trova l'ultimo elemento
            }
            temp->next = N; // Aggiunge il nuovo elemento in coda
        }
        i++; // Incrementa il contatore
    } while (i < 5);
	
	int NuovoDato;
	cout << "Inserire il nuovo elemento" << endl;
	cin >> NuovoDato;
	inserisciInTesta(Testa, NuovoDato);
	
	//Trova numero minimo pari
	Elemento* Min=MinPari();
	if(Min!=NULL){
	cout << "L'elemento più piccolo \212 " << Min->dato << endl;
	} else {
	cout << "Non esiste nessun elemento pari piccolo" << endl;
	}
	
	//Elimina i numeri dispari
	SterminaDispari();

    // Stampa gli elementi della lista
    Elemento* temp = Testa;
    cout << "Elementi nella lista:" << endl;
    while (temp != NULL) {
        cout << temp->dato << endl;
        temp = temp->next;
    }

    // Libera la memoria allocata
    temp = Testa;
    while (temp != NULL) {
        Elemento* daEliminare = temp;
        temp = temp->next;
        delete daEliminare;
    }

    return 0;
}

