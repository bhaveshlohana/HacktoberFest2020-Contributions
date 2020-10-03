package application;

import java.util.ArrayList;

/**
 * Cette classe represente le labyrinthe du jeu
 */
public class Labyrinthe {
	
	/**
	 * direction prenable pour les entitees : gauche
	 */
	public static final String g = "gauche";
	
	/**
	 * direction prenable pour les entitees : droite
	 */
	public static final String d = "droite";
	
	/**
	 * direction prenable pour les entitees : haut
	 */
	public static final String h = "haut";
	
	/**
	 * direction prenable pour les entitees : bas
	 */
	public static final String b = "bas";

	/**
	 * position x de la sortie du niveau
	 */
	private int xSortie;
	
	/**
	 * position y de la sortie du niveau
	 */
	private int ySortie;
	
	private int xEntree, yEntree;
	
	/**
	 * tableau a double dimensions de type Case
	 */
	private Case[][] labyrinthe;

	/**
	 * tableau de monstres
	 */
	private ArrayList<Monstre> monstres;
	
	/**
	 * liste d'objets sur la carte
	 */
	private ArrayList<Objet> objets;
	
	/**
	 * attribut representant l'aventurier joue par le jouer
	 */
	private Aventurier hero;
	
	/**
	 * String pour l'etat de la partie
	 */
	private String etatPartie = "en cours";
	
	/**
	 * Contructeur vide du labyrinthe. Cree un labyrinthe de 10*10 et place un
	 * aventurier aux coordonnees (1,1)
	 */
	public Labyrinthe() {
		int tailleLaby = 10;
		int tabLaby[][] = {	{1,1,1,1,1,1,1,1,1,1}, 
							{1,0,0,1,0,1,1,0,0,1},
							{1,1,0,0,0,1,0,0,0,1},
							{1,0,0,1,0,0,0,0,1,1},
							{1,0,1,1,1,0,1,0,0,1}, 
							{1,0,0,0,0,0,0,0,1,1},
							{1,1,0,1,1,0,1,0,0,1},
							{1,0,0,0,1,1,1,0,1,1},
							{1,1,1,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1},		
		};
		int nbMonstres = 6;
		//creation et remplissage du labyrinthe
		this.labyrinthe = new Case[tailleLaby][tailleLaby];
		for(int i = 0; i < tailleLaby; i++) {
			for(int j = 0; j < tailleLaby; j++) {
				if(tabLaby[j][i] == 0) {
					this.labyrinthe[i][j] = new CaseVide();
				} else {
					this.labyrinthe[i][j] = new Mur();
				}				
			}
		}
		this.hero = new Aventurier(1,1);
		this.monstres = new ArrayList<Monstre>();
		ArrayList<Entites> entites = new ArrayList<Entites>();
		entites.add(this.hero);
		//creation des monstres
		for(int i = 0; i < nbMonstres; i++) {
			Monstre m = new Monstre((int)(Math.random()*this.labyrinthe.length), (int)(Math.random()*this.labyrinthe.length));
			for(int j = 0; j < entites.size(); j++) {
				while((m.getX() == entites.get(j).getX() && m.getY() == entites.get(j).getY()) || (!labyrinthe[m.getX()][m.getY()].estVide())) {
					m = new Monstre((int)(Math.random()*this.labyrinthe.length), (int)(Math.random()*this.labyrinthe.length));
					j = 0;
				}
			}
			this.monstres.add(m);	
			entites.add(m);
		}
		//positionnement de l'amulette
		objets = new ArrayList<Objet>();
		Amulette a = new Amulette((int)(Math.random()*this.labyrinthe.length), (int)(Math.random()*this.labyrinthe.length));
		for(int i = 0; i < entites.size(); i++) {
			while(a.getX() == entites.get(i).getX() && a.getY() == entites.get(i).getY() || (!labyrinthe[a.getX()][a.getY()].estVide())) {
				a = new Amulette((int)(Math.random()*this.labyrinthe.length), (int)(Math.random()*this.labyrinthe.length));
				i = 0;
			}
		}
		objets.add(a);
	}
	

