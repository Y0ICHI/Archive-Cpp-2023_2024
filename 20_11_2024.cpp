#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

struct El {
    string prodotto;
    string categoria;
    int quantita;
    float prezzo;
    El* next;
};

El* Primo = NULL, *Ultimo = NULL;

void InserimentoInCoda(string newProdotto, string newCategoria, int newQuantita, float newPrezzo) {
    El* temp = new El;
    temp->prodotto = newProdotto;
    temp->categoria = newCategoria;
    temp->quantita = newQuantita;
    temp->prezzo = newPrezzo;
    temp->next = NULL;

    if (Primo == NULL) {
        Primo = temp;
    } else {
        El* Temp = Primo;
        while (Temp->next != NULL) {
            Temp = Temp->next;
        }
        Temp->next = temp;
    }
}

void InserimentoInTesta(string newProdotto, string newCategoria, int newQuantita, float newPrezzo) {
	El* temp = new El;
	temp->prodotto = newProdotto;
	temp->categoria = newCategoria;
    temp->quantita = newQuantita;
    temp->prezzo = newPrezzo;
    if(Primo == NULL){
		temp->next = NULL;
	} else {
		temp->next = Primo;
	}
	Primo = temp;
}

void Elimina() {
    El* Temp = Primo;
    while (Temp != NULL) {
        El* DaEliminare = Temp;
        Temp = Temp->next;
        delete DaEliminare;
    }
    Primo = NULL;
}

void Visualizza(){
	El* temp = Primo;
	while(temp!=NULL){
		cout << "Prodotto: " << temp->prodotto << endl;
		cout << "Categoria: " << temp->categoria << endl;
		cout << "Quantita': " << temp->quantita << endl;
		cout << "Prezzo: " << temp->prezzo << endl;
		temp = temp->next;
		cout << "----------------------" << endl;
	}
}

bool VisualizzaSpecifico(string Cercato){
	bool trovato = false;
	El* temp = Primo;
	while(temp!=NULL){
		if(temp->categoria == Cercato){
			trovato = true;
		cout << "Prodotto: " << temp->prodotto << endl;
		cout << "Quantita': " << temp->quantita << endl;
		cout << "Prezzo: " << temp->prezzo << endl;
		cout << "----------------------" << endl;
		}
		temp = temp->next;
	}
	return trovato;
}

bool VisualizzaSottoSoglia(int Soglia){
	bool trovato = false;
	El* temp = Primo;
	while(temp!=NULL){
		if(temp->quantita < Soglia){
			trovato = true;
		cout << "Prodotto: " << temp->prodotto << endl;
		cout << "Quantita': " << temp->quantita << endl;
		cout << "Prezzo: " << temp->prezzo << endl;
		cout << "----------------------" << endl;
		}
	temp = temp->next;
	}
	return trovato;
}

bool VisualizzaRange(int Min, int Max){
	El* temp = Primo;
	bool trovato = false;
	while(temp!=NULL){
		if(temp->prezzo >= Min && temp->prezzo <= Max){
			trovato = true;
		cout << "Prodotto: " << temp->prodotto << endl;
		cout << "Quantita': " << temp->quantita << endl;
		cout << "Prezzo: " << temp->prezzo << endl;
		cout << "----------------------" << endl;
		}
	temp = temp->next;
	}
	return trovato;
}

/* TODO (#1#): da completare */

void EstrazioneInTesta(int N){
	//string* prodotto = new string[N];
	El* temp = Primo;
	int i = 0;
	if(Primo == NULL){
		 return;	
		}
	while(i<N){
		
	}
}

bool EstrazioneInCoda(){
		if (Ultimo == NULL)
	return false;
	else if (Ultimo == Primo){
		delete Primo;
		Primo = NULL;
		Ultimo = NULL;
	} else {
		El* temp = Primo;
		/*while(temp->next != Ultimo)
			temp = temp->next;
			*/
		while(temp->next->next != NULL)
			temp = temp->next;
		delete Ultimo;
		Ultimo = temp;
		Ultimo->next = NULL;
		temp = NULL;
	}
	return true;
}






int main(){
	int N;
	cout << "Quanti elementi vuoi inserire?" << endl;
	cin >> N;
	while(N<0){
		cout << "Errore." << endl;
		cin >> N;
	}
	string Prodotto, Categoria;
	int Quantita;
	float Prezzo;
	for(int i = 0; i<N; i++){
		cout << i+1 << " - Prodotto" << endl << "    ";
		cin >> Prodotto;
		cout << i+1 << " - Categoria" << endl << "    ";
		cin >> Categoria;
		cout << i+1 << " - Quantità" << endl << "    ";
		cin >> Quantita;
		cout << i+1 <<" - Prezzo" << endl << "    ";
		cin >> Prezzo;
		InserimentoInCoda(Prodotto, Categoria, Quantita, Prezzo);
		
	}
	cout << "Prodotti inseriti: " << endl;
	Visualizza();
	
	int M;
	cout << "Quanti altri prodotti vuoi inserire?" << endl;
	cin >> M;
	while(M<0){
		cout << "Errore." << endl;
		cin >> M;
	}
	
	for(int i = 0; i<M; i++){
		cout << i+1 << " - Prodotto" << endl << "    ";
		cin >> Prodotto;
		cout << i+1 << " - Categoria" << endl << "    ";
		cin >> Categoria;
		cout << i+1 << " - Quantità" << endl << "    ";
		cin >> Quantita;
		cout << i+1 <<" - Prezzo" << endl << "    ";
		cin >> Prezzo;
		InserimentoInTesta(Prodotto, Categoria, Quantita, Prezzo);
		
	}
	cout << "Prodotti inseriti con quelli già esistenti: " << endl;
	Visualizza();
	
	string cCategoria; // Si occupa di cercare il prodotto interessato.
	cout << "Che categoria ti interessa cercare?" << endl;
	cin >> cCategoria;
	if(!VisualizzaSpecifico(cCategoria)){
		cout << "Nessun prodotto trovato per la categoria scelta!" << endl;
	}
	
	
	int soglia;
	cout << "Soglia" << endl;
	cin >> soglia;
	VisualizzaSottoSoglia(soglia);
	
	int rangeMin, rangeMax;
	cout << "Minimo: ";
	cin >> rangeMin;
	cout << endl << "Massimo: ";
	cin >> rangeMax;
	cout << endl;
	VisualizzaRange(rangeMin, rangeMax);
	
	
	
	
	
	
	Elimina();
}
