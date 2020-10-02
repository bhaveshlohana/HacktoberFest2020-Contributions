import java.util.Scanner;


/**
 * 
 * 
 * Linear Search scans each elements in the array 
 * 
 * Time Complexity:-
 * 		Best Case:- element present at the start of the element 
 * 					O(1)
 * 		
 * 		Worst Case :- element not present in the list
 * 					O(n)
 *
 * Space Complexity:-  O(1) Constant Space
 */
public class LinearSearch {

	public static int search(int[] arr, int key) {

		for(int i=0;i<arr.length;i++)
		{
			if(arr[i] == key)
				return i;
		}
		
		return -1;
	}
}


class LinearSearchImplementation {
	
	public static void main(String[] args) {

		Scanner s=new Scanner(System.in);
		System.out.println("Enter the number of Elements");
		
		int n=s.nextInt();
		int arr[]=new int[n];
		
		System.out.println("Enter the Elements");
		for(int i=0;i<n;i++)
			arr[i]=s.nextInt();
		
		System.out.print("Enter the Element to be searched :");
		int key=s.nextInt();
	
		int result = LinearSearch.search(arr,key);
		
		if(result == -1)
			System.out.println("The element is not present in list");
		else
			System.out.print("The element is present at :"+ (result+1)+" position" );

	}
	
}

/*
 * 
Enter the number of Elements
5
Enter the Elements
1 2 10 9 3
Enter the Element to be searched :10
The element is present at :3 position


Enter the number of Elements
5
Enter the Elements
1 2 10 9 3
Enter the Element to be searched :7
The element is not present in list






*/