	public Labyrinthe(int cote) {
		int c ;
		if(cote%2==0) {
			c=cote-1;
		}else {
			c=cote;
		}

	/**
	 * constrcteur du labyrinthe
	 * @param c, taille du labyrinthe
	 */
			this.labyrinthe = new Case[c][c];
		for(int i=0;i<c;i++) {
			for(int j=0;j<c;j++) {
				if(i%2==0) {
					labyrinthe[i][j]=new Mur();
				}
				if(j%2==0) {
					labyrinthe[i][j]=new Mur();
				}
				if(labyrinthe[i][j]==null) {
					labyrinthe[i][j]= new CaseVide();
				}
			}
		}
		int xEnt=0,xSort=c-1;
		int yEnt=(int) (Math.random()*c-2)+2;
		int ySort=(int) (Math.random()*(c-2)+2);
		if(yEnt%2==0) {
			yEnt=yEnt-1;
		}
		if(ySort%2==0) {
			ySort=ySort-1;
		}
		//positionnement de l'entree et la sortie du labyritnhe
		//entree
		labyrinthe[xEnt][yEnt]=new CaseVide();
		labyrinthe[xSort][ySort]=new CaseVide();
		this.xSortie=xSort;
		this.ySortie=ySort;
		this.xEntree=xEnt;
		this.yEntree=yEnt;
		//sortie
		labyrinthe[xEnt+1][yEnt]=new CaseVide();
		labyrinthe[xSort-1][ySort]=new CaseVide();
		//etat du labyrinthe
		boolean isfinished = false;
		//on joue tant qu'on a pas fini la partie
		while(!isfinished) {
			  int x = (int) (Math.random() * (c-2))+1;
			  int y = (int) (Math.random() * (c-2))+1;
			  //verification
			  if(labyrinthe[x][y]instanceof Mur && (!((labyrinthe[x-1][y]instanceof Mur)&&(labyrinthe[x+1][y]instanceof Mur)&&(labyrinthe[x][y-1]instanceof Mur)&&(labyrinthe[x][y+1]instanceof Mur)))) {
				  if((labyrinthe[x-1][y]instanceof CaseVide)&&(labyrinthe[x+1][y]instanceof CaseVide)) {
					 CaseVide c1 = new CaseVide((CaseVide) labyrinthe[x-1][y]);
					 CaseVide c2 = new CaseVide((CaseVide) labyrinthe[x+1][y]);
					 //verifications
					 if(c1.getId()!=c2.getId()) {
						 labyrinthe[x][y]=new CaseVide(c1);
						 for(int a=0;a<c;a++) {
							 for(int b=0;b<c;b++) {
								 if(labyrinthe[a][b] instanceof CaseVide) {
									 if(((CaseVide) labyrinthe[a][b]).getId()==c2.getId()) {
										 labyrinthe[a][b]=new CaseVide(c1);
									 }
								 }
							 }
						 }
					 }
				 //sinon on fait
				 }else if((labyrinthe[x][y-1]instanceof CaseVide)&&(labyrinthe[x][y+1]instanceof CaseVide)) {
					 CaseVide c1 = new CaseVide((CaseVide) labyrinthe[x][y-1]);
					 CaseVide c2 = new CaseVide((CaseVide) labyrinthe[x][y+1]);
					 //conditionnelle
					 if(c1.getId()!=c2.getId()) {
						 labyrinthe[x][y]=new CaseVide(c1);
						 for(int a=0;a<c;a++) {
							 for(int b=0;b<c;b++) {
								 if(labyrinthe[a][b] instanceof CaseVide) {
									 if(((CaseVide) labyrinthe[a][b]).getId()==c2.getId()) {
										 labyrinthe[a][b]=new CaseVide(c1);
									 }
								 }
							 }
						 }
					 }
				  }
				  //
				  ArrayList<Integer> identifiants= new ArrayList<Integer>();
				  //
				  for(int r=0;r<c;r++) {
					  for(int s=0;s<c;s++) {
						 if(labyrinthe[r][s]instanceof CaseVide) {
							if(!identifiants.contains(((CaseVide) labyrinthe[r][s]).getId())) {
								identifiants.add(((CaseVide) labyrinthe[r][s]).getId());
							}
						 }
					  }
				  }
				  //System.out.println(identifiants.size());
				  if(identifiants.size()==3) {
					  isfinished=true;
				  }
			  }
		}	
		//position du heros
		this.hero= new Aventurier(xEnt,yEnt);
		this.monstres=new ArrayList<Monstre>();
		int nbMonstres = 6;
		ArrayList<Entites> entites = new ArrayList<Entites>();
		entites.add(this.hero);
		//
		for(int i = 0; i < nbMonstres; i++) {
			Monstre m = new Monstre((int)(Math.random()*this.labyrinthe.length), (int)(Math.random()*this.labyrinthe.length));
			for(int j = 0; j < entites.size(); j++) {
				while((m.getX() == entites.get(j).getX() && m.getY() == entites.get(j).getY()) || (!labyrinthe[m.getX()][m.getY()].estVide())) {
					m = new Monstre((int)(Math.random()*this.labyrinthe.length), (int)(Math.random()*this.labyrinthe.length));
					j = 0;
				}
			}
			this.monstres.add(m);	
			entites.add(m);
		}
		//
		objets = new ArrayList<Objet>();
		Amulette a = new Amulette((int)(Math.random()*this.labyrinthe.length), (int)(Math.random()*this.labyrinthe.length));
		for(int i = 0; i < entites.size(); i++) {
			while(a.getX() == entites.get(i).getX() && a.getY() == entites.get(i).getY() || (!labyrinthe[a.getX()][a.getY()].estVide())) {
				a = new Amulette((int)(Math.random()*this.labyrinthe.length), (int)(Math.random()*this.labyrinthe.length));
				i = 0;
			}
		}
		objets.add(a);
	}

