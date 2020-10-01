package application;

/**
 * classe abstraite representant les objets
 * @author Purple
 */
public abstract class Objet {
	
	/**
	 * represente l'abscisse de l'objet dans le labyrinthe
	 */
	private int x;
	
	/**
	 * represente l'ordonnee de l'objet dans le labyrinthe
	 */
	private int y;
	
	/*
	 * permet d'instancier un objet a partir de coordonnees
	 * @param dx abscisse de l'objet
	 * @param dy ordonnee de l'objet
	 */
	public Objet(int dx, int dy) {
		this.x = dx;
		this.y = dy;
	}

	/**
	 * renvoit l'abscisse de l'objet
	 * @return x
	 */
	public int getX() {
		return x;
	}

	/**
	 * renvoit l'ordonnee de l'objet
	 * @return y
	 */
	public int getY() {
		return y;
	}

}
