package es1;

public class StudenteThread extends Thread {

    private int id;

    public StudenteThread(int id) {
        this.id = id;
    }

    @Override
    public void run() {
        int somma = 0, media;
        for(int i=0; i<Main.matrice[i].length; i++){
            somma += Main.matrice[id][i];
        }
        media = somma / Main.num_compiti;
        System.out.println("Lo studente " + id + " ha una media di " + media);
        if(media >= 7){
            System.out.println("Lo studente " + id + " è promosso!");
        }
        else{
            System.out.println("Lo studente " + id + " è rimandato!");
        }
    }
}
