#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// STRUCTs //
typedef struct{
    char *titolo;
    char *autore;
    char *codiceISBN;
    int annoPubblicazione;
} Libro;

typedef struct{
    char *nome;
    Libro *libri;
    int nLibri;
} Biblioteca;


// DICHIARAZIONE FUNZIONI //
void inizializzaBiblioteca(Biblioteca *pb, Libro *libri, char *nome, int nLibri);
void inizializzaLibro(Libro *pl, char *newTitolo, char *newAutore, char *newCodiceISBN, int anno);
void stampaBiblioteca(Biblioteca *pb);
void stampaLibroDaIndice(Biblioteca *pb, int index);
void stampaLibroDaISBN(Biblioteca *pb, char *isbn);
void stampaLibriPerAnno(Biblioteca *pb, int anno1, int anno2);
void stampaLibro(Libro *pl);
void liberaMemoria(Biblioteca *pb);


// MAIN //
int main()
{
    int dfLibri=3, scelta, index, anno1, anno2;
    char *isbn = (char*)malloc(100*sizeof(char));
    Biblioteca biblioteca;
    Libro libri[dfLibri];
    Biblioteca *pb = &biblioteca;
    Libro *pl = &libri[0];

    inizializzaLibro(pl, "Il nome della Rosa", "Umberto Eco", "978-8845296833", 1980);
    pl++;
    inizializzaLibro(pl, "1984", "George Orwell", "978-8804719137", 1949);
    pl++;
    inizializzaLibro(pl, "Il Piccolo Principe", "Antoine de Saint-Exepery", "978-8854172388", 1943);
    pl++;
    pl = &libri[0]; //Riporto il puntatore all'inizio dell'array libri

    inizializzaBiblioteca(pb, pl, "Nome Biblioteca", dfLibri);

    /* OPPURE
    inizializzaLibro(&libri[0], "Il nome della Rosa", "Umberto Eco", "..ISBN..", 1980);
    inizializzaLibro(&libri[1], "1984", "George Orwell", "..ISBN..", 1949);
    inizializzaLibro(&libri[2], "Il Piccolo Principe", "Antoine de Saint-Exepery", "..ISBN..", 1943);
    */

    do{
        printf("\n\n== MENU BIBLIOTECA == \n1. Stampa tutta la biblioteca \n2. Stampa libro per indice \n3. Stampa libro per ISBN \n4. Stampa libro per anno \n0. Esci \nScelta: ");
        scanf("%d", &scelta);
        switch(scelta){
            case 1:
                stampaBiblioteca(pb);
                break;
            case 2:
                printf("Indice: ");
                scanf("%d", &index);
                stampaLibroDaIndice(pb, index);
                break;
            case 3:
                printf("ISBN: ");
                scanf("%s", isbn);
                stampaLibroDaISBN(pb, isbn);
                break;
            case 4:
                printf("Anno 1: ");
                scanf("%d", &anno1);
                printf("Anno 2: ");
                scanf("%d", &anno2);
                stampaLibriPerAnno(pb, anno1, anno2);
                break;
            case 0:
                printf("Exit...");
                break;
            default:
                printf("Opzione non valida!");
                break;
        }
    }while( scelta != 0);

    liberaMemoria(pb);
    free(isbn);

    return 0;
}

// IMPLEMENTAZIONE FUNZIONI //
void inizializzaBiblioteca(Biblioteca *pb, Libro *libri, char *nome, int nLibri){
    pb->nome = (char*)malloc((strlen(nome)+1)*sizeof(char));
    strcpy(pb->nome, nome);
    pb->nLibri = nLibri;
    pb->libri = (Libro*)malloc(nLibri * sizeof(Libro));
    for(int i=0; i<nLibri; i++){
        pb->libri[i] = libri[i];
    }
}

