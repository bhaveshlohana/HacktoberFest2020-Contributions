package HelloWorld;

import java.awt.Image;
import java.io.File;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.SwingConstants;

public class HelloWorldGUI{

    public static void main(final String[] args) {
        new HelloWorldGUI();
    }

    private HelloWorldGUI() {
        this.displayImage();
    }

    private ImageIcon resizeIcon(final String path, final int resizedWidth, final int resizedHeight) {
        final Image img = new ImageIcon(new File(path).getAbsolutePath()).getImage();
        final Image resizedImage = img.getScaledInstance(resizedWidth, resizedHeight,  java.awt.Image.SCALE_SMOOTH);
        return new ImageIcon(resizedImage);
    }

    private void displayImage() {

        final JFrame jf = new JFrame("Hello World");

        final JLabel label = new JLabel("Hello World", this.resizeIcon("src/globe.png", 100, 100), SwingConstants.CENTER);
        label.setVisible(true);

        label.setSize(120, 40);
        jf.add(label);

        jf.setSize(250, 140);
        jf.setLocationRelativeTo(null);
        jf.setVisible(true);
        jf.setResizable(false);
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}