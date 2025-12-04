#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    char *titolo;
    char *autore;
    int anno;
    bool disponibilita;
}Libro;

void inizializzaLibro(Libro *puntatoreLibro, char newT[], char newAutore[], int newAnno, bool newDisp);
void prestaLibro(Libro *puntatoreLibro);
void restituisciLibro(Libro *puntatoreLibro);
void stampaLibro(Libro *puntatoreLibro);

int main()
{
    Libro libri[3];
    Libro *pl = &libri[0];

    //      PRIMO LIBRO         //
    inizializzaLibro(pl, "titolo1", "autore1", 2001, true);
    prestaLibro(pl);
    stampaLibro(pl);
    pl++;

    //      SECONDO LIBRO         //
    inizializzaLibro(pl, "titolo2", "autore2", 2002, false);
    restituisciLibro(pl);
    stampaLibro(pl);
    pl++;

    //      TERZO LIBRO         //
    inizializzaLibro(pl, "titolo3", "autore3", 2003, true);
    stampaLibro(pl);

    for(pl = &libri[0]; pl < libri + 3; pl++){
        free(pl->titolo);
        free(pl->autore);
    }

    return 0;
}

void inizializzaLibro(Libro *puntatoreLibro, char newT[], char newAutore[], int newAnno, bool newDisp){
    puntatoreLibro->titolo = (char*)malloc((strlen(newT)+1)*sizeof(char));
    puntatoreLibro->autore = (char*)malloc((strlen(newAutore)+1)*sizeof(char));
    strcpy(puntatoreLibro->titolo, newT);
    strcpy(puntatoreLibro->autore, newAutore);
    puntatoreLibro->anno = newAnno;
    puntatoreLibro->disponibilita = newDisp;
}

void prestaLibro(Libro *puntatoreLibro){
    if( puntatoreLibro->disponibilita ){
        puntatoreLibro->disponibilita = false;
    }
}

void restituisciLibro(Libro *puntatoreLibro){
    if( !(puntatoreLibro->disponibilita) ){
        puntatoreLibro->disponibilita = true;
    }
}

void stampaLibro(Libro *puntatoreLibro){
    printf("\n\nTitolo: %s \nAutore: %s \nAnno pubblicazione: %d \nDisponibilita': %d", puntatoreLibro->titolo, puntatoreLibro->autore, puntatoreLibro->anno, puntatoreLibro->disponibilita);
}


/*
Consegna:
Crea un programma per gestire il catalogo di una biblioteca. Definisci una struct Libro che contenga i seguenti campi:
titolo (stringa)
autore (stringa)
anno di pubblicazione (intero)
disponibilità (intero: 1 per disponibile, 0 per prestato)
Implementa le seguenti funzioni:
inizializzaLibro() - per impostare i dati di un libro
prestaLibro() - per prestare un libro (se disponibile)
restituisciLibro() - per restituire un libro prestato
stampaLibro() - per visualizzare tutte le informazioni di un libro
Nel main, crea un array di 3 libri, inizializzali con dati a piacere, e testa tutte le funzioni effettuando alcuni prestiti e restituzioni.

*/

