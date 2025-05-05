#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

struct scarpe {
    string marca;
    string modello;
    int quantita;
    float prezzo;
    scarpe* next;
}; 

scarpe *primo = NULL, *ultimo = NULL;

void visualizza() {
    scarpe* current = primo;
    cout << "Lista delle scarpe:" << endl;
    while (current != NULL) {
        cout << "Marca: " << current->marca << ", "
             << "Modello: " << current->modello << ", "
             << "Quantità: " << current->quantita << ", "
             << "Prezzo: " << current->prezzo << endl;
        current = current->next;
    }
}

bool Aggiunta(string newMarca, string newModello, int newQuantita, float newPrezzo, scarpe * &ultimo) {
    // Creazione nuovo nodo
    scarpe *nuovaScarpa = new scarpe;
    if (nuovaScarpa == NULL) {
        return false;
    }

    // Assegnamento dei valori al nuovo nodo
    nuovaScarpa->marca = newMarca;
    nuovaScarpa->modello = newModello;
    nuovaScarpa->quantita = newQuantita;
    nuovaScarpa->prezzo = newPrezzo;

    // Inserimento nuovo nodo in testa alla lista
    nuovaScarpa->next = primo;
    primo = nuovaScarpa;

    // Se la lista era vuota, aggiornamento ultimo
    if (ultimo == NULL) {
        ultimo = nuovaScarpa;
    }

    return true;
}

void eliminaScarpeConQuantitaZero() {
    scarpe* current = primo;
    scarpe* prev = NULL;

    while (current != NULL) {
        if (current->quantita == 0) {
            if (prev == NULL) {
                primo = current->next;
                
                if (current == ultimo) {
                    ultimo = NULL;
                }
                delete current;
                current = primo;
            } else {
                prev->next = current->next;
                
                if (current == ultimo) {
                    ultimo = prev;
                }
                delete current;
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void visualizzaModelliDiMarca(const string& marca) {
    scarpe* current = primo;
    cout << "Modelli della marca " << marca << ":" << endl;
    bool found = false;
    while (current != NULL) {
        if (current->marca == marca) {
            cout << "Modello: " << current->modello << endl;
            found = true;
        }
        current = current->next;
    }
    if (!found) {
        cout << "Nessun modello trovato per la marca " << marca << "." << endl;
    }
}

void visualizzaQuantitaPrezzoInferiore(float soglia) {
    scarpe* current = primo;
    int quantitaTotale = 0;
    cout << "Modelli con prezzo inferiore a " << soglia << ":" << endl;
    while (current != NULL) {
        if (current->prezzo < soglia) {
            cout << "Modello: " << current->modello << ", Quantità: " << current->quantita << endl;
            quantitaTotale += current->quantita;
        }
        current = current->next;
    }
    cout << "Quantità totale dei modelli con prezzo inferiore a " << soglia << ": " << quantitaTotale << endl;
}

int main() {
    short n = 0;
    int numScarpe;
    string marca, modello;
    int quantita;
    float prezzo;

    cout << "Quante scarpe vuoi inserire?" << endl;
    cin >> numScarpe;
    while (numScarpe < 0) {
        cout << "Errore." << endl;
        cin >> numScarpe;
    }
    
    while (n < numScarpe) {
        n++;
        if (n == 1) {
            primo = new scarpe;
            if (primo == NULL)
                return -1;

            cout << n << " - Inserisci la marca: ";
            cin >> primo->marca;
            cout << n << " - Inserisci il modello: ";
            cin >> primo->modello;
            cout << n << " - Inserisci il quantita': ";
            cin >> primo->quantita;
            cout << n << " - Inserisci il prezzo: ";
            cin >> primo->prezzo;
            primo->next = NULL;
            ultimo = primo;
        } else {
            ultimo->next = new scarpe;
            if (ultimo->next == NULL)
                return -1;

            ultimo = ultimo->next;

            cout << n << " - Inserisci la marca: ";
            cin >> ultimo->marca;
            cout << n << " - Inserisci il modello: ";
            cin >> ultimo->modello;
            cout << n << " - Inserisci il quantita': ";
            cin >> ultimo->quantita;
            cout << n << " - Inserisci il prezzo: ";
            cin >> ultimo->prezzo;
            ultimo->next = NULL;
        }
    }
    
    bool risultato;
    n++;
    cout << "Inserire la nuova scarpa." << endl;
    cout << n << " - Inserisci la marca: ";
    cin >> marca;
    cout << n << " - Inserisci il modello: ";
    cin >> modello;
    cout << n << " - Inserisci il quantita': ";
    cin >> quantita;
    cout << n << " - Inserisci il prezzo: ";
    cin >> prezzo;
    
    risultato = Aggiunta(marca, modello, quantita, prezzo, ultimo);
    
    eliminaScarpeConQuantitaZero();
    
    visualizza();
    visualizzaModelliDiMarca(marca);
    
    float soglia;
    cout << "Inserire una soglia." << endl;
    cin >> soglia;
    visualizzaQuantitaPrezzoInferiore(soglia);
    
    scarpe* current = primo;
    while (current != NULL) {
        scarpe* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
