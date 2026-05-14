package es3;

import java.util.Random;

public class ClienteThread extends Thread {

    private String nome;

    public ClienteThread(String nome) {
        this.nome = nome;
    }

    @Override
    public void run() {
        try {
            int i = 0;
            while (i<5) {
                Main.semaphore.acquire();
                if (Main.denaro >= 50) {
                    Main.denaro -= 50;
                    System.out.println("Il cliente " + nome + " ha prelevato 50 euro! Denaro rimasto: " + Main.denaro);
                }
                else{
                    System.out.println("Denaro insufficiente, il cliente "+ nome + " non ha prelevato!");
                }
                Main.semaphore.release();
                Thread.sleep(5000);
                i++;
            }
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}
