package moteurPerso;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;

import moteurJeu.DessinJeu;

public class DessinPerso implements DessinJeu {
	public static final int TAILLE = 20;
	private JeuPerso jeuEnCours;
	
	public DessinPerso(JeuPerso j) {
		this.jeuEnCours=j;
	}
	
	@Override
	public void dessiner(BufferedImage image) {
		Graphics2D g = (Graphics2D) image.getGraphics();
		g.setColor(Color.blue);
		g.fillOval(jeuEnCours.getX() * TAILLE, jeuEnCours.getY() * TAILLE, TAILLE, TAILLE);
		g.dispose();
	}

}
