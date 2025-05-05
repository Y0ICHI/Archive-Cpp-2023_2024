//vatriante traccia originale, si modifica che l'utente inserisce anche la posizione
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

void Caricamento(int *V1, int &dim){
	cout << "Inserire la dimensione del vettore." << endl;
	cin >> dim;
	
	while(dim<=0){
		cout << "Errore." << endl;
	}
	
	for(int i = 0; i<dim; i++){
		cout << i+1 << " - Inserire il numero: ";
		cin >> *(V1+i);
		cout << endl;
	}
	return;
}

void VisualizzazioneVettore(int *V, int dim){
	for(int i = 0; i<dim; i++){
		cout << i+1 << " - " << *(V+i) << endl;
	}
	return;
}

void Duplicazione(int* V, int &dim, int *V2, int &dim2){
	int i, j;
	for (i = 0; i<dim2; i++){
		*(V2+i) = *(V+i);
	}
}

int Posizione(int *V, int& dim){
	int Pos;
	cout << "Dove vuoi inserire il nuovo valore di posizione?" << endl;
	cin >> Pos;
	while(Pos<1 || Pos > dim){
		cout << "Errore." << endl;
		cin >> Pos;
	}
	return Pos-1;
}

void AggiuntaElemento(int *V, int &dim, int *V2, int &dim2, int N){
	int i, j, l, num;
	dim2 = dim+N;
	for (i = 0; i<dim; i++){
		*(V2+i) = *(V+i);
	}
	j = i;
	for (i=0; i<N; i++){
		num = Posizione(V, dim2);
		cout << i+1 << " - Inserire il nuovo valore." <<endl;
		/* TODO (#1#): perchè non viene eseguito di nuovo??? non più grande di 2 i numeri da aggiungere?*/
		for(l = num; l<dim2; l++){
		*(V2+(l+1)) = *(V+l);
		//cout << "Fatto." << endl;
	}
	cout << "Prima:" << endl;
	VisualizzazioneVettore(V2, dim2);
		cin >> *(V2+num);
	cout << "Dopo:" << endl;
		VisualizzazioneVettore(V2, dim2);
	}
	dim+=N;
	return;
}


int Ricerca(int *V, int dim, int cercato){
	int trovato = -1;
	for(int i = 0; i<dim; i++){
		if (*(V+i) == cercato){
			trovato = i;
			cout << "true" << endl;
		}
	}
	return trovato;
}

void RimozioneElemento(int *V, int &dim, int *V2, int &dim2, int N){
    int elementiEliminati = 0;
    for(int k = 0; k < N; k++){
        int E;
        cout << "Inserisci l'elemento da eliminare: ";
        cin >> E;
        
        int vE = Ricerca(V, dim, E);
        
        if (vE == -1) {
            cout << "Elemento non trovato." << endl;
            //Permette di skippare le parti successive del ciclo, quindi in questo caso il ciclo e la riduzione della dimensione e vettore
            continue;
        }
		
		/* TODO (#1#): da correggere, ho utilizzato per sbaglio lo shift*/
        for (int i = vE; i < dim - 1; i++) {
            *(V+i) = *(V+(i+1));
        }

        dim--; // Riduce la dimensione del vettore
        elementiEliminati++;

        cout << "Elemento " << E << " eliminato." << endl;
    }

    if(elementiEliminati == 0) {
        cout << "Non \212 stato eliminato nessun elemento." << endl;
    } else {
        cout << "Sono stati eliminati " << elementiEliminati << " elementi." << endl;
    }

    // Aggiorna V2 e dim2
    for (int i = 0; i < dim; i++) {
        *(V2+i) = *(V+i);
    }
    dim2 = dim;
}

int main(){
	int dim, dim2;
	int* Vettore = new int[dim];
	cout << "Caricamento vettore: " << endl;
	Caricamento(Vettore, dim);
	//VisualizzazioneVettore(Vettore, dim);
	
	
	char SceltaAE;
	bool stop = false;
	char Scelta;
	while(stop == false){
	cout << "Vuoi aggiungere o eliminare elementi? \nA - Aggiungi \nE- Elimina \n\n(Il valore predefinito \212 A)." << endl;
	cin >> SceltaAE;
	SceltaAE = toupper(SceltaAE);
	if(SceltaAE !='A' and SceltaAE !='E'){
		SceltaAE = 'A';
	}
	//cout << "Scelta: " << SceltaAE << endl;
	int dim2, N;
	int* Vettore2 = new int[dim2];
	if(SceltaAE == 'A'){
		cout << "Quanti elementi vuoi inserire?" << endl;
		cin >> N;
		while(N<0){
			cout << "Errore." << endl;
			cin >> N;
		}
		AggiuntaElemento(Vettore, dim, Vettore2, dim2, N);
	} else {
		cout << "Quanti elementi vuoi eliminare?" << endl;
		cin >> N;
		while(N<0){
			cout << "Errore." << endl;
			cin >> N;
		}
		RimozioneElemento(Vettore, dim, Vettore2, dim2, N);
	}
	Duplicazione(Vettore2, dim2, Vettore, dim);
	cout << "Vuoi continuare a inserire elementi? \n(Il valore predefintio \212 N)." << endl;
	cin >> Scelta;
	Scelta = toupper(Scelta);
	if(Scelta !='Y' and Scelta !='N'){
		Scelta = 'N';
	}
	if(Scelta == 'N'){
		stop = true;
	}
	
	VisualizzazioneVettore(Vettore2, dim);
	
	}
	
	return 0;
}
