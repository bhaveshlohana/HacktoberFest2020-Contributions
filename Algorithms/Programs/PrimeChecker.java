import java.util.*;

public class PrimeChecker{
	public static void main(String args[]) 
	{
		//check if a number is prime or not

		Scanner scanner = new Scanner(System.in);
		int number = scanner.nextInt();

		if(isPrime(number))
			System.out.println(number + " is a prime number");
		else
			System.out.println(number + " is not a prime number");
	}

	public static boolean isPrime(int number)
	{
		// number 1 is not a prime number
		if(number == 1)
			return false;

		// all even numbers but 2 is not a prime number
		if(number != 2 && (number&1)==0)
			return false;

		for(int i = 3 ; i <= Math.sqrt(number) ; i+=2)
		{
			if(number%i == 0)
				return false;
		}

		return true;

	}
} 