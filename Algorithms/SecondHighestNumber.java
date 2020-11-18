/** WAP to find the second Largest number 
 * @author Indrajit Bhattacharjee
  @Date Jan 19,2019
 *
 */

package codes;

public class SecondHighestNumber {

	public static void main(String[] args) {
		int n[] = { 6, 15, 2, 100, 98, 77, 55 };
		int max = n[0];
		int secondMax = n[0];

		for (int i = 0; i < n.length; i++) {
			if (n[i] > max) {
				secondMax = max;
				max = n[i];

			} else if (n[i] > secondMax) {
				secondMax = n[i];
			}
		}

		System.out.println("First Max number " + max);
		System.out.println("Second  Max number " + secondMax);
	}

}
