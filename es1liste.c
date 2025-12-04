#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int valore;
    struct nodo *next;
};

void inserimentoTesta(struct nodo **head, int val){
    //Inizializzo un nuovo nodo 'appoggio'
    struct nodo *appoggio = malloc(sizeof(struct nodo));
    appoggio->valore = val;
    appoggio->next = *head; //Il nuovo nodo (quello d mettere in cima alla lista) punterà al nodo puntato da head fino ad ora
    *head = appoggio; //Il nodo che punta ora head è 'appoggio', quello appena messo all'inizio
};

void inserimento(struct nodo *x, struct nodo *t){
    if( x!=NULL && t!=NULL ){
        t->next = x->next; //t punterà a quello puntato in precedenza da x
        x->next = t; //x punterà a t
    }
};

void inserimentoCoda(struct nodo **head, int val){
    //Inizializzazione del nuovo nodo
    struct nodo *nuovo = malloc(sizeof(struct nodo));
    nuovo->valore = val;
    nuovo->next = NULL; //Punta a NULL perché è l'ultimo elemento

    if( *head == NULL ){ //Se head non punta a nulla
        *head = nuovo; //head punta al nuovo elemento
    }
    else{
        struct nodo *temp = *head; //Inizializzo un nodo temporaneo che scorrerrà per tutto l'array fino alla fine, partendo dal nodo puntato da head (il primo)
        while( temp->next != NULL ){ //Fino a quando temp non diventa l'ultimo,
            temp = temp->next; //temp diventerà il nodo successivo a quello che è in quel momento
        }
        temp->next = nuovo; //nuovo diventa ora l'ultimo elemento
    }
};

void rimuovi(struct nodo **head, int val){
    struct nodo *temp = *head;
    struct nodo *prec = NULL;

    if( temp!=NULL && temp->valore==val ){ //Se il valore che si cerca è il primo, bisogna aggiornare il valore di head
        *head = temp->next; //head diventa il valore successivo a temp, il primo elemento che bisogna rimuovere
        free(temp); //Libero la memoria del nodo da eliminare
    }
    else{
        while( temp!=NULL && temp->valore!= val ){
            prec = temp;
            temp = temp->next;
        }
        if( temp==NULL ){
            printf("Nessun valore trovato");
        }
        else{
            prec->next = temp->next;
            free(temp);
        }
    }
};

void stampa(struct nodo **head){
    struct nodo *temp = *head;
    while( temp != NULL ){
        printf("%d   ", temp->valore);
        temp = temp->next;
    }
    printf("NULL \n");
};

void liberaLista(struct nodo **head) {
    struct nodo *temp = *head;
    struct nodo *next;

    while (temp != NULL) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
};

int sommaLista(struct nodo **head){
    struct nodo *temp = *head;
    int somma = 0;
    if(temp==NULL){
        somma = -1;
    }
    else{
        while( temp!=NULL ){
            somma += temp->valore;
            temp = temp->next;
        }
    }
    return somma;
};

float mediaLista(struct nodo **head){
    struct nodo *temp = *head;
    int somma = 0;
    int nNodi = 0;
    float media = -1;
    /* if(temp==NULL){
        media -1;
    } */
    while( temp!=NULL ){
        somma += temp->valore;
        temp = temp->next;
        nNodi++;
    }
    media = somma / nNodi;
    return media;
};

int main(){
    struct nodo *head = NULL;

    inserimentoTesta(&head, 20);
    inserimentoTesta(&head, 10);

    inserimentoCoda(&head, 30);
    inserimentoCoda(&head, 40);

    struct nodo *nuovo = malloc(sizeof(struct nodo));
    nuovo->valore = 25;
    nuovo->next = NULL;
    struct nodo *temp = head;
    while(temp != NULL && temp->valore != 20){
        temp = temp->next;
    }
    if(temp != NULL){
        inserimento(temp, nuovo);
    }

    printf("Lista dopo gli inserimenti:\n");
    stampa(&head);

    int somma = sommaLista(&head);
    float media = mediaLista(&head);

    printf("Somma degli elementi: %d\n", somma);
    printf("Media degli elementi: %.2f\n", media);

    rimuovi(&head, 30);
    printf("Lista dopo la rimozione di 30:\n");
    stampa(&head);

    liberaLista(&head);
    return 0;
}

/*
Esercizio 1:
Creare una Lista di valori interi. Successivamente creare delle funzioni che permettano di
sommare tutti gli elementi della lista e di fare la media tra di essi.
*/
