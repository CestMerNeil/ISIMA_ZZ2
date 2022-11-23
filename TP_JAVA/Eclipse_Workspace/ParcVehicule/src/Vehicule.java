
public abstract class Vehicule {
	
	private String immat;

	public Vehicule(String immat) {
		this.immat = immat;
	}
	
	public void afficher() {
		StringBuffer sbf = new StringBuffer();
		sbf.append("Je suis une vehicule d'immat ")
        .append(immat);
		
		System.out.println(sbf.toString());
	}
	
	public void avancer() {
		System.out.println("DI DI~");
	}
	
	public String getImmat() {
		return immat;
	}
	
	public int getType() {
		return 3;
	}

}
