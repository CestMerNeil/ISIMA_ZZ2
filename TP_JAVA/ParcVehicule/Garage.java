package ParcVehicule;

public class Garage {
    private int nbVoiture = 0;
    private int nbCamion = 0;
    private int capaciteVoiture = 200;
    private int capaciteCamion = 50;
    private int placeVoiture[];
    private int placeCamion[];


    public void setCapaciteCamion(int Capacite)
    {
        capaciteCamion = Capacite;
    }

    public void setCapaciteVoiture(int Capacite)
    {
        capaciteVoiture = Capacite;
    }


    /* ---------------------------------------------------------------------------------------------------*/
    /* C'est pour la voiture*/
    public void voitureIn(int place)
    {
        if(capaciteVoiture < nbVoiture && placeVoiture[place] == 0){
            nbVoiture++;
            placeVoiture[place] = 1;
        }
        else{
            System.out.println("Error, you don't have this place for this car");
        }
    }

    public void voitureOut(int place){
        nbVoiture--;
        placeVoiture[place] = 0;
    }


    /* ---------------------------------------------------------------------------------------------------*/
    /* C'est pour le camion*/
    public void camionIn(int place){
        if(capaciteCamion < nbCamion && placeCamion[place] == 0){
            nbCamion++;
            placeCamion[place] = 1;
        }
        else{
        nbCamion--;
        placeCamion[place] = 0;
        }
    }
}

