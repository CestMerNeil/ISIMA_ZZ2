
public class Garage {
	private int nbVoiture = 0;
    private int nbCamion = 0;
    private int capaciteVoiture = 200;
    private int capaciteCamion = 50;
    
    private int CamionList[] = {0};
    private int VoitureList[] = {0};
    
    public void vehiculeIn(Vehicule v) {
    	/* Au cas ou c'est un camion */
    	if(v.getType() == 1) {
    		if(nbCamion < capaciteCamion) {
    			CamionList[nbCamion] = 1;
    			nbCamion++;
    			System.out.println("Succes camion!");
    		}
    		else {
    			System.out.println("Y'a plus de place pour ce camion!");
    		}
    	}
    	/* Au cas ou c'est une voiture */
    	if(v.getType() == 2) {
    		if(nbVoiture < capaciteVoiture) {
    			VoitureList[nbVoiture] = 1;
    			nbVoiture++;
    			System.out.println("Succes voiture!");
    		}
    		else {
    			System.out.println("Y'a plus de place pour cette voiture!");
    		}
    	}
    }
    
    public void vehiculeOut(Vehicule v) {
    	/* Au cas ou c'est un camion */
    	if(v.getType() == 1) {
    		//CamionList[nbCamion] = 0;
    		//nbCamion--;
			System.out.println("Succes OUT camion!");
    	}
    	/* Au cas ou c'est une voiture */
    	if(v.getType() == 2) {
    		//VoitureList[nbVoiture] = 0;
    		//nbVoiture--;
    		System.out.println("Succes OUT voiture!");
    	}
    }
}
