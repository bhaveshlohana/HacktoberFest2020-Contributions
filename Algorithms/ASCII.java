/**
 * Reads a number by keyboard and display by console the character to which it belongs in the ASCII table
 * 
 * @author IryaDev
 */

import javax.swing.JOptionPane;
public class ASCII {
    public static void main(String[] args) {
 
        String text=JOptionPane.showInputDialog("Enter a code from the ASCII table");
        //We transform the String to int
        int code=Integer.parseInt(text);
 
        //We transform the code to character
        char character=(char)code;
 
        System.out.println(character);
    }
}