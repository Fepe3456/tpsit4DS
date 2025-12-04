#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int valore;
    struct nodo *next;
};

void inserimentoTesta(struct nodo **head, int val){
    struct nodo *appoggio = malloc(sizeof(struct nodo));
    appoggio->valore = val;
    appoggio->next = *head;
    *head = appoggio;
}

void inserimento(struct nodo *x, struct nodo *t){
    if(x!=NULL && t!=NULL){
        t->next = x->next;
        x->next = t;
    }
}

void inserimentoCoda(struct nodo **head, int val){
    struct nodo *nuovo = malloc(sizeof(struct nodo));
    nuovo->valore = val;
    nuovo->next = NULL;
    if(*head==NULL){
        *head = nuovo;
    } else {
        struct nodo *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nuovo;
    }
}

void rimuovi(struct nodo **head, int val){
    struct nodo *temp = *head;
    struct nodo *prec = NULL;
    if(temp!=NULL && temp->valore==val){
        *head = temp->next;
        free(temp);
    } else {
        while(temp!=NULL && temp->valore!=val){
            prec = temp;
            temp = temp->next;
        }
        if(temp==NULL){
            printf("Nessun valore trovato\n");
        } else {
            prec->next = temp->next;
            free(temp);
        }
    }
}

void stampa(struct nodo **head){
    struct nodo *temp = *head;
    while(temp != NULL){
        printf("%d   ", temp->valore);
        temp = temp->next;
    }
    printf("NULL\n");
}

void liberaLista(struct nodo **head){
    struct nodo *temp = *head;
    struct nodo *next;
    while(temp != NULL){
        next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
}

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

    rimuovi(&head, 30);

    printf("Lista dopo la rimozione di 30:\n");
    stampa(&head);

    liberaLista(&head);
    return 0;
}
