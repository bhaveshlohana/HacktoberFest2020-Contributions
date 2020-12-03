package moteurJeu;

import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.image.BufferedImage;

import javax.swing.JPanel;

public class PanelDessin extends JPanel {

	/**
	 * la clase chargee de Dessiner
	 */
	private DessinJeu dessin;

	/**
	 * image suivante est l'image cachee sur laquelle dessiner
	 */
	private BufferedImage imageSuivante;

	/**
	 * image en cours est l'image entrain d'etre affichee
	 */
	private BufferedImage imageEnCours;

	/**
	 * la taille des images
	 */
	private int width, height;

	/**
	 * constructeur Il construit les images pour doublebuffering ainsi que le
	 * Panel associe. Les images stockent le dessin et on demande au panel la
	 * mise a jour quand le dessin est fini
	 * 
	 * @param width
	 *            largeur de l'image
	 * @param height
	 *            hauteur de l'image
	 */
	public PanelDessin(int x, int y, DessinJeu affiche) {
		super();
		this.setPreferredSize(new Dimension(x, y));
		this.width = x;
		this.height = y;
		this.dessin=affiche;

		// cree l'image buffer et son graphics
		this.imageSuivante = new BufferedImage(width, height,
				BufferedImage.TYPE_INT_RGB);
		this.imageEnCours = new BufferedImage(width, height,
				BufferedImage.TYPE_INT_RGB);
	}

	/**
	 * demande de mettre a jour le rendu de l'image sur le Panel. Creer une
	 * nouvelle image vide sur laquelle dessiner
	 */
	public void dessinerJeu() {
		// generer la nouvelle image
		this.dessin.dessiner(this.imageSuivante);

		// inverses les images doublebuffereing
		BufferedImage temp = this.imageEnCours;
		// l'image a dessiner est celle qu'on a construite
		this.imageEnCours = this.imageSuivante;
		// l'ancienne image est videe
		this.imageSuivante = temp;
		this.imageSuivante.getGraphics()
				.fillRect(0, 0, this.width, this.height);
		// met a jour l'image a afficher sur le panel
		this.repaint();
	}

	/**
	 * redefinit la methode paint consiste a dessiner l'image en cours
	 * 
	 * @param g
	 *            graphics pour dessiner
	 */
	public void paint(Graphics g) {
		super.paint(g);
		g.drawImage(this.imageEnCours, 0, 0, getWidth(), getHeight(), 0, 0,
				getWidth(), getHeight(), null);
	}

}
