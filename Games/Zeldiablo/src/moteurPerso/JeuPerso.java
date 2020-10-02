package moteurPerso;

import moteurJeu.Commande;
import moteurJeu.Jeu;

public class JeuPerso implements Jeu {
	
	private int x,y;
	
	public JeuPerso() {
		this.x=10;
		this.y=10;
	}

	@Override
	public void evoluer(Commande commandeUser) {
		
		if(commandeUser.bas) {
			this.y+=1;
		}else if(commandeUser.haut) {
			this.y-=1;
		}else if(commandeUser.droite) {
			this.x+=1;
		}else if(commandeUser.gauche) {
			this.x-=1;
		}

	}

	@Override
	public boolean etreFini() {
		
		return false;
	}
	
	public int getX() {
		return this.x;
	}
	
	public int getY() {
		return this.y;
	}

}
