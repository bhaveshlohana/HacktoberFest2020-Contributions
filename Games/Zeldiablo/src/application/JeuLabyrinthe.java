package application;
 
import moteurJeu.Commande;
import moteurJeu.Jeu;

/**
 * Cette classe represente le jeu
 */
public class JeuLabyrinthe implements Jeu {
	
	/**
	 * Labyrinthe du jeu;
	 */
	private Labyrinthe lab;
	 
	/**
	 * representation du temps en milliseconde
	 */
	private int millisTime = 0;
	
	/**
	 * Constructeur vide du Jeu
	 */
	public JeuLabyrinthe(){
		this.lab= new Labyrinthe(11);
	}
	
	/**
	 * Constructeur avec pour seul parametre le Labyrinthe
	 * @param l Labyrinthe avec le quel on initialise le jeu;
	 */
	public JeuLabyrinthe(Labyrinthe l){
		this.lab = l;
	}
	
	/**
     * methode qui permet de deplacer si possible l'aventurier du labyrinthe dans une 
     * direction indiquee
     * @param direction String qui indique la direction souhaitee
     */
    public void deplacerAventurier(String direction) {
        lab.getAventurier().seDeplacer(this.lab, direction);
    }

    /**
     * methode qui fait evoluer la partie en cours
     * @param Commande, voir moteur du jeu
     */
    public void evoluer(Commande commandeUser) {
    	//gestion du mouvement du hero
		if (commandeUser.bas) {
			this.lab.getAventurier().seDeplacer(this.lab, Labyrinthe.b);
		} else if (commandeUser.haut) {
			this.lab.getAventurier().seDeplacer(this.lab, Labyrinthe.h);
		} else if (commandeUser.droite) {
			this.lab.getAventurier().seDeplacer(this.lab, Labyrinthe.d);
		} else if (commandeUser.gauche) {
			this.lab.getAventurier().seDeplacer(this.lab, Labyrinthe.g);
		} else if (commandeUser.espace) {
			this.lab.getAventurier().attaquer(1, this.lab);
		}
    	//gestion du mouvement des monstres
      	this.millisTime += 100;
      	//Mouvement aleatore du monstre toutes les deux secondes
      	//String moves[] = {"gauche", "droite", "bas", "haut"};
      	if(millisTime % 2000 == 0) {
      		for(int i = 0; i < this.getLabyrinthe().getMonstres().size(); i++) {
      			//int choixMove = (int)(Math.random()*4);
      			//this.getLabyrinthe().getMonstres().get(i).seDeplacer(this.getLabyrinthe(), moves[choixMove]);
      			this.getLabyrinthe().getMonstres().get(i).attaquer(1, this.getLabyrinthe());
      			//this.getLabyrinthe().getMonstres().get(i).seDeplacerSmart(this.getLabyrinthe());
      		}
      	}
    }

	/**
	 * methode qui permet de savoir quand stopper le jeu en cours
	 * @return boolean, etat de l'etat de la partie
	 */
	public boolean etreFini() {
		boolean end = false;
		//si le heros meurt alors defaite
		if(this.getLabyrinthe().getAventurier().getVie() <= 0) {
			this.getLabyrinthe().setEtatPartie("Defaite");
			end = true;
			System.out.println("La partie est terminee, le heros est mort !");
		}
		//si le heros gagne
		if(this.getLabyrinthe().getAventurier().getHasAmulette() && this.getLabyrinthe().getAventurier().getX() == this.lab.getXSortie() && this.getLabyrinthe().getAventurier().getY() == this.lab.getYSortie()) {
			this.getLabyrinthe().setEtatPartie("Victoire");
			end = true;
			System.out.println("La partie est terminee, le heros a gagne");
		}
		//renvoie du resultat
		return end;
	}
	
	/**
	 * getter pour le labyrinthe actuel
	 * @return
	 */
	public Labyrinthe getLabyrinthe() {
		return this.lab;
	}

}
