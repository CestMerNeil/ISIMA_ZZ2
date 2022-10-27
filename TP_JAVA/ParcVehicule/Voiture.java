package ParcVehicule;

import java.lang.String;

public class Voiture {

    private String immat;
    private int couleur;
    private int place;

    public void afficher()
    {
        StringBuffer sbf = new StringBuffer();
        sbf.append("Je suis une voiture d'immat");
        sbf.append(immat);

        System.out.println(sbf.toString());
        //System.out.println("je suis une voiture en " + couleur + ", et je suis dans la place " + place + "ma immatriculation est " + immat);
    }

    public void avancer()
    {
        System.out.println("Voiture voiture ~");
    }  

    public void setImmat(String Immat)
    {
        immat = Immat;
    }

    public final String getImmat()
    {
        return immat;
    }

    public void setCouleur(int Couleur)
    {
        couleur = Couleur;
    }

    public final int getCouleur()
    {
        return couleur;
    }
    
    public void setPlace(int Place)
    {
        place = Place;
    }

    public final int getPlace()
    {
        return place;
    }
}
