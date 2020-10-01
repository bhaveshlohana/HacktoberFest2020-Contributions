package moteurPerso;

import java.util.Scanner;


import moteurJeu.MoteurGraphique;

public class MainPerso {

	public static void main(String[] args) throws InterruptedException {
		// creation du jeu particulier et de son afficheur
				JeuPerso jeu = new JeuPerso();
				DessinPerso aff = new DessinPerso(jeu);
				
				// classe qui lance le moteur de jeu generique
				MoteurGraphique moteur = new MoteurGraphique(jeu, aff);
				// lance la boucle de jeu qui tourne jusque la fin du jeu
				moteur.lancerJeu(400, 400);
				
				// lorsque le jeu est fini
				System.out.println("Fin du Jeu - Appuyer sur Entree");
				Scanner sc=new Scanner(System.in);
				sc.nextLine();
				System.exit(1);


	}

}
