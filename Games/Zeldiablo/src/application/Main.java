package application;

import java.util.Scanner;

import moteurJeu.DessinJeu;
import moteurJeu.Jeu;
import moteurJeu.MoteurGraphique;
import moteurPerso.DessinPerso;
import moteurPerso.JeuPerso;

/**
 * classe principale, c'est le coeur du jeu
 * @author geronimus, grimmer, gross et meyer
 */
public class Main {   

	public static void main(String[] args)throws InterruptedException {
		
		// creation du jeu particulier et de son afficheur
		Jeu jeu = new JeuLabyrinthe();
		DessinJeu aff = new DessinLabyrinthe((JeuLabyrinthe) jeu);
		
		// classe qui lance le moteur de jeu generique
		MoteurGraphique moteur = new MoteurGraphique(jeu, aff);
		
		// lance la boucle de jeu qui tourne jusque la fin du jeu
		moteur.lancerJeu(440, 490);		
	}
}
