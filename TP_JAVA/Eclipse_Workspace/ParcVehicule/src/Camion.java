
public class Camion extends Vehicule{
	private double capacite;

	
	public Camion(String immat, double capacite) {
		super(immat);
		this.capacite = capacite;
	}
	
	public void afficher() {
		StringBuffer sbf = new StringBuffer();
		sbf.append("Je suis une vehicule d'immat ")
        .append(super.getImmat())
        .append(" ")
		.append(capacite);
		
		System.out.println(sbf.toString());
	}
	public double getCapacite() {
		return capacite;
	}
	public int getType() {
		return 1;
	}

}
