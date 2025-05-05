#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

struct voto {
    float scritto;
    float pratica;
    float orale;
    float complessiva;
};

struct studente {
    string nome;
    string cognome;
    voto media;
    studente* next;
};

studente *Primo = NULL, *Ultimo = NULL;

void EliminazioneAlunno() {
    string nome, cognome;
    cout << "Nome: ";
    cin >> nome;
    cout << "Cognome: ";
    cin >> cognome;

    studente* corrente = Primo;
    studente* precedente = NULL;

    while (corrente != NULL) {
        if (corrente->nome == nome && corrente->cognome == cognome) {
            if (precedente == NULL) {
                Primo = corrente->next; // Rimuovi il primo nodo
            } else {
                precedente->next = corrente->next; // Rimuovi nodo intermedio o finale
            }
            delete corrente; // Libera la memoria
            cout << "Lo studente è stato trovato e eliminato!" << endl;
            return; // Esci dalla funzione dopo l'eliminazione
        }
        precedente = corrente; // Aggiorna il nodo precedente
        corrente = corrente->next; // Passa al nodo successivo
    }
    cout << "Lo studente non è stato trovato." << endl;
}

int ContaStudente(){
	studente* corrente = Primo;
	int conta = 0;
	while(corrente !=NULL){
		if(corrente->media.complessiva >= 6){
			//cout << "Nome: "<< corrente->nome << endl << "Cognome: " << corrente->cognome << endl << "Media:" << corrente->media.complessiva << endl;
			conta++;
		}
		corrente = corrente->next;
	}
	return conta;
}

bool VisualizzaStudenteMediaInferiore5(){
	studente* corrente = Primo;
	bool trovato = false;
	while(corrente !=NULL){
		if(corrente->media.scritto <= 5){
			cout << "Nome: "<< corrente->nome << endl << "Cognome: " << corrente->cognome << endl << "Media scritto:" << corrente->media.scritto << endl;
			trovato = true;
		}
		corrente = corrente->next;
	}
	return trovato;
}

bool VisualizzaStudenteMediaSuperiore8(){
	studente* corrente = Primo;
	bool trovato = false;
	while(corrente !=NULL){
		if(corrente->media.complessiva >= 8){
			cout << "Nome: "<< corrente->nome << endl << "Cognome: " << corrente->cognome << endl << "Media complessiva:" << corrente->media.complessiva << endl;
			trovato = true;
		}
		corrente = corrente->next;
	}
	return trovato;
}



int main() {
    int n;
    cout << "Inserire la dimensione della lista di studenti: " << endl;
    cin >> n;
    while (n <= 0) {
        cout << "Il numero deve essere maggiore di zero." << endl;
        cin >> n;
    }
    
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            Primo = new studente;
            if (Primo == NULL)
                return -1;

            cout << i << " - Inserisci il nome dello studente: ";
            cin >> Primo->nome;
            cout << i << " - Inserisci il cognome dello studente: ";
            cin >> Primo->cognome;
            cout << i << " - Inserisci la media del voto scritto: ";
            cin >> Primo->media.scritto;
            cout << i << " - Inserisci la media del voto pratica: ";
            cin >> Primo->media.pratica;
            cout << i << " - Inserisci la media del voto orale: ";
            cin >> Primo->media.orale;
            Primo->media.complessiva=(Primo->media.scritto+Primo->media.pratica+Primo->media.orale)/3;
            Primo->next = NULL;
            Ultimo = Primo;
        } else {
            Ultimo->next = new studente;
            if (Ultimo->next == NULL)
                return -1;

            Ultimo = Ultimo->next;

            cout << i << " - Inserisci il nome dello studente: ";
            cin >> Ultimo->nome;
            cout << i << " - Inserisci il cognome dello studente: ";
            cin >> Ultimo->cognome;
            cout << i << " - Inserisci la media del voto scritto: ";
            cin >> Ultimo->media.scritto; 
            cout << i << " - Inserisci la media del voto pratica: ";
            cin >> Ultimo->media.pratica;
            cout << i << " - Inserisci la media del voto orale: ";
            cin >> Ultimo->media.orale;
            Ultimo->media.complessiva = (Ultimo->media.scritto + Ultimo->media.pratica + Ultimo->media.orale) / 3;
            Ultimo->next = NULL; 
    }
}

EliminazioneAlunno();
int conta=ContaStudente();
if(conta!=0){
	cout << "Ci sono " << conta << " alunni con la media maggiore o uguale a 6!" << endl;
} else {
	cout << "Non ci sono studenti con la media maggiore o uguale a 6, non \212 molta buona la situazione.." << endl;
}

cout << "Studenti con una media degli scritti inferiore a 5: " << endl;

if(!VisualizzaStudenteMediaInferiore5()){
	cout << "Nessuno studente con la media inferiore a 5." << endl;
}

cout << "Studenti con una media complessiva superiore a 8." << endl;
if(!VisualizzaStudenteMediaSuperiore8()){
	cout << "Nessuno studente con la media complessiva superiore a 8." << endl;
}

    

    return 0;
}

