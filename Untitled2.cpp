void InserimentoInCoda(string elemento){
	El *temp = new El;
	temp->elemento = elemento;
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

bool inserimentoTesta(string elemento){
	elemento *temp = new elemento;
	if(temp==NULL){
		return false;
	}
	temp->elemento = elemento;
	temp->next = NULL;
	temp->prev = NULL;
	if(primo==NULL){
		ultimo = temp;
	}else{
		primo->prev = temp;
		temp->next = primo;
	}
	primo = temp;
	temp = NULL;
	return true;
}

void VisualizzaDaCoda(){
	volo *temp = Ultimo;
	while(temp!=NULL){
		cout << "Elemento: " << temp->elemento << endl;
		temp = temp->prev;
	}
	return;
}

void VisualizzaDaTesta(){
	El *temp = Primo;
	while(temp!=NULL){
		cout << "Elemento: " << temp->elemento << endl;
		temp = temp->next;
	}
}

bool EstrazioneInCoda(){
	if ( ultimo == NULL )     // la lista Ã¨ vuota
		return false;
	else if (ultimo == primo){ // la lista contiene solo un elemento
		delete primo;
		primo = NULL;
		ultimo = NULL;
	}else{
		elemento * temp = primo;
		while (temp->next != ultimo){
	 		temp = temp->next;
	 	}
		delete ultimo;
		ultimo = temp;
		ultimo->next = NULL;
		temp = NULL;
	}
	return true;
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

bool Ricerca_e_Rimuovi(string cercato){
    volo *temp = Primo;
    volo *tempPrec = NULL;

    if (temp == NULL) {  // la lista è vuota
        return false;
    } else {
        while (temp != NULL && temp->elemento != cercato) {
            tempPrec = temp;
            temp = temp->next;
        }
        if (temp != NULL && temp->elemento == cercato) {
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
