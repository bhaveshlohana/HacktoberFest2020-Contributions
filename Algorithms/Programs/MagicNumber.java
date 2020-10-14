import java.util.*;
public class MagicNumber {
       
    public static void main(String args[]) {
        System.out.println("Enter any number : ");    
        Scanner scan = new Scanner(System.in);
        int inputNumber = scan.nextInt();
        boolean result = checkMagicNumber(inputNumber);
        if(result)
            System.out.println(inputNumber +" is a Magic Number");          
        else
            System.out.println(inputNumber +" is NOT a Magic Number");
    }
    
    public static boolean checkMagicNumber(int inputNumber) { 
        // Initialize sumOfDigits of inputNumber 
        int sumOfDigits = 0;
        // Create a copy of the inputNumber 
        int number = inputNumber;
 
        while( sumOfDigits > 9 || number > 0) {
        /* if number is zero and sumOfDigits is non-zero
           then the loop will continue.
           Loop will stop when number is zero and
           sumOfDigits becomes a single digit */    
            if (number == 0) {
                number = sumOfDigits;
                sumOfDigits = 0;
            }
            sumOfDigits = sumOfDigits + (number % 10);
            number = number / 10;
        } 
         /* If sumOfDigits is equal to 1 then 
            the number is Magic number, otherwise not */ 
            return (sumOfDigits == 1);
    }
}