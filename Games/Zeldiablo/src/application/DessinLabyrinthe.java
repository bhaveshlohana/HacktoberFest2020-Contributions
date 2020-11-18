package application;

import java.awt.Color;

import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;

import javax.imageio.ImageIO;

import moteurJeu.DessinJeu;

/**
 * classe permettant la representation graphique du labyrinthe
 * @author meyer
 */
public class DessinLabyrinthe implements DessinJeu {
	
	/**
	 * Le jeu que la classe doit dessiner 
	 */
	private JeuLabyrinthe jeu;
	
	/**
	 * la liste de sprites utiles
	 */
	private ArrayList<BufferedImage> sprites;
	
	/**
	 * Taille d'une case de la grille
	 */
	public static final int TAILLE = 40;
	
	/**
	 * Permet de construire un dessin du jeu avec le jeu passe en parametre
	 * @param jeu
	 */  
	public DessinLabyrinthe(JeuLabyrinthe jeu) {
		this.jeu = jeu;
		sprites=new ArrayList<BufferedImage>();
	}

	/**
	 * methode qui dessine a proprement parle les differents objets de la scene
	 * @param BufferedImage, permet de stocker les images a dessiner par la suite
	 * @return void
	 */
	public void dessiner(BufferedImage image) {
		this.chargerSprites();
		Graphics2D g = (Graphics2D) image.getGraphics();
		g.setColor(Color.blue);
		//aventurier
		Case[][] cases = jeu.getLabyrinthe().getCases();
		//dessin des murs
		g.setColor(Color.pink);
		for(int i=0;i<cases.length;i++) {
			for(int j=0;j<cases[i].length;j++) {
				if(cases[i][j]instanceof Mur) {
					g.drawImage(sprites.get(6),i*TAILLE,j*TAILLE,null);				
				}
				if(cases[i][j]instanceof CaseVide)
				{
					//g.setColor(Color.red);
					g.drawImage(sprites.get(5),i*TAILLE,j*TAILLE,null);
					}
				}
		}
		//affichage de l'amulette 
		g.setColor(Color.yellow);
		int k = 0;
		while (!jeu.getLabyrinthe().getObjets().isEmpty() && !(jeu.getLabyrinthe().getObjets().get(k) instanceof Amulette && k < jeu.getLabyrinthe().getObjets().size())) {
			k++;
		}
		if(!jeu.getLabyrinthe().getObjets().isEmpty()) {
			
			g.drawImage(sprites.get(8),jeu.getLabyrinthe().getObjets().get(k).getX() * TAILLE,jeu.getLabyrinthe().getObjets().get(k).getY() * TAILLE,null);
		}
		
		//porte entree et sortir
		//entree
		g.drawImage(sprites.get(10), jeu.getLabyrinthe().getXEntree()*TAILLE, jeu.getLabyrinthe().getYEntree()*TAILLE, null);
		//sortie
		g.drawImage(sprites.get(11), jeu.getLabyrinthe().getXSortie()*TAILLE, jeu.getLabyrinthe().getYSortie()*TAILLE, null);
		
		//joueur
		this.dessinerSprite(g,(Entites)(this.jeu.getLabyrinthe().getAventurier()));
		
		//monstres
		g.setColor(Color.magenta);
		for(int i = 0; i < jeu.getLabyrinthe().getMonstres().size(); i++) {
			g.drawImage(sprites.get(7), jeu.getLabyrinthe().getMonstres().get(i).getX() * TAILLE, jeu.getLabyrinthe().getMonstres().get(i).getY() * TAILLE,null);
			//ecrit leur PV
			g.setColor(Color.white);
			g.drawString("PV : "+jeu.getLabyrinthe().getMonstres().get(i).getVie(), jeu.getLabyrinthe().getMonstres().get(i).getX() * TAILLE, jeu.getLabyrinthe().getMonstres().get(i).getY() * TAILLE);
		}
	
		//affichage des coeurs du hero
		//emplacements des coeurs
		for(int i=0; i<5; i++) {
			g.drawImage(sprites.get(13), 5+i*25, 450, null);
		}
		//les coeurs qui restent
		for(int i=0; i<jeu.getLabyrinthe().getAventurier().getVie(); i++) {
			g.drawImage(sprites.get(12), 5+i*25, 450, null);
		}
		
		//si cest la victoire du hero alors
		if(jeu.getLabyrinthe().getEtatPartie().equals("Victoire") ) {
			//on affiche le score, bravo et touche espace pour allez au prochain niveau !
			g.drawImage(sprites.get(9), (440-sprites.get(9).getWidth())/2, 100, null);
			g.setColor(Color.white);
			g.drawString("Victoire, niveau suivant avec ESPACE", 105, 130);
		}
		
		//si cest la defaite du hero alors
		if(jeu.getLabyrinthe().getEtatPartie().equals("Defaite") ) {
			//on affiche le score et perdu
			g.drawImage(sprites.get(9), (440-sprites.get(9).getWidth())/2, 100, null);
			g.setColor(Color.white);
			g.drawString("Défaite, vous avez parcouru "+jeu.getLabyrinthe().getAventurier().getEtageParcouru()+" étage(s)", 100, 130);
		}
		
		//on dessine l'emplacement de la medaille vide si on la pas attrape
		g.drawImage(sprites.get(14), 140, 450, null);
		//si on la attrape alors on le voit 
		if(jeu.getLabyrinthe().getAventurier().getHasAmulette()) {
			g.drawImage(sprites.get(15), 140, 450, null);
		}
		
		//on dessine le compteur d'étages
		g.drawImage(sprites.get(16), 180, 450, null);
		g.setColor(Color.black);
		g.drawString(" : "+jeu.getLabyrinthe().getAventurier().getEtageParcouru(), 210, 470);

		//fin de cette methode
		g.dispose();
	}
	
