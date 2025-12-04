#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char *nome;
    char *cognome;
    char *scuola;
    int anno;
    char sezione;
} Studente;

typedef struct {
    char *nomeCorso;
    char *codiceCorso;
    int maxStudenti;
    int studentiIscritti;
    Studente *studenti;
} Corso;

void inizializzaCorso(Corso *pCorso, char *nomeCorso, char *codiceCorso, int maxStudenti);
void inizializzaStudente(Studente *pStudente, char *nome, char *cognome, char *scuola, int anno, char sezione);
void stampaStudente(Studente *pStudente);
void iscriviStudente(Corso *pCorso, Studente *pStudente);
void cancellaIscrizione(Corso *pCorso, Studente *pStudente);
void stampaCorso(Corso *pCorso);
bool corsoAffolato(Corso *pCorso);

int main()
{
    Corso corsi[3], *pCorso = &corsi[0];
    Studente s1, s2, s3,  *ps1=&s1, *ps2=&s2, *ps3=&s3;

    inizializzaCorso(&corsi[0], "Informatica", "INF01", 3);
    inizializzaCorso(&corsi[1], "Matematica", "MAT02", 2);
    inizializzaCorso(&corsi[2], "Fisica", "FIS03", 2);

    inizializzaStudente(ps1, "Mario", "Rossi", "ITT", 4, 'A');
    inizializzaStudente(ps2, "Luigi", "Verdi", "ITT", 4, 'B');
    inizializzaStudente(ps3, "Anna", "Bianchi", "ITT", 4, 'C');

    int scelta;
    do {
        printf("\n\n1. Iscrivi Studente\n2. Cancella Iscrizione\n3. Stampa Corso\n4. Corso Sovraffollato\n0. Esci\nScelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                iscriviStudente(pCorso, ps1);
                iscriviStudente(pCorso, ps2);
                iscriviStudente(pCorso, ps3);
                break;
            case 2:
                cancellaIscrizione(pCorso, ps2); // Cancella secondo studente
                break;
            case 3:
                stampaCorso(pCorso);
                break;
            case 4:
                if( corsoAffolato(pCorso) ){
                    printf("Il corso ha raggiunto il limite delle iscrizioni!");
                }
                else{
                    printf("Il corso NON ha ancora raggiunto il limite delle iscrizioni!");
                }
                break;
            default:
                printf("Opzione non valida!");
                break;
        }
    } while (scelta != 0);

    return 0;
}

void inizializzaCorso(Corso *pCorso, char *nomeCorso, char *codiceCorso, int maxStudenti){
    pCorso->studenti = malloc(maxStudenti * sizeof(Studente));
    pCorso->nomeCorso = (char*)malloc((strlen(nomeCorso)+1)*sizeof(char));
    pCorso->codiceCorso = (char*)malloc((strlen(codiceCorso)+1)*sizeof(char));
    strcpy(pCorso->nomeCorso, nomeCorso);
    strcpy(pCorso->codiceCorso, codiceCorso);
    pCorso->maxStudenti = maxStudenti;
    pCorso->studentiIscritti = 0;
}

void inizializzaStudente(Studente *pStudente, char *nome, char *cognome, char *scuola, int anno, char sezione){
    pStudente->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
    pStudente->cognome = (char*)malloc((strlen(cognome)+1)*sizeof(char));
    pStudente->scuola = (char*)malloc((strlen(scuola)+1)*sizeof(char));
    strcpy(pStudente->nome, nome);
    strcpy(pStudente->cognome, cognome);
    strcpy(pStudente->scuola, scuola);
    pStudente->anno = anno;
    pStudente->sezione = sezione;
}

void iscriviStudente(Corso *pCorso, Studente *pStudente){
    int i = pCorso->studentiIscritti;
    if(pCorso->studentiIscritti < pCorso->maxStudenti){
        pCorso->studenti[i].nome = (char*)malloc((strlen(pStudente->nome)+1)*sizeof(char));
        pCorso->studenti[i].cognome = (char*)malloc((strlen(pStudente->cognome)+1)*sizeof(char));
        pCorso->studenti[i].scuola = (char*)malloc((strlen(pStudente->scuola)+1)*sizeof(char));
        strcpy(pCorso->studenti[i].nome, pStudente->nome);
        strcpy(pCorso->studenti[i].cognome, pStudente->cognome);
        strcpy(pCorso->studenti[i].scuola, pStudente->scuola);
        pCorso->studentiIscritti++;
    }

}

void cancellaIscrizione(Corso *pCorso, Studente *pStudente){
    bool trovato = false;
    for(int i=0; i<pCorso->studentiIscritti; i++){
        if (strcmp(pCorso->studenti[i].nome, pStudente->nome) == 0 && strcmp(pCorso->studenti[i].cognome, pStudente->cognome) == 0 &&
            strcmp(pCorso->studenti[i].scuola, pStudente->scuola) == 0 && pCorso->studenti[i].anno == pStudente->anno &&
            pCorso->studenti[i].sezione == pStudente->sezione){
                trovato = true;
        }
        if(trovato && i!=pCorso->studentiIscritti-1 ){
            pCorso->studenti[i] = pCorso->studenti[i+1];
        }
    }
    pCorso->studentiIscritti--;
}

void stampaCorso(Corso *pCorso){
    printf("Il corso %s (codice: %s) attualmente ha %d studenti iscritti (massimo iscrizioni: %d)", pCorso->nomeCorso, pCorso->codiceCorso, pCorso->studentiIscritti, pCorso->maxStudenti);
    for(int i=0; i<pCorso->studentiIscritti; i++){
        printf("\n     ");
        stampaStudente(&(pCorso->studenti[i]));
    }
}
void stampaStudente(Studente *pStudente){
    printf("Lo studente %s %s frequenta la scuola %s nella classe %d%d", pStudente->nome, pStudente->cognome, pStudente->scuola, pStudente->anno, pStudente->sezione);
}

bool corsoAffolato(Corso *pCorso){
    if(pCorso->maxStudenti>=pCorso->studentiIscritti){
        return true;
    }
    else{
        return false;
    }
}


/*
Crea un programma per la gestione dei dati di una scuola. Definisci una struct Corso che contenga:
    nome del corso (stringa)
    codice del corso (stringa)
    numero di studenti iscritti (intero)
    numero massimo di studenti (intero)
Implementa le seguenti funzioni:
    iscriviStudente() - iscrive uno studente a un corso se non è al completo.
    cancellaIscrizione() - cancella l'iscrizione di uno studente da un corso.
    stampaCorso() - visualizza i dati di un corso.
    corsoSovraffollato() - restituisce true se il corso è al completo, false altrimenti.
Nel main, crea un array di 3 corsi, prova ad iscrivere e cancellare studenti, e stampa lo stato dei corsi.

*/
