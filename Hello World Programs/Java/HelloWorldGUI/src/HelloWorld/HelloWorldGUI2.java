package HelloWorld;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.awt.Dimension;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class HelloWorldGUI2 extends JPanel{

    private static final long serialVersionUID = 1L;
    private final BufferedImage image;

    private HelloWorldGUI2() throws IOException {
        final File imageFile = new File("src/globe.png");
        final String absolutePath = imageFile.getAbsolutePath();
        this.image = resizeBufferedImage(ImageIO.read(new File(absolutePath)), 100, 100);
        this.displayImage();
    }

    public static void main(final String[] args) {
        try {
            new HelloWorldGUI2();
        } catch (final IOException e) {
            e.printStackTrace();
        }
    }

    private final BufferedImage resizeBufferedImage(final BufferedImage img, final int newW, final int newH) { 
        final Image image = img.getScaledInstance(newW, newH, Image.SCALE_SMOOTH);
        final BufferedImage bfImage = new BufferedImage(newW, newH, BufferedImage.TYPE_INT_ARGB);
        final Graphics2D g2d = bfImage.createGraphics();
        g2d.drawImage(image, 0, 0, this);
        g2d.dispose();
        return bfImage;
    }

    private void displayImage() {

        final JFrame jf = new JFrame("Hello World");

        final JLabel label = new JLabel("Hello World");
        label.setVisible(true);

        final Dimension size = label.getPreferredSize();
        label.setBounds(120, 40, size.width, size.height);
        jf.add(label);

        jf.setSize(250, 140);
        jf.getContentPane().add(this);
        jf.setLocationRelativeTo(this);
        jf.setVisible(true);
        jf.setResizable(false);
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    @Override
    protected void paintComponent(final Graphics g) {
        super.paintComponent(g);
        g.drawImage(this.image, 0, 0, this);
    }
}