	/**
	 * renvoie la liste de monstre
	 * @return ArrayList<Monstre>
	 */
	public ArrayList<Monstre> getMonstres() {
		return monstres;
	}
 
	/**
	 * Constructeur du labyrinthe (taille donn�e)
	 * @param longueur , longueur du labyrinthe
	 * @param largeur  , largeur du labyrinthe place un joueur au centre
	 */
	public Labyrinthe(int longueur, int largeur) {
		this.labyrinthe = new Case[longueur][largeur];
		for(int i = 0; i < longueur; i++) {
			for(int j = 0; j < largeur; j++) {
				this.labyrinthe[i][j] = new CaseVide();
			}
		}
		this.hero = new Aventurier((int) (Math.floor(((longueur - 1) / 2))), (int) (Math.floor(((largeur - 1) / 2))));
		this.monstres = new ArrayList<Monstre>();
		this.objets = new ArrayList<Objet>();
	}

	/**
	 * permet de verifier la collision dans une certaine direction donnee
	 * @param direction String qui indique la direction dans laquelle on teste la collision
	 */
	public boolean verifierCollisionsMurs(String direction, Entites e) {
		boolean res = false;
		switch(direction) {
		case "gauche":
			e.setFacing(Labyrinthe.g);
			if(e.getX() > 0) { //test si l'entite sort du labyrinthe
				if(this.labyrinthe[e.getX() - 1][e.getY()].estVide()) {
					res = true;
				}
			}
			break;
		case "droite":
			e.setFacing(Labyrinthe.d);
			if(e.getX() < this.labyrinthe.length - 1) { //test si l'entite sort du labyrinthe
				if(this.labyrinthe[e.getX() + 1][e.getY()].estVide()) {
					res = true;
				}
			}
			break;
		case "haut":
			e.setFacing(Labyrinthe.h);
			if(e.getY() > 0) { //test si l'entite sort du labyrinthe
				if(this.labyrinthe[e.getX()][e.getY() - 1].estVide()) {
					res = true;
				}
			}
			break;
		case "bas":
			e.setFacing(Labyrinthe.b);
			if(e.getY() < this.labyrinthe[0].length-1) { //test si l'entite sort du labyrinthe
				if(this.labyrinthe[e.getX()][e.getY() + 1].estVide()) {
					res = true;
				}
			}
			break;		
		}
		return res;
	}
	
