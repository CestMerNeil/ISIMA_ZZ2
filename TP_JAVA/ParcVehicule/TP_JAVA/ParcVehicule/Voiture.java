package ParcVehicule;

import java.lang.String;

public class Voiture {

    private String immat;
    private int couleur;
    private int place;
    
    public Voiture(String immat, int couleur, int place)
    {
        this.immat = immat;
        this.couleur = couleur;
        this.place = place;
    }

    public void afficher()
    {
        StringBuffer sbf = new StringBuffer();
        sbf.append("Je suis une voiture d'immat");
        sbf.append(immat);
        sbf.append(couleur);
        sbf.append(place);

        System.out.println(sbf.toString());
        //System.out.println("je suis une voiture en " + couleur + ", et je suis dans la place " + place + "ma immatriculation est " + immat);
    }

    public void avancer()
    {
        System.out.println("Voiture voiture ~");
    }  
}
