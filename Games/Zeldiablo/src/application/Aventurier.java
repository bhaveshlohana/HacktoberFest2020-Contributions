package application;

import java.util.ArrayList;

/**
 * Cette classe represente l'aventurier
 */
public class Aventurier extends Entites{

	/**
	 * possession de l'amulette
	 */
	private boolean hasAmulette;
	
	//nombre detage parcouru
	private int etageParcouru;
	
	/**
	 * Instancie l'aventurier en fonction de coordonnees
	 * @param a abscisse de l'aventurier
	 * @param o ordonnee de l'aventurier
	 */
	public Aventurier(int a, int o) {
		super(a, o);
		this.setFacing("idle");
		this.setVie(5);
		this.etageParcouru = 0;
	}
	
	/**
     * permet de deplacer l'aventurier dans une direction donnee
     * @direction String qui indique la direction souhait�e
     * @lab labyrinthe dans lequel se deplace l'aventurier
     */
    public void seDeplacer(Labyrinthe lab, String direction) {
        direction = direction.toLowerCase();
        boolean res = lab.verifierCollisionsMurs(direction, this) && lab.verifierCollisionsEntites(direction, this);
        //differents chois suivant le deplacement a effectuer
        if(res == true) {
            switch(direction) {
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
        this.recupererAmulette(lab);
    }
    
    /**
     * permet de recuperer l'amulette
     * @param lab labyrinthe dans lequel se trouve l'amulette 
     * @return vrai si l'amulette a ete recuperee
     */
    public void recupererAmulette(Labyrinthe lab) {
    	ArrayList<Objet> obj = lab.getObjets();
    	int i = 0;
    	int xA = -1;
    	int yA = -1;
    	while(!obj.isEmpty() && !(obj.get(i) instanceof Amulette)) {
    		i ++;
    	}
    	if(!obj.isEmpty()) {
    		xA = obj.get(i).getX();
    		yA = obj.get(i).getY();
    	}
    	if(this.getX() == xA && this.getY() == yA) {
    		lab.getObjets().remove(i);
    		this.hasAmulette = true;
    	}
    }

	/**
	 * permet de lancer une attaque contre un monstre
	 * @param d, le nombre de degats que l'on va infliger au monstre
	 * @param lab, labyrinthe dans lequel se trouve l'aventurier et le monstre
	 */
	public void attaquer(int d,Labyrinthe lab) {
		int xe=0,ye=0;
		//permet de gerer la feature : attaque directionnelle
		switch(this.getFacing()) {
		case Labyrinthe.h:
			ye=-1;
			break;
		case Labyrinthe.b :
			ye=1;
			break;
		case Labyrinthe.d :
			xe=1;
			break;
		case Labyrinthe.g :
			xe = -1;
			break;
		}
		//on recupere le monstre que l'on veut frapper
		Entites e = lab.getMonstreCoord(this.getX()+xe,this.getY()+ye);
		//on enleve des PV au monstre victime des coups
		if(e!=null) {
			int pvMonstre = e.getVie();
			e.setVie(pvMonstre-d);	
			if(e.getVie()==0) {
				lab.rmMonstre(e);				
			}
		}
	}
	
	/**
	 * permet de savoir si l'aventurier possede l'amulette
	 * @return l'attribut hasAmulette
	 */
	public boolean getHasAmulette() {
		return this.hasAmulette;
	}
	
	public int getEtageParcouru() {
		return this.etageParcouru;
	}
	
	public void setEtageParcouru(int p) {
		this.etageParcouru = p;
	}
   
}