	/**
	 * methode qui dessine les images ou sprites
	 * @param g
	 * @param pion
	 */
	public void dessinerSprite(Graphics2D g,Entites pion) {
		Aventurier bob = (Aventurier)pion;
		if(pion instanceof Aventurier) {
			switch(bob.getFacing()) {
			case Labyrinthe.b :
				g.drawImage(sprites.get(1), bob.getX()*TAILLE,bob.getY()*TAILLE,null);
				break;
			case Labyrinthe.h :
				g.drawImage(sprites.get(2), bob.getX()*TAILLE,bob.getY()*TAILLE,null);
				break;
			case Labyrinthe.g :
				g.drawImage(sprites.get(4), bob.getX()*TAILLE,bob.getY()*TAILLE,null);
				break;
			case Labyrinthe.d : 
				g.drawImage(sprites.get(3), bob.getX()*TAILLE,bob.getY()*TAILLE,null);
				break;
			default : 
				g.drawImage(sprites.get(0), bob.getX()*TAILLE,bob.getY()*TAILLE,null);
				break;
			}
		}
	}
	
	/**
	 * permet de charger les images en memoire avant de les utiliser
	 */
	public void chargerSprites() {
		try {
			sprites.add(ImageIO.read(new File("src/ressources/idle.png")));
			sprites.add(ImageIO.read(new File("src/ressources/down.png")));
			sprites.add(ImageIO.read(new File("src/ressources/up.png")));
			sprites.add(ImageIO.read(new File("src/ressources/right.png")));
			sprites.add(ImageIO.read(new File("src/ressources/left.png")));
			//decors
			sprites.add(ImageIO.read(new File("src/ressources/cobble.png")));
			sprites.add(ImageIO.read(new File("src/ressources/wall.png")));
			//monstre
			sprites.add(ImageIO.read(new File("src/ressources/mdown.png")));
			//Medaille
			sprites.add(ImageIO.read(new File("src/ressources/medal.png")));
			//menu - 9
			sprites.add(ImageIO.read(new File("src/ressources/bannerScroll.png")));
			//porte entree et sortie
			sprites.add(ImageIO.read(new File("src/ressources/doorEntry.png")));
			sprites.add(ImageIO.read(new File("src/ressources/doorEnd.png")));
			//coeur
			sprites.add(ImageIO.read(new File("src/ressources/hearth.png")));
			sprites.add(ImageIO.read(new File("src/ressources/hearth_empty.png")));
			//medal vide - 14
			sprites.add(ImageIO.read(new File("src/ressources/medal_empty.png")));
			//petite medaille pleine - 15
			sprites.add(ImageIO.read(new File("src/ressources/medal_little.png")));
			//pimmeuble, etages - 16
			sprites.add(ImageIO.read(new File("src/ressources/stages.png")));
		
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	/**
	 * getter pour le jeu en cours
	 * @return JeuLabyrinthe, le jeu en cours
	 */
	public JeuLabyrinthe getJeu() {
		return jeu;
	}

	/**
	 * getter pour la liste des images
	 * @return ArrayList d'images
	 */
	public ArrayList<BufferedImage> getSprites() {
		return sprites;
	}

	/**
	 * getter pour la taille des cases du plateau de jeu
	 * @return int, la taille des cases
	 */
	public static int getTaille() {
		return TAILLE;
	}

}
