package application;

import java.awt.Color;

/**
 * cette classe implemente @see Case 
 * elle represente une case vide, sur la quelle le joueur peut se deplacer
 */
public class CaseVide implements Case {
	
	/**
	 * compteur interne a la classe
	 */
	public static int ids = 0;
	
	/**
	 * le type de la case / son identifiant
	 */
	private int id;
	
	/**
	 * la couleur de la case
	 */
	private Color c;
	
	/**
	 * permet de savoir si une case est vide ou non (sans hero ni monstre)
	 * methode commune a toutes les Cases
	 * @return boolean
	 */
	public boolean estVide() {
		return true;
	}
	
	/**
	 * constructeur de base sans parametre
	 */
	public CaseVide() {
		id=ids++;
		c= new Color((int)(Math.random()*255),(int)(Math.random()*255),(int)(Math.random()*255));
	}
  
	/**
	 * constructeur avec un parametre CaseVide
	 * @param cv
	 */
	public CaseVide(CaseVide cv) {
		this.c=cv.getC();
		this.id=cv.getId();
	}
  
	/**
	 * getter pour l'attribut ids
	 * @return int, attribut ids
	 */
	public static int getIds() {
		return ids;
	}

	/**
	 * getter pour l'attribut id
	 * @return int, attribut id
	 */
	public int getId() {
		return id;
	}

	/**
	 * getter pour la couleur
	 * @return Color, la couleur de la case
	 */
	public Color getC() {
		return c;
	}
  
}
