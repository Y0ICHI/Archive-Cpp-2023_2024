#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Elemento {
    int dato;
    Elemento *next;
};

Elemento *Testa = NULL;

void Aggiunta(Elemento *&Testa) {
    Elemento *corrente = new Elemento;
    cout << "Inserisci un valore: ";
    cin >> corrente->dato;
    corrente->next = NULL;

    if (Testa == NULL) {
        Testa = corrente; // controllo lista se è vuota, il nuovo elemento diventa la testa
    } else {
        Elemento *temp = Testa;
        while (temp->next != NULL) {
            temp = temp->next; // Trova l'ultimo elemento
        }
        temp->next = corrente; // Aggiungi il nuovo elemento in coda
    }
}

int Somma(Elemento *Testa, int M) {
    if (Testa == NULL) {
        return -1; // Lista vuota
    }

    int somma = 0;
    Elemento *corrente = Testa;
    while (corrente != NULL) {
        if (corrente->dato % M == 0) {
            somma += corrente->dato; // Somma solo i multipli di M
        }
        corrente = corrente->next;
    }
    return somma;
}

void EliminaNonMultipli(Elemento *&Testa, int M) {
    Elemento *corrente = Testa;
    Elemento *precedente = NULL;

    while (corrente != NULL) {
        if (corrente->dato % M != 0) {
            // Se l'elemento non è un multiplo di M, si elimina
            if (precedente == NULL) {
                // Se è il primo elemento
                Testa = corrente->next;
                delete corrente;
                corrente = Testa;
            } else {
                // Se non è il primo elemento
                precedente->next = corrente->next;
                delete corrente;
                corrente = precedente->next;
            }
        } else {
            precedente = corrente;
            corrente = corrente->next;
        }
    }
}

void Visualizza(Elemento *EL) {
    Elemento *corrente = EL;
    while (corrente != NULL) {
        cout << corrente->dato << " ";
        corrente = corrente->next;
    }
    cout << endl;
}

int main() {
    int M;
    cout << "Inserisci il valore di M: ";
    cin >> M;

    // Aggiunta di elementi alla lista
    for (int i = 0; i < 5; i++) { // Aggiunta 5 elementi casualmente
        Aggiunta(Testa);
    }

    cout << "Lista iniziale: ";
    Visualizza(Testa);

    // Calcolo della somma dei multipli di M
    int somma = Somma(Testa, M);
    if (somma != -1) {
        cout << "Somma dei multipli di " << M << ": " << somma << endl;
    } else {
        cout << "La lista è vuota." << endl;
    }

    // Eliminazione degli elementi non multipli di M
    EliminaNonMultipli(Testa, M);
    cout << "Lista dopo l'eliminazione: ";
    Visualizza(Testa);

    return 0;
}
