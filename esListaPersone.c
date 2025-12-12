#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Persona{
    char *nome;
    char *cognome;
    int eta;
    struct Persona *next;
};

void inserisciPersonaTesta(struct Persona **head, char *nome, char *cognome, int eta){
    struct Persona *temp = malloc(sizeof(struct Persona));
    temp->nome = (char*)malloc(strlen(nome)+1);
    temp->cognome = (char*)malloc(strlen(cognome)+1);
    strcpy( temp->nome, nome );
    strcpy( temp->cognome, cognome );
    temp->eta = eta;
    temp->next = *head;
    *head = temp;
};

void inserimentoPersonaCoda(struct Persona **head, char *nome, char *cognome, int eta){
    struct Persona *nuova = malloc(sizeof(struct Persona));
    nuova->nome = (char*)malloc(strlen(nome)+1);
    nuova->cognome = (char*)malloc(strlen(cognome)+1);
    strcpy( nuova->nome, nome );
    strcpy( nuova->cognome, cognome );
    nuova->eta = eta;
    nuova->next = NULL;
    if( *head==NULL ){
        *head = nuova;
    }
    else{
        struct Persona *temp = *head;
        while( temp->next!=NULL ){
            temp = temp->next;
        }
        temp->next = nuova;
    }
};

void rimozionePersonaNome(struct Persona **head, char *nome){
    struct Persona *temp = *head;
    if( temp!=NULL && strcmp(temp->nome, nome)==0 ){
        *head = temp->next;
        free(temp);
    }
    else{
        struct Persona *prec = NULL;
        while( temp!=NULL && strcmp(temp->nome, nome)!=0 ){
            prec = temp;
            temp = temp->next;
        }
        if( temp!=NULL ){
            prec->next = temp->next;
            free(temp);
        }
        else{
            printf("Nessuna persona con il nome specificato presente nella lista! \n");
        }
    }
};

void stampaListaPersone(struct Persona **head){
    struct Persona *temp = *head;
    while( temp!=NULL ){
        printf("\nNome: %s \nCognome: %s \nEta: %d \n", temp->nome, temp->cognome, temp->eta);
        temp = temp->next;
    }
    printf("\nNULL \n\n");
};

void stampaMaggiorenni(struct Persona **head){
    struct Persona *temp = *head;
    while( temp!=NULL ){
        if(temp->eta >= 18){
            printf("\nNome: %s \nCognome: %s \nEta: %d \n", temp->nome, temp->cognome, temp->eta);
        }
        temp = temp->next;
    }
    printf("\nNULL \n\n");
};

void stampaNome(struct Persona **head, char *nome){
    struct Persona *temp = *head;
    while( temp!=NULL ){
        if( strcmp(temp->nome, nome)==0 ){
            printf("\nNome: %s \nCognome: %s \nEta: %d \n", temp->nome, temp->cognome, temp->eta);
        }
        temp = temp->next;
    }
    printf("\nNULL \n\n");
};

int main(){
    struct Persona *headP = NULL;

    inserisciPersonaTesta(&headP, "Federico", "Pedretti", 17);
    inserimentoPersonaCoda(&headP, "Alessandro", "di Gioia", 18);
    inserimentoPersonaCoda(&headP, "Mirko", "Castorina", 19);
    inserimentoPersonaCoda(&headP, "Robert", "Concal", 17);

    printf("Stampa: \n");
    stampaListaPersone(&headP);

    printf("\n\nStampa maggiorenni: ");
    stampaMaggiorenni(&headP);

    printf("\n\nStampa nome (Mirko): ");
    stampaNome(&headP, "Mirko");

    printf("Stampa dopo rimozione Martino: \n");
    rimozionePersonaNome(&headP, "Martino");
    stampaListaPersone(&headP);

    printf("Stampa dopo rimozione Mirko: \n");
    rimozionePersonaNome(&headP, "Mirko");
    stampaListaPersone(&headP);

    return 0;
}

/*
Riprendere la struct Persona e creare una lista di persone.
Devono essere implementate le seguenti funzionalità:
Inserimento di una persona
rimozione di una persona
stampa di tutte le persone
stampa delle persone maggiorenni
Stampa delle persone con un nome specifico scelto dall’utente
*/
