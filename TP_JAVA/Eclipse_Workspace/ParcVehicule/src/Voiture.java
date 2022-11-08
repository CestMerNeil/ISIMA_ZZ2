
public class Voiture extends Vehicule{
	private int couleur;
	private int place;
	
	public Voiture(String immat, int couleur, int place) {
		super(immat);
		this.couleur = couleur;
		this.place = place;

	}
	
	public void afficher() {
		StringBuffer sbf = new StringBuffer();
		sbf.append("Je suis une vehicule d'immat ")
        .append(super.getImmat())
        .append(" ")
        .append(couleur)
        .append(" ")
        .append(place);
		
		System.out.println(sbf.toString());
	}
	public int getType() {
		return 2;
	}
}
