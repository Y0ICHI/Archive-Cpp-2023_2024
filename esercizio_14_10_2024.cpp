#include<iostream>
#include<string>
#include<cctype>
using namespace std;

void VisualizzaVettore(char* Vettore, int dim){
	for(int i = 0; i<dim; i++){
		cout << *(Vettore+i);
	}
	cout << endl;
}

void Maiuscolo(int dim, char* C){
	for(int i=0; i<dim; i++){
		*(C+i) = toupper(*(C+i));
	}
}

// 1 punto
void InvertiVettore(char* V1, int dim, char* V2) {
    for (int i = 0; i < dim; i++) {
        *(V2 + i) = *(V1 + (dim - 1 - i));
    }
}

bool check(char* V1, int dim, char* V2){
	bool checker = true;
	for(int i = 0; i<dim/2 && checker == true; i++){
		if(*(V1+i) != *(V1 + (dim - 1 -i))){
			checker = false;
		}
	}
	return checker;
}




//2 punto
void ConsonantiDoppie(char* Vettore, int dim, int* Pos, int& dim2){
	int i, j = 0;
	for(i = 0; i<dim; i++){
		if(*(Vettore+i)==*(Vettore+i+1)){
			if(*(Vettore+i) != 'A' && *(Vettore+i) != 'E' && *(Vettore+i) != 'I' && *(Vettore+i) != 'O' && *(Vettore+i) != 'U'){
			*(Pos+j++) = i;
			dim2--;
			//cout << "true" << endl;
			}
		}
	}
}

void EliminazioneConsonanti(char* V1, int dim, int* Pos, char* V2, int dim2){
	int j=0, l = 0;
	for(int i = 0; i<dim; i++){
		if(i==*(Pos+j)){
			i++;
			j++;
		}
		
		*(V2+l++) = *(V1+i);
	}
}
//2 punto

//3 punto
int Contadittonghi(char* Vettore, int dim){
	int C = 0;
	for(int i = 0; i<dim; i++){
		if ((Vettore[i] == 'A' || Vettore[i] == 'E' || Vettore[i] == 'I' || Vettore[i] == 'O' || Vettore[i] == 'U') && (Vettore[i + 1] == 'A' || Vettore[i + 1] == 'E' || Vettore[i + 1] == 'I' || Vettore[i + 1] == 'O' || Vettore[i + 1] == 'U')){
			C++;
		}
	}
	return C;
}
// 3 punto


int main(){
	int dim;
	cout << "Quanto \212 lunga la tua parola?" << endl;
	cin >> dim;
	while(dim<=0){
		cout << "Errore." << endl;
		cin >> dim;
	}
	char* Vettore = new char [dim];
	cout << "Inserire la parola" << endl;
	for(int i = 0; i<dim; i++){
		cin >> *(Vettore+i);
	}
	cout << endl;
	Maiuscolo(dim, Vettore);
	int dim2 = dim;
	
	// 1 punto
	char* Inverti = new char [dim];
	InvertiVettore(Vettore, dim, Inverti);
	VisualizzaVettore(Inverti, dim);
	if(check(Vettore, dim, Inverti)){
		cout << "La parola \212 Parindroma." << endl;
	}
	
	
	
	// 2 punto
	int* Pos = new int [dim2];
	char* NuovoVettore = new char [dim2];
	ConsonantiDoppie(Vettore, dim, Pos, dim2);
	EliminazioneConsonanti(Vettore, dim, Pos, NuovoVettore, dim2);
	Maiuscolo(dim, NuovoVettore);
	VisualizzaVettore(NuovoVettore, dim);
	// 2 punto
	
	
	// 3 punto
	int C = Contadittonghi(Vettore, dim);
	cout << "Ci sono " << C << " dittonghi/o nella parola." << endl;
	// 3 punto
}
