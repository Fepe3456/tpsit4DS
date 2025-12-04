#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char *stringa = malloc(100 * sizeof(char));
    char *p;
    bool solo_lettere = true, maiuscolo=true, minuscolo=true;
    printf("Inserisci una stringa: ");
    fgets(stringa, 100, stdin);
    printf("Hai inserito: %s", stringa);

    //Se la stringa non è formata da solo lettere, la ristampo così
    //Se la stringa è formata da sole lettere
        //Se tutta la stringa è maiuscola, convertire in minuscola
        //Se tutta la stringa è minuscola, convertire in maiuscola
        //Se la stringa è mista, i caratteri in posizione pari diventano zero 0

    for(p = stringa; *p != '\n'; p++){

        if( !((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) ){
            solo_lettere = false;
            break;
        }
        if( *p >= 'a' && *p <= 'z' ){
            maiuscolo = false;
        }
        if( *p >= 'A' && *p <= 'Z' ){
            minuscolo = false;
        }

    }

    printf("Stringa originale: %s", stringa);
    if(!solo_lettere){
        printf("Stringa modificata: %s", stringa);
    }
    else{
        if(maiuscolo){
            for(p = stringa; *p != '\n'; p++){
                if(*p >= 'A' && *p <='Z'){
                    *p += 32;
                }
            }
            printf("Stringa modificata: %s", stringa);
        }
        else if(minuscolo){
            for(p = stringa; *p != '\n'; p++){
                if(*p >= 'a' && *p <='z'){
                    *p -= 32;
                }
            }
            printf("Stringa modificata: %s", stringa);
        }
        else{
            int i=0;
            for(p = stringa; *p != '\n'; p++){
                if(i % 2 == 0){
                    *p = '0';
                }
                i++;
            }
            printf("Stringa modificata: %s", stringa);
        }
    }

    free(stringa);
    return 0;

}

/*
    Realizzare un programma che data una stringa di dimensione a piacere stampi a video se la stringa è formata da solo lettere e se in caso affermativo stampi se la stringa è tutta maiuscola,
    tutta minuscola o mista. In caso la stringa sia maiuscola convertirla in minuscolo, in caso la stringa sia minuscola convertirla in maiuscolo.
    Qualora la stringa fosse mista sostituire i caratteri nelle posizioni pari con 0. Stampare poi a video la stringa originale e quella post modifiche.
    Se la stringa di principio conteneva altri caratteri oltre alle lettere stampare semplicemente la stringa senza modifiche.  Utilizzare l’aritmetica dei puntatori per lo svolgimento dell’esercizio.
*/
