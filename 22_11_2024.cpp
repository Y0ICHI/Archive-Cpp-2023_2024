#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

struct El {
	string nome;
	string cognome;
	bool Abbonato;
	string spettacolo;
	El* next;
};

El* Primo = NULL, *Ultimo = NULL;

void InserisciInCoda(string nome, string cognome, bool abbonato, string spettacolo){
	El* temp = new El;
	temp->nome = nome;
	temp->cognome = cognome;
	temp->Abbonato = abbonato;
	temp->spettacolo = spettacolo;
	temp->next=NULL;
	if(Primo == NULL){
		Primo = temp;
		Ultimo = Primo;
	} else {
	Ultimo->next = temp;
	Ultimo = temp;
	}
}

void Vero(bool abbonato){
	if(abbonato == true){
		cout << "Si" << endl;
	} else {
		cout << "Nuh uh" << endl;
	}
}

void LiberaMemoria() {
    El* temp = Primo;
    while (temp != NULL) {
        El* daEliminare = temp;
        temp = temp->next;
        delete daEliminare;
    }
    Primo = NULL;
    Ultimo = NULL;
}

void EliminaInTesta3(){ //Eliminerà i primi 3, richiesta dalla traccia
	El* temp = Primo;
	const int A=3;
	for(int i = 0; i<A; i++){
		if(Primo == NULL){
			cout << "Coda vuota." << endl;
			return;
		}
		El* correnteEliminazione = temp;
		temp = temp->next;
		Primo = temp;
		delete correnteEliminazione;
	}
}

int ContaUtenti() {
    int count = 0;
    El* temp = Primo;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void Visualizza(){
	El* temp = Primo;
	while(temp!=NULL){
		cout << "Nome: " << temp->nome << endl;
		cout << "Cognome: " << temp->cognome << endl;
		cout << "Abbonato: ";
		Vero(temp->Abbonato);
		cout << "Spettacolo: " << temp->spettacolo << endl;
		temp = temp->next;
	}
}

void VisualizzaAbbonati(){
	El* temp = Primo;
	while(temp!=NULL){
		if(temp->Abbonato){
		cout << "Nome: " << temp->nome << endl;
		cout << "Cognome: " << temp->cognome << endl;
		cout << "Spettacolo: " << temp->spettacolo << endl;
	}
		temp = temp->next;
	}
}

bool EliminaElementi(string cercato){
    El* temp = Primo;
    El* precedente = NULL;
    bool eliminato = false;
    while(temp != NULL){
        if(temp->spettacolo == cercato){
            if(precedente == NULL){
                Primo = temp->next;
            } else {
                precedente->next = temp->next;
            }
            El* elimina = temp;
            temp = temp->next;
            delete elimina;
            eliminato = true;
        } else {
            precedente = temp;
            temp = temp->next;
        }
    }
    return eliminato;
}




int main(){
	int N;
	cout << "Quanti utenti inserire?" << endl;
	cin >> N;
	while (N<5){
		cout << "Errore, deve essere almeno 5!" << endl;
		cin >> N;
	}
	string nome, cognome, spettacolo;
	bool abbonato;
	char CheckAbbonato;
	for(int i = 0; i<N; i++){
		cout << "Nome: ";
		cin >> nome;
		cout << endl << "Cognome: ";
		cin >> cognome;
		cout << endl << "Abbonato (Y/N): ";
		cin >> CheckAbbonato;
		cout << endl;
		CheckAbbonato = toupper(CheckAbbonato);
		while(CheckAbbonato !='Y' and CheckAbbonato!='N'){
			cout << "Errore." << endl;
			cin >> CheckAbbonato;
			CheckAbbonato = toupper(CheckAbbonato);
		}
		if(CheckAbbonato == 'Y'){
			abbonato = true;
		} else {
			abbonato = false;
		}
		cout << "Spettacolo: ";
		cin >> spettacolo;
		InserisciInCoda(nome, cognome, abbonato, spettacolo);
	}
	cout << "Fila: " << endl;
	Visualizza();
	cout << "Fila, solo abbonati: " << endl;
	VisualizzaAbbonati();
	EliminaInTesta3();
	cout << "Fila, senza tre persone." << endl;
	int utentiRimanenti = ContaUtenti();
	if (utentiRimanenti > 0) {
        cout << "Ci sono nella fila " << utentiRimanenti << " persone." << endl;
    } else {
        cout << "La coda è terminata." << endl;
    }
    Visualizza();
    string sAnnullato;
    cout << "Oh no lo spettacolo.. ";
    cin >> sAnnullato;
    cout << " \212 stato annullato!" << endl;
    if(EliminaElementi(sAnnullato)){
    	cout << "Sembra che qualcuno ha perso il loro posto nella sua fila" << endl;
	} else {
		cout << "Sembra che nessuno abbia perso il loro posto nella sua fila" << endl;
	}
	cout << "Nuova lista: " << endl;
	Visualizza();
	LiberaMemoria();
}
