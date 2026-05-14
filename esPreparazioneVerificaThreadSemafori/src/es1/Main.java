package es1;

import java.util.Scanner;

public class Main {

    protected static int num_studenti = 6;
    protected static int num_compiti = 4;
    protected static int[][] matrice = new int[num_studenti][num_compiti];

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        //Inizializzazione matrice leggendo valori input
        for(int i=0; i<matrice.length; i++){
            for(int j=0; j<matrice[i].length; j++){
                System.out.println("Studente " + i + " - Compito " + j + " : ");
                matrice[i][j] = input.nextInt();
            }
        }

        for(int i=0; i<matrice.length; i++){
            StudenteThread thread = new StudenteThread(i);
            thread.start();
        }

    }
}

/*

🔵 ESERCIZIO 1 — Thread con parametri (simile a ES1)
🧮 Calcolo media per studente (matrice + thread)

I voti di 6 studenti nei primi 4 compiti sono organizzati in una matrice.

La riga rappresenta lo studente
La colonna rappresenta il compito
Caricare la matrice da tastiera

📌 Il programma deve:

Ricevere in input l’identificativo dello studente
Creare un thread
Il thread deve calcolare:
la media dei voti
stampare il risultato

🔹 Extra (per livello alto):
Se la media è maggiore di 7, stampare “Promosso”, altrimenti “Rimandato”.

* */