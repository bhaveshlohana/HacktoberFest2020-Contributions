// A simple Java program to Roll Two Dice
import java.util.Scanner;

public class DiceRollerApp {

	public static void main(String[] args) {

		//Welcome
		System.out.println("Dice Roller\n");
		Scanner sc = new Scanner(System.in);
		String choice = "y";

		while (choice.equalsIgnoreCase("y")) {
			System.out.print("Feeling lucky? (y/n)");
			sc.nextLine();
			int d1 = (int) (Math.random() * 6) + 1;
			int d2 = (int) (Math.random() * 6) + 1;
			int t = d1 + d2;


			System.out.println();
			System.out.println("Die 1: " +d1);
			System.out.println("Die 2: " +d2);
			System.out.println("Total: " +t);

			if (t == 2) {
				System.out.println("Snake eyes!");
			}
			else if (t == 12) {
				System.out.println("Box Cars");
			}
			else {
			}
			System.out.println();


			choice = getString(sc, "Try again? (y/n)");
		}

		sc.close();
		System.out.println("Better luck next time");

	}


	private static String getString(Scanner sc, String prompt) {
		String s = "";
		boolean isValid = false;
		//Keep prompting user until enters y or n
		while (!isValid) {
			System.out.println(prompt);
			s = sc.nextLine();
			//Check for empty string
			if (s.equalsIgnoreCase("")) {
				System.out.println("Error....entry is required");
				continue;
			}
			else if (s.equalsIgnoreCase("y")||s.equalsIgnoreCase("n")) {
				isValid = true;
			}
			else {
				System.out.println("Error....only 'y' or 'n' is accepted.");
				continue;
			}

		}
		return s;
	}
}