	/**
	 * permet de verifier la collision dans une certaine direction donnee avec une entite
	 * @param direction String qui indique la direction dans laquelle on teste la collision
	 */
	public boolean verifierCollisionsEntites(String direction, Entites s) {
		boolean res = true;
		ArrayList<Entites> entites = new ArrayList<Entites>();
		entites.add(this.hero);
		entites.addAll(this.monstres);
		switch(direction) {
		case "gauche":
			for(int i = 0; i < entites.size(); i++) {
				if( entites.get(i).getX() == s.getX()-1 && entites.get(i).getY() == s.getY() ) {
					s.setFacing(Labyrinthe.g);
					res = false;
				}
			}
			break;
		case "droite":
			for(int i = 0; i < entites.size(); i++) {
				if( entites.get(i).getX() == s.getX()+1 && entites.get(i).getY() == s.getY() ) {
					s.setFacing(Labyrinthe.d);
					res = false;
				}
			}
			break;
		case "haut":
			for(int i = 0; i < entites.size(); i++) {
				if( entites.get(i).getX() == s.getX() && entites.get(i).getY() == s.getY()-1 ) {
					s.setFacing(Labyrinthe.h);
					res = false;
				}
			}
			break;
		case "bas":
			for(int i = 0; i < entites.size(); i++) {
				if( entites.get(i).getX() == s.getX() && entites.get(i).getY() == s.getY()+1 ) {
					s.setFacing(Labyrinthe.b);
					res = false;
				}
			}
			break;		
		}
		return res;
	}

	/**
	 * Permet de recuperer l'aventurier
	 * @return Aventurier , le heros joue par le joueur
	 */
	public Aventurier getAventurier() {
		return this.hero;
	}
	
	/**
	 * Permet de recuperer le tableau de cases du labyrinthe
	 * @return Case[][] tableau a deux dimensions de Case
	 */
	public Case[][] getCases() {
		return this.labyrinthe;
	}
	
	/**
	 * Permet de placer un mur dans le labyrinthe a l'endroit ou on veut 
	 * @return void
	 */
	public void setCasesMur(int px, int py) {
		this.labyrinthe[px][py] = new Mur(); 
	}
	
	/**
	 * Permet de placer une case vide dans le labyrinthe a l'endroit ou on veut 
	 * @return void
	 */
	public void setCasesVide(int px, int py) {
		this.labyrinthe[px][py] = new CaseVide(); 
	}
	
	/**
	 * Permet de placer un monstre dans le labyrinthe a l'endroit ou on veut 
	 * @return void
	 */
	public void setMonstre(int px, int py) {
		this.monstres.add(new Monstre(px, py)); 
	}
	
	/**
<<<<<<< HEAD
	 * Permet de recuperer un monstre en fonction de ses coordonnees sur le labyrinthe
	 * @param x coordonnees en abcisse du monstre
	 * @param y coordonnees en ordonnee du monstre
=======
	 * Permet de recuperer un monstre en fonction de ses coordonnees sur le labyrinthe
	 * @param x coordonnees en abcisse du monstre
	 * @param y coordonnees en ordonnee du monstre
>>>>>>> labRand
	 * @return Monstre
	 */
	public Entites getMonstreCoord(int x,int y) {
		Monstre ans=null;
		int i=0;
		boolean found=false;
		//
		while(!found && i<monstres.size()) {
			Monstre m = monstres.get(i);
			if(m.getX()==x&&m.getY()==y) {
				ans=m;
				found=true;
			}
			i++;
		}
		//resultat
		return ans;
	}
	
	/**
<<<<<<< HEAD
	 * Permet de supprimer une Entite du labyrinthe passee en parametre
	 * @param e entite a supprimer
=======
	 * Permet de supprimer une Entite du labyrinthe passee en parametre
	 * @param e entite a supprimer
>>>>>>> labRand
	 */
	public void rmMonstre(Entites e) {
		if(e!=null) {
			if(e instanceof Aventurier) {
				this.hero=null;
			}else if(e instanceof Monstre) {
				monstres.remove(e);
			}
		}
	}
	
	/**
	 * renvoit la liste d'objets
	 * @return liste d'objets
	 */
	public ArrayList<Objet> getObjets(){
		return this.objets;
	}
	
	/**
	 * permet de recuperer l'etat de la partie 
	 * @return String etat de la partie
	 */
	public String getEtatPartie() {
		return this.etatPartie;
	}
	
	/**
	 * permet de modifier l'etat de la partie
	 */
	public void setEtatPartie(String e) {
		this.etatPartie = e;
	}
	
	/**
	 * getter pour la position du sortie
	 * @return
	 */
	public int getXSortie() {
		return this.xSortie;
	}
	
	/**
	 * getter pour la position du sortie
	 * @return
	 */
	public int getYSortie() {
		return this.ySortie;
	}
	
	public int getXEntree() {
		return this.xEntree;
	}
	
	public int getYEntree() {
		return this.yEntree;
	}

}
