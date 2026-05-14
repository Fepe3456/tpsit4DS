package es3;

import java.util.concurrent.Semaphore;

public class Main {

    protected static int denaro = 200;
    protected static Semaphore semaphore = new Semaphore(1);

    public static void main(String[] args) {

        ClienteThread cliente1 = new ClienteThread("Cliente1");
        ClienteThread cliente2 = new ClienteThread("Cliente2");
        ClienteThread cliente3 = new ClienteThread("Cliente3");
        CassiereThread cassiere = new CassiereThread();

        cliente1.start();
        cliente2.start();
        cliente3.start();
        cassiere.start();
        try {
            cliente1.join();
            cliente2.join();
            cliente3.join();
            cassiere.setAttivo(false);
            cassiere.join();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

    }
}

/*

🔴 ESERCIZIO 3 — Semafori (tipo ES3 ma con semafori veri)
🏦 Sportello bancario con semaforo

Ci sono:

1 cassiere
3 clienti

Il denaro disponibile allo sportello è inizialmente 200.

Ogni cliente:

può prelevare 50
deve aspettare se non c’è abbastanza denaro

📌 Usare un Semaphore per:

permettere l’accesso di un cliente alla volta
evitare condizioni di race

Il cassiere:

ogni 4 secondi controlla il denaro
se scende sotto 100, lo riporta a 200

Stampare messaggi chiari per:

richiesta di prelievo
accesso allo sportello
ricarica del denaro

* */