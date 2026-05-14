package es2;

import java.util.Scanner;
import java.util.concurrent.Semaphore;

public class Main {

    protected static int num_corridori = 4;
    protected static int traguardo = 300;
    protected static int podio = 1;
    static Semaphore semaphore = new Semaphore(1);

    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);

        for(int i=0; i<num_corridori; i++){
            RunnerThread runner = new RunnerThread(("Corr"+i), 70-(i*10), 30-(i*2));
            runner.start();
        }

    }
}

/*

🟢 ESERCIZIO 2 — Gara con thread (simile a ES2)
🏃 Gara tra 4 runner

Ogni corridore è un thread.

Ogni runner ha:

nome
velocità iniziale (5–15 metri al secondo)
energia (100)

Ogni secondo:

percorre metri pari alla sua velocità
perde 5 punti energia
stampa:
metri totali
energia rimasta

📌 Regole speciali:

Quando l’energia scende sotto 50:
la velocità viene ridotta di un numero casuale tra 1 e 3
Se l’energia arriva a 0:
il runner si ferma

🏁 Vince chi raggiunge per primo i 300 metri.

Alla fine:

Stampare il podio
Stampare il vincitore

* */