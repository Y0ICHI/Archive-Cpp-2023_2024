#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

struct volo {
	string nome;
	string cognome;
	string nVolo;
	bool bagaglio;
	volo *next;
	volo *prev;
};

volo *Primo = NULL;
volo *Ultimo = NULL;


void InserimentoInCoda(string nome, string cognome, string Volo, bool bagaglio){
	volo *temp = new volo;
	temp->nome = nome;
	temp->cognome = cognome;
	temp->nVolo = Volo;
	temp->bagaglio = bagaglio;
	temp->next = NULL;
	temp->prev = NULL;
	if(Primo==NULL){
		Primo = temp;
	}else{
		Ultimo->next = temp;
		temp->prev = Ultimo;
	}
	Ultimo = temp;
}

void Vero(bool Bagaglio){
	if(Bagaglio==true){
		cout << "Si" << endl;
	} else {
		cout << "No" << endl;
	}
}

void VisualizzaDaTesta(){
	volo *temp = Primo;
	while(temp!=NULL){
		cout << "Nome: " << temp->nome << endl;
		cout << "Cognome: " << temp->cognome << endl;
		cout << "Volo: " << temp->nVolo << endl;
		cout << "Bagaglio da stivare: ";
		Vero(temp->bagaglio);
		temp = temp->next;
	}
}

void VisualizzaDaCoda(){
	volo *temp = Ultimo;
	while(temp!=NULL){
		cout << "Nome: " << temp->nome << endl;
		cout << "Cognome: " << temp->cognome << endl;
		cout << "Volo: " << temp->nVolo << endl;
		cout << "Bagaglio da stivare: ";
		Vero(temp->bagaglio);	
		temp = temp->prev;
	}
	return;
}

void EstrazioneInTesta(){
    volo *temp = Primo;
    if (Primo != NULL) {
        Primo = Primo->next;
        if (Primo != NULL) {
            Primo->prev = NULL;
        } else {
            Ultimo = NULL;
        }
        delete temp;
    }
}

bool VisualizzaBagagli(){
	volo* temp = Primo;
	bool stivare = false;
	while(temp!=NULL){
		if(temp->bagaglio){
			cout << "Nome: " << temp->nome << endl;
			cout << "Cognome: " << temp->cognome << endl;
			cout << "Volo: " << temp->nVolo << endl;
			stivare = true;
		}
		temp = temp->next;
	}
	return stivare;
}

bool Ricerca_e_Rimuovi(){
    volo *temp = Primo;
    volo *tempPrec = NULL;

    if (temp == NULL) {  // la lista è vuota
        return false;
    } else {
        while (temp != NULL && temp->bagaglio) {
            tempPrec = temp;
            temp = temp->next;
        }
        if (temp != NULL && !temp->bagaglio) {
            if (tempPrec != NULL) {
                tempPrec->next = temp->next;
            } else {
                // Se l'elemento da rimuovere è il primo nodo
                Primo = temp->next;
            }
            if (temp->next != NULL) {
                temp->next->prev = tempPrec;
            } else {
                // Se l'elemento da rimuovere è l'ultimo nodo
                Ultimo = tempPrec;
            }
            delete temp;
            return true;
        } else {
            return false;
        }
    }
}


int main(){
	int N;
	cout << "N" << endl;
	cin >> N;
	while(N<0){
		cout << "Errore." << endl;
		cin >> N;
	}
	string nome, cognome, volo;
	bool bagaglio;
	char scelta;
	for(int i = 0; i<N; i++){
		cout << i+1 << " - Nome" << endl;
		cin >> nome;
		cout << i+1 << " - Cognome" << endl;
		cin >> cognome;
		cout << i+1 << " - Volo" << endl;
		cin >> volo;
		cout << i+1 << " - Bagaglio (Y/N)" << endl;
		cin >> scelta;
		scelta = toupper(scelta);
		while(scelta!='Y' and scelta!='N'){
			cout << "Errore." << endl;
			cin >> scelta;
			scelta = toupper(scelta);
		}
		if(scelta=='Y'){
			bagaglio = true;
		} else {
			bagaglio = false;
		}
		InserimentoInCoda(nome, cognome, volo, bagaglio);
	}
	//cout << "Visualizza da testa:" << endl;
	//VisualizzaDaTesta();
	//cout << "Visualizza da coda: " << endl;
	//VisualizzaDaCoda();
	
	bool stop = false;
	int N2;
	while(stop == false){
	cout << "C'e nuova gente in fila? (Y/N)" << endl;
	cin >> scelta;
	scelta = toupper(scelta);
	while(scelta!='Y' and scelta!='N'){
		cout << "Errore." << endl;
		cin >> scelta;
		scelta = toupper(scelta);
	}
	if(scelta=='N'){
		stop = true;
	} else {
		cout << "Quante sono le nuove persone?" << endl;
		cin >> N2;
		while(N2<0){
		cout << "Errore." << endl;
		cin >> N2;
		}
		for(int i = 0; i<N2; i++){
		cout << i+1 << " - Nome" << endl;
		cin >> nome;
		cout << i+1 << " - Cognome" << endl;
		cin >> cognome;
		cout << i+1 << " - Volo" << endl;
		cin >> volo;
		cout << i+1 << " - Bagaglio (Y/N)" << endl;
		cin >> scelta;
		scelta = toupper(scelta);
		while(scelta!='Y' and scelta!='N'){
			cout << "Errore." << endl;
			cin >> scelta;
			scelta = toupper(scelta);
		}
		if(scelta=='Y'){
			bagaglio = true;
		} else {
			bagaglio = false;
		}
		InserimentoInCoda(nome, cognome, volo, bagaglio);
		}
		}
	}
	VisualizzaDaTesta();
	int N3;
	cout << "Quante persone hanno terminato di fare il check-in?" << endl;
	cin >> N3;
	while(N3<0){
		cout << "Errore." << endl;
		cin >> N3;
	}
	for(int i=0; i<N3; i++){
		EstrazioneInTesta();
	}
	VisualizzaDaTesta();
	cout << "Utenti con un bagaglio da stivare:" << endl;
	if(!VisualizzaBagagli()){
		cout << "Non ci sono utenti con un bagaglio da stivare." << endl;
	}
	bool trovato = Ricerca_e_Rimuovi();;
	while (trovato){
    trovato = Ricerca_e_Rimuovi();
	}
	cout << "Lista senza gli utenti senza bagaglio." << endl;
	VisualizzaDaTesta();
	return 0;
}
	
