package ParcVehicule;


public class Test {
    public static void main(String[] args){
        Voiture v = new Voiture("AA-135-XX", 9, 2);
        Camion c = new Camion("AA-125-XX", 9, 2, 13.5);

        v.afficher();
        c.afficher();

    }
}
