package application;

/**
 * classe monstre, les ennemis du jeu
 * @author meyer
 */
public class Monstre extends Entites {
	
	/**
	 * constructeur des objets monstres
	 * @param x
	 * @param y
	 */
	public Monstre(int x, int y) {
		super(x, y);
		this.setVie(3);
	}

	/**
	 * methode qui permet de deplacer les monstres
	 * @param Labyrinthe, permet de savoir dans quel niveau on se trouve
	 * @param String, direction
	 */
	public void seDeplacer(Labyrinthe l, String s) {
		s = s.toLowerCase();
        boolean res = l.verifierCollisionsMurs(s, this) && l.verifierCollisionsEntites(s, this);
        if(res == true) {
            switch(s) {
            case Labyrinthe.g:
                this.gauche();
                break;
            case Labyrinthe.d:
                this.droite();
                break;
            case Labyrinthe.b:
                this.bas();
                break;
            case Labyrinthe.h:
                this.haut();
                break;
            }
        }
	}
	
	/**
	 * permet de deplacer le monstre dans la direction de l'aventurier afin qu'il se rapproche de lui
	 * a vol d'oiseau
	 * @param l labyrinthe dans lequel il se deplace
	 */
	public void seDeplacerSmart(Labyrinthe l) {
		int x = l.getAventurier().getX();
		int y = l.getAventurier().getY();
		if (Math.abs(x - this.getX()) >= Math.abs(y - this.getY())) {
			if (y > this.getY()) {
				this.seDeplacer(l, Labyrinthe.b);
			} else if (y < this.getY()) {
				this.seDeplacer(l, Labyrinthe.h);
			} else {
				if (x >= this.getX()) {
					this.seDeplacer(l, Labyrinthe.d);
				} else {
					this.seDeplacer(l, Labyrinthe.g);
				}
			}
		} else if (Math.abs(x - this.getX()) <= Math.abs(y - this.getY())) {
			if (x > this.getX()) {
				this.seDeplacer(l, Labyrinthe.d);
			} else if (x < this.getX()) {
				this.seDeplacer(l, Labyrinthe.g);
			} else {
				if (y > this.getY()) {
					this.seDeplacer(l, Labyrinthe.b);
				} else if (y < this.getY()) {
					this.seDeplacer(l, Labyrinthe.h);
				}
			}
		}
	}

	/**
	 * methode qui permet aux monstres d'attaquer le hero
	 * @param int d, nombre de degats des monstres
	 * @param Labyrinthe lab, permet de savoir dans quel niveau on se trouve
	 */
	public void attaquer(int d,Labyrinthe lab) {
		int x = lab.getAventurier().getX();
		int y = lab.getAventurier().getY();
		int pvHeroRef = lab.getAventurier().getVie();
		if(x == this.getX() && (y == this.getY()+1 || y == this.getY()-1)) {
			lab.getAventurier().setVie(pvHeroRef-d);
		} else if(y == this.getY() && (x == this.getX()+1 || x == this.getX()-1)) {
			lab.getAventurier().setVie(pvHeroRef-d);
		} else {
			this.seDeplacerSmart(lab);
		}
	}
	
}
