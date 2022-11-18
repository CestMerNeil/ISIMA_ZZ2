
public class Test {
	
	public static void main(String[] argv) {
		Garage g = new Garage();
		Camion c = new Camion("AA-26-XX", 50);
		Voiture v = new Voiture("BB-56-XX", 152, 4);
		//Vehicule ve = new Vehicule("CC-29-BB");
		
		v.afficher();
		c.afficher();
		v.avancer();
		c.avancer();
		
		g.vehiculeIn(v);
		g.vehiculeIn(c);
		
		
		g.vehiculeOut(v);
		g.vehiculeOut(c);
	}

}
