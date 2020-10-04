package application;

/**
 * abstract class permettant de regrouper les methodes relies aux entites
 * cela comprend l'aventurier et les monstres
 * @author meyer
 */
public abstract class Entites {

	/**
	 * represente l'abscisse de l'entite dans le labyrinthe
	 */
	private int x;
	
	/**
	 * represente l'ordonnee du monstre dans le labyrinthe 
	 */
	private int y;
	
	/**
	 * represente les points de vie de l'entite
	 */
	private int vie;
	
	/**
	 * direction dans laquelle le personnage regarde
	 */
	private String facing;
	
	/**
	 * permet d'instancier une entite
	 * @param x
	 * @param y
	 */
	public Entites(int x, int y) {
		this.x = x;
		this.y = y;
		this.vie = 0;
	}
	
	/**
	 * methode qui permet d'attaquer une autre entite
	 * @param d, les degats a infliger
	 * @param lab, le terrain de jeu actuel
	 */
	public abstract void attaquer(int d,Labyrinthe lab);
	
	/**
	 * permet de deplacer une entite
	 * @param l, l'espace de jeu actuel
	 * @param s, la direction du deplacement
	 */
	public abstract void seDeplacer(Labyrinthe l, String s);
	
	/*
	 * Permet de deplacer l'entite vers le haut
	 */
	public void haut() {
		facing=Labyrinthe.h;
		this.setY(this.getY()-1);
	}
	
	/*
	 * Permet de deplacer l'entite vers le bas
	 */
	public void bas() {
		facing=Labyrinthe.b;
		this.setY(this.getY()+1);
	}
	
	/*
	 * Permet de deplacer l'entite vers la gauche
	 */
	public void gauche() {
		facing=Labyrinthe.g;
		this.setX(this.getX()-1);
	}
	
	/*
	 * Permet de deplacer l'entite vers la droite
	 */
	public void droite() {
		facing=Labyrinthe.d;
		this.setX(this.getX()+1);
	}
	
	/**
	 * Permet de recuperer l'orientation de l'entite
	 * @return String : haut, bas, gauche, droite
	 */
	public String getFacing() {
		return this.facing;
	}
	
	/**
	 * Permet de changer le facing du heros
	 * @param f, direction du facing
	 * @return void
	 */
	public void setFacing(String f) {
		this.facing = f;
	}

	/**
	 * renvoit l'abscisse de l'entite
	 * @return int 
	 */
	public int getX() {
		return x;
	}

	/**
	 * renvoit l'ordonnee de l'entite
	 * @return int 
	 */
	public int getY() {
		return y;
	}
	
	/**
	 * renvoit le nombre de point de vie de l'entite
	 * @return int 
	 */
	public int getVie() {
		return vie;
	}
	
	/**
	 * permet de modifier l'abscisse de l'entite
	 */
	public void setX(int newX) {
		this.x = newX;
	}
	
	/**
	 * permet de modifier l'ordonn�e de l'entite 
	 */
	public void setY(int newY) {
		this.y = newY;
	}
	
	/**
	 * permet de modifier les points de vie de l'entite 
	 */
	public void setVie(int newV) {
		this.vie = newV;
	}
 
}
