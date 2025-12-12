#include <stdio.h>
#include <stdlib.h>

typedef struct Prodotto{
   char *nome;
   float prezzo;
   struct Prodotto *next;
};

struct Prodotto* aggiungiProdotto(struct Prodotto **head, char *nome, float prezzo){
    if (*head == NULL) {
        inserimentoTesta(&head, nome, prezzo);
    }else{
        struct Prodotto *corrente = *head;
        struct Prodotto *prec = NULL;
        float min = corrente->prezzo, max = corrente->prezzo;
        while( corrente!=NULL ){
            if( corrente->prezzo > max ){
                max = corrente->prezzo;
            }
            else if( corrente->prezzo < min ){
                min = corrente->prezzo;
            }
            prec = corrente;
            corrente = corrente->next;
        }
        if( prezzo <= min ){
            inserimentoTesta(head, nome, prezzo);
        }
        else if( prezzo > max ){
            inserimentoCoda(head, nome, prezzo);
        }
        else{
            corrente = *head;
            while( prec->prezzo > corrente->prezzo ){
                prec = corrente;
                corrente = corrente->next;
            }
            inserimentoCentro(prec, nome, prezzo);
        }
    }
    return head;
};

void inserimentoCentro(struct Prodotto *prec, char *nome, float prezzo){
    struct Prodotto *nuovo = malloc(sizeof(struct Prodotto));
    nuovo->nome = (char*)malloc(strlen(nome)+1);
    strcpy( nuovo->nome, nome );
    nuovo->prezzo = prezzo;
    nuovo->next = prec->next;
    prec->next = nuovo;
};

void inserimentoTesta(struct Prodotto **head, char *nome, float prezzo){
    struct Prodotto *temp = malloc(sizeof(struct Prodotto));
    temp->nome = (char*)malloc(strlen(nome)+1);
    strcpy( temp->nome, nome );
    temp->prezzo = prezzo;
    temp->next = *head;
    *head = temp;
};

void inserimentoCoda(struct Prodotto **head, char *nome, float prezzo){
    struct Prodotto *nuova = malloc(sizeof(struct Prodotto));
    nuova->nome = (char*)malloc(strlen(nome)+1);
    strcpy( nuova->nome, nome );
    nuova->prezzo = prezzo;
    nuova->next = NULL;
    if( *head==NULL ){
        *head = nuova;
    }
    else{
        struct Prodotto *temp = *head;
        while( temp->next!=NULL ){
            temp = temp->next;
        }
        temp->next = nuova;
    }
};

void stampa(struct Prodotto **head){
    struct Prodotto *temp = *head;
    while( temp!=NULL ){
        printf("\nNome prodotto: %s \nPrezzo: %f", temp->nome, temp->prezzo);
        temp = temp->next;
    }
    printf("\nNULL \n\n");
};


int main(){
    struct Prodotto *head = NULL;
    head = aggiungiProdotto(&head, "a", 4);
    head = aggiungiProdotto(&head, "b", 2);
    head = aggiungiProdotto(&head, "c", 3);
    head = aggiungiProdotto(&head, "d", 5);
    stampa(&head);
    return 0;
}

/*
Realizza una lista semplicemente concatenata in cui ogni nodo contiene una struttura Prodotto composta da nome e prezzo.
La lista deve rimanere ordinata in senso crescente per prezzo.

Implementa una funzione che:

    riceve in ingresso un nuovo Prodotto;
    percorre la lista usando due puntatori (precedente e corrente);
    individua la posizione corretta confrontando i prezzi;
    gestisce correttamente i tre casi:
    inserimento in testa,
    inserimento in mezzo,
    inserimento in coda;
    restituisce la nuova testa della lista.
*/
