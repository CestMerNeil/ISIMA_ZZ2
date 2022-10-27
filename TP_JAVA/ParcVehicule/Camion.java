package ParcVehicule;

import java.lang.String;

public class Camion {

    private String immat;
    private int couleur;
    private int place;
    private double capacite;

    public Camion(String immat, int couleur, int place, double capacite)
    {
        this.immat = immat;
        this.couleur = couleur;
        this.place = place;
        this.capacite = capacite;
    }

    public void afficher()
    {
        StringBuffer sbf = new StringBuffer();
        sbf.append("Je suis une voiture d'immat")
           .append(immat);

        System.out.println(sbf.toString());
        //System.out.println("je suis une voiture en " + couleur + ", et je suis dans la place " + place + "ma immatriculation est " + immat);
    }

    public void avancer()
    {
        System.out.println("Voiture voiture ~");
    }  
}
