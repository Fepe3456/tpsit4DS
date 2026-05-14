package es2;

import java.util.Random;

public class RunnerThread extends Thread {

    private String nome;
    private int energia;
    private int velocità;
    private int metri_percorsi;

    public RunnerThread(String nome, int energia, int velocità) {
        this.nome = nome;
        this.energia = energia;
        this.velocità = velocità;
        this.metri_percorsi = 0;
    }

    @Override
    public void run() {
        Random random = new Random();
        try {
            while(energia>0 && metri_percorsi<Main.traguardo ) {
                Thread.sleep(1000);
                metri_percorsi += velocità;
                energia -= 5;
                System.out.println("Il runner " + nome + " ha percorso " + metri_percorsi + " metri e ha " + energia + " energia");
                if (energia <= 50) {
                    energia -= random.nextInt(4) + 1; //Da 1 a 3
                }
            }
            if(energia<=0){
                System.out.println("Il runner " + nome + " si ferma!");
            }
            if( metri_percorsi>=Main.traguardo ){
                Main.semaphore.acquire();
                System.out.println("Il runner " + nome + " è arrivato " + Main.podio + "!");
                Main.podio++;
                Main.semaphore.release();
            }
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
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