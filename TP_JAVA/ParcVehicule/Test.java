package ParcVehicule;


public class Test {
    public void Main(String[] args){
        Garage g = new Garage();
        Voiture v = new Voiture();
        Camion c = new Camion("AA-125-XX", 9, 2, 13.5);

        v.setPlace(6);
        g.voitureIn(5);

        v.afficher();
        c.afficher();

    }
}
