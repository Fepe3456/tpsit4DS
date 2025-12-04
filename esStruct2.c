#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char* nome;
    char* cognome;
    int voti[5];
    float media;
}Studente;

void inizializzaStudenti(Studente *pstudente);
float calcolaMedia(Studente *pstudente);
Studente studenteMigliore(Studente *pArrayStudenti);
void stampaStudente(Studente *pstudente);

int main()
{
    Studente studenti[4], migliore;
    Studente *ps = &studenti[0], *psm = &migliore;

    inizializzaStudenti(ps);

    migliore = studenteMigliore(ps);

    for(int i=0; i<4; i++){
        printf("\n\nSTUDENTE %d", i+1);
        stampaStudente(ps);
        if(i!=4-1){
            ps++;
        }
    }

    printf("\n\n\nSTUDENTE MIGLIORE:");
    stampaStudente(psm);


    return 0;
}

void inizializzaStudenti(Studente *pstudente){
//pstudente->nome = (char*)malloc(50*sizeof(char));
//pstudente->nome = (char*)malloc(50*sizeof(char));

    //      STUDENTE 1      //
    pstudente->nome = "Nome1";
    pstudente->cognome = "Cognome1";
    pstudente->voti[0] = 8;
    pstudente->voti[1] = 5;
    pstudente->voti[2] = 6;
    pstudente->voti[3] = 7;
    pstudente->voti[4] = 7;
    pstudente->media = calcolaMedia(pstudente);

    //      STUDENTE 2      //
    pstudente++;
    pstudente->nome = "Nome2";
    pstudente->cognome = "Cognome2";
    pstudente->voti[0] = 8;
    pstudente->voti[1] = 8;
    pstudente->voti[2] = 7;
    pstudente->voti[3] = 7;
    pstudente->voti[4] = 8;
    pstudente->media = calcolaMedia(pstudente);

    //      STUDENTE 3      //
    pstudente++;
    pstudente->nome = "Nome3";
    pstudente->cognome = "Cognome3";
    pstudente->voti[0] = 6;
    pstudente->voti[1] = 5;
    pstudente->voti[2] = 4;
    pstudente->voti[3] = 6;
    pstudente->voti[4] = 5;
    pstudente->media = calcolaMedia(pstudente);

    //      STUDENTE 4      //
    pstudente++;
    pstudente->nome = "Nome4";
    pstudente->cognome = "Cognome4";
    pstudente->voti[0] = 7;
    pstudente->voti[1] = 9;
    pstudente->voti[2] = 10;
    pstudente->voti[3] = 9;
    pstudente->voti[4] = 8;
    pstudente->media = calcolaMedia(pstudente);
}

float calcolaMedia(Studente *pstudente){
    float media = 0;
    for(int i=0; i<5; i++){
        media = media + pstudente->voti[i];
    }
    return media/5;
}

Studente studenteMigliore(Studente *pArrayStudenti){
    Studente *migliore = &pArrayStudenti[0];
    for(int i=1; i<4; i++){
        pArrayStudenti++;
        if( pArrayStudenti->media > migliore->media ){
            migliore = pArrayStudenti;
        }
    }
    return *migliore;
}

void stampaStudente(Studente *pstudente){
    printf("\nNome: %s \nCognome: %s \nMedia: %f \nVoti: \n     [ ", pstudente->nome, pstudente->cognome, pstudente->media);
    for(int i=0; i<5; i++){
        if( i==5-1 ){
            printf("%d ]", pstudente->voti[i]);
        }
        else{
           printf("%d, ", pstudente->voti[i]);
        }
    }
}

/*
Consegna:
Sviluppa un sistema per gestire il registro di una classe. Definisci una struct Studente con:
nome e cognome (stringhe)
array di 5 voti (interi)
media (float)
Implementa le funzioni:
calcolaMedia() - calcola e restituisce la media dei voti di uno studente
studenteMigliore() - trova e restituisce lo studente con la media più alta
stampaStudente() - visualizza tutti i dati di uno studente
Nel main, crea un array di 4 studenti con voti a piacere, calcola le medie di tutti gli studenti, stampa i loro dati e identifica lo studente con la media più alta.
*/
