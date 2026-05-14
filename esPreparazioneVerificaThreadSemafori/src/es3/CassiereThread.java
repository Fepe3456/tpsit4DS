package es3;

public class CassiereThread extends Thread {

    private boolean attivo = true;

    public CassiereThread() {

    }

    public void setAttivo(boolean attivo) {
        this.attivo = attivo;
    }

    @Override
    public void run() {
        try {
            while(attivo){
                Thread.sleep(4000);
                Main.semaphore.acquire();
                if(Main.denaro<100){
                    Main.denaro = 200;
                    System.out.println("Il cassiere ha ripristinato a 200 il denaro allo sportello!");
                }
                Main.semaphore.release();
            }
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}
