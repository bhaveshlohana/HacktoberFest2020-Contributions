import java.util.Scanner;
import java.util.Random;

public class LinearSearch {
  
  public static void main(String[] args) {
    //Taking random number of instead of user input
    Random rd = new Random(); 
    int[] inputArray = new int[100];
    System.out.println("Array:");
    for (int i = 0; i < inputArray.length; i++) {
      inputArray[i] = rd.nextInt(100000) + 1; 
      System.out.print(inputArray[i] + " ");
    }
    System.out.println("\nInput Integer to Search:");
    Scanner sc = new Scanner(System.in);
    //Linear Search implementation starts here
    int searchKey = sc.nextInt();
    for (int i = 0; i < inputArray.length; i++) { 
      if (inputArray[i] == searchKey) 
        System.out.println(searchKey + " found at index: " + i);
    }
  }
  
}
