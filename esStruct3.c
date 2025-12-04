#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char* nome;
    char* cognome;
    char* mansione;
    float stipendio;
    int anniEsperienza;
}Dipendente;

void inizializzaDipendente(Dipendente *pd, char* n, char* c, char* m, float s, int ae);
void aumentaStipendio(Dipendente *pd);
void promuoviDipendente(Dipendente *pd, char* newMansione);
void cercaPerMansione(Dipendente *pd, char* mansione, int dl);
void stampaDipendenti(Dipendente *pd, int dl);
void dipendenteToString(Dipendente *pd);

int main()
{
    char* nome = (char*)malloc(50*sizeof(char));
    char* cognome = (char*)malloc(50*sizeof(char));
    char* mansione = (char*)malloc(50*sizeof(char));
    float stipendio;
    int anniEsperienza, df;

    printf("Quanti dipendenti? ");
    scanf("%d", &df);
    getchar();

    Dipendente dipendenti[df];
    Dipendente *pd = &dipendenti[0];

    for(int i=0; i<df; i++){
        printf("\n\nDIPENDENTE %d", i+1);
        printf("\nNome: ");
        fgets(nome, 50, stdin);
        nome[strcspn(nome, "\n")] = '\0'; //Quando si usa fgets() viene sempre aggiunto \n alla fine e per toglierlo si fa così
        printf("\nCognome: ");
        fgets(cognome, 50, stdin);
        cognome[strcspn(cognome, "\n")] = '\0';
        printf("\nMansione: ");
        fgets(mansione, 50, stdin);
        mansione[strcspn(mansione, "\n")] = '\0';
        printf("\nStipendio: ");
        scanf("%f", &stipendio);
        printf("\nAnni esperienza: ");
        scanf("%d", &anniEsperienza);
        getchar();
        inizializzaDipendente(pd, nome, cognome, mansione, stipendio, anniEsperienza);
        pd++;
    }
    pd = &dipendenti[0];

    printf("\n\nFunzione promuoviDipendente(Dipendente *pd, char* newMansione)");
    for(int i=0; i<df; i++){
        printf("\nNuova mansione dipendente %s: ", pd->nome);
        fgets(mansione, 50, stdin);
        mansione[strcspn(mansione, "\n")] = '\0';
        promuoviDipendente(pd, mansione);
        pd++;
    }
    pd = &dipendenti[0];

    printf("\n\nFunzione cercaPerMansione(Dipendente *pd, char* mansione, int dl)");
    printf("\nMansione: ");
    fgets(mansione, 50, stdin);
    mansione[strcspn(mansione, "\n")] = '\0';
    cercaPerMansione(pd, mansione, df);
    pd = &dipendenti[0];

    printf("\n\nFunzione stampaDipendenti(Dipendente *pd, int dl)");
    stampaDipendenti(pd, df);
    pd = &dipendenti[0];


    for(int i=0; i<df; i++){
        free(pd->nome);
        free(pd->cognome);
        free(pd->mansione);
        pd++;
    }
    pd = &dipendenti[0];
    free(nome);
    free(cognome);
    free(mansione);


    return 0;
}

void inizializzaDipendente(Dipendente *pd, char* n, char* c, char* m, float s, int ae){
    pd->nome = malloc(strlen(n)+1);
    strcpy(pd->nome, n);
    pd->cognome = malloc(strlen(c)+1);
    strcpy(pd->cognome, c);
    pd->mansione = malloc(strlen(m)+1);
    strcpy(pd->mansione, m);
    pd->stipendio = s;
    pd->anniEsperienza = ae;
}

void aumentaStipendio(Dipendente *pd){
    if(pd->anniEsperienza > 10){
        pd->stipendio = pd->stipendio + (pd->stipendio * 15 / 100);
    }
    else if(pd->anniEsperienza > 5){
        pd->stipendio = pd->stipendio + (pd->stipendio * 10 / 100);
    }
    else if(pd->anniEsperienza > 2){
        pd->stipendio = pd->stipendio + (pd->stipendio * 5 / 100);
    }
}

void promuoviDipendente(Dipendente *pd, char* newMansione){
    free(pd->mansione);
    pd->mansione = malloc(strlen(newMansione)+1);
    strcpy(pd->mansione, newMansione);
    pd->stipendio = pd->stipendio + (pd->stipendio * 20 / 100);
}

void cercaPerMansione(Dipendente *pd, char* mansione, int dl){
    for(int i=0; i<dl; i++){
        if(strcmp(pd->mansione, mansione)==0){
            dipendenteToString(pd);
        }
        pd++;
    }
    //Ricordarsi di rimettere pd a pd=&dipendenti[0];
}

void stampaDipendenti(Dipendente *pd, int dl){
    for(int i=0; i<dl; i++){
        dipendenteToString(pd);
        pd++;
    }
    //Ricordarsi di rimettere pd a pd=&dipendenti[0];
}

void dipendenteToString(Dipendente *pd){
    printf("\nIl dipendente %s %s con mansione %s e %d anni di esperienza, ha uno stipendio di %f", pd->nome, pd->cognome, pd->mansione, pd->anniEsperienza, pd->stipendio);
}

/*
Consegna:
Realizza un programma per la gestione del personale di un'azienda. Definisci una struct Dipendente contenente:
nome e cognome
mansione
stipendio
anni di esperienza
Implementa le funzioni:
aumentoStipendio() - aumenta lo stipendio in base agli anni di esperienza:
2+ anni: +5%
5+ anni: +10%
10+ anni: +15%
promuoviDipendente() - cambia la mansione e aumenta lo stipendio del 20%
cercaPerMansione() - trova tutti i dipendenti con una specifica mansione
stampaDipendenti() - visualizza tutti i dipendenti
Nel main, crea un array di 5 dipendenti, applica gli aumenti di stipendio, promuovi almeno un dipendente, e mostra i risultati delle ricerche per mansione.

*/
