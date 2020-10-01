package application;
/**
 *Cette classe implemente @see Case
 *represente un mur qui empeche le joueur de passer
 */
public class Mur implements Case {

	/**
	 * permet de savoir si on est sur une case vide ou pleine
	 * objet mur donc case pleine donc false
	 * @return boolean, false
	 */
	public boolean estVide() {
		return false;
	}

}
  