void inizializzaLibro(Libro *pl, char *newTitolo, char *newAutore, char *newCodiceISBN, int anno){
    pl->titolo = (char*)malloc((strlen(newTitolo)+1)*sizeof(char));
    pl->autore = (char*)malloc((strlen(newAutore)+1)*sizeof(char));
    pl->codiceISBN = (char*)malloc((strlen(newCodiceISBN)+1)*sizeof(char));
    pl->annoPubblicazione = anno;
    strcpy(pl->titolo, newTitolo);
    strcpy(pl->autore, newAutore);
    strcpy(pl->codiceISBN, newCodiceISBN);
}

void stampaBiblioteca(Biblioteca *pb){
    printf("\n=== BIBLIOTECA: %s ===", pb->nome);
    for(int i=0; i<pb->nLibri; i++){
        printf("\nLibro %d:", i);
        stampaLibro(&(pb->libri[i]));
    }
}

void stampaLibro(Libro *pl){
    printf("\nTitolo: %s \nAutore: %s \nAnno pubblicazione: %d \nISBN: %s\n", pl->titolo, pl->autore, pl->annoPubblicazione, pl->codiceISBN);
}

void stampaLibroDaIndice(Biblioteca *pb, int index){
    if( index < 0 || index >= pb->nLibri ){
        printf("Nessun libro con l'indice %d e' stato trovato!", index);
    }
    else{
        stampaLibro(&(pb->libri[index]));
    }
}
void stampaLibroDaISBN(Biblioteca *pb, char *isbn){
    bool trovato = false;
    for(int i=0; i<pb->nLibri; i++){
        if( strcmp(pb->libri[i].codiceISBN, isbn) == 0 ){
            stampaLibro(&(pb->libri[i]));
            trovato = true;
        }
    }
    if( !trovato ){
        printf("Nessun libro con codice ISBN %s e' stato trovato!", isbn);
    }
}
void stampaLibriPerAnno(Biblioteca *pb, int anno1, int anno2){
    bool trovatoAlmeno1 = false;
    if( anno1 > anno2 ){
        int temp = anno1;
        anno1 = anno2;
        anno2 = temp;
    }
    for(int i=0; i<pb->nLibri; i++){
        if( pb->libri[i].annoPubblicazione>=anno1 && pb->libri[i].annoPubblicazione<=anno2){
            stampaLibro(&(pb->libri[i]));
            trovatoAlmeno1 = true;
        }
    }
    if( !trovatoAlmeno1 ){
        printf("Nessun libro trovato con data compresa tra gli anni %d e %d", anno1, anno2);
    }
}

void liberaMemoria(Biblioteca *pb){
    for(int i=0; i < pb->nLibri; i++){
        free(pb->libri[i].titolo);
        free(pb->libri[i].autore);
        free(pb->libri[i].codiceISBN);
    }
    free(pb->nome);
    free(pb->libri);
}

/*
Si vuole progettare un programma che simuli la gestione di una Biblioteca. Quest’ultima è caratterizzata dal proprio nome e un elenco di libri.
Ogni Libro ha
    un titolo,
    un autore,
    un anno di pubblicazione e
    un codice ISBN.

Creare quindi le due Struct che servono a rappresentare quanto descritto sopra. Le funzionalità del programma sono le seguenti:

    stampa biblioteca → stampa il nome della biblioteca e tutti i libri contenuti all’interno di essa
    stampa libro da indice →  stampa le generalità del libro a seconda della posizione del vettore di libri contenuti nella biblioteca specificato
    stampa libro da ISBN → stampa le generalità del libro a seconda del codice ISBN che è stato specificato
    stampa libri per anno → stampa il nome di tutti i libri che hanno l’anno di pubblicazione compreso tra due anni scelti dall’utente.

Potete utilizzare altre funzioni oltre a quelle sopra descritte per creare la biblioteca, creare i libri e liberare la memoria.

Il main sarà così composto:
    All’utente verrà chiesto quale delle opzioni vuole selezionare tra quelle proposte.
    A ogni opzione numerica corrisponde la relativa funzione da chiamare.
    Il programma dovrà continuare a chiedere all’utente cosa vuole fare fino a quando non inserisce il valore 0. Quando questo accade il programma termina.

*/
