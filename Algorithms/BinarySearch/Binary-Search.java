import java.util.Arrays;
import java.util.Scanner;


/**
 * 
 * Binary Search is optimization of linear search. 
 * Binary Search works only on sorted data .
 * After each comparision the  array to be searched is reduced  to half
 * 
 * Time Complexity:-
 * 		Best Case:- element present at the start of the element 
 * 					O(1)
 * 		
 * 		Worst Case :- element not present in the list
 * 					O(logn)
 *
 * Space Complexity:- O(1)
 */


public class BinarySearch {

	public static int search(int[] arr, int key) {
		Arrays.parallelSort(arr);
		return binarySearch(arr,key,0,arr.length-1);
	}

	private static int binarySearch(int[] arr, int key, int L, int R) {

		for(;L<R;) {
			int m = (L+R)/2;
			if(arr[m] == key)
				return m;
			else if(arr[m] > key)
				R=m-1;
			else
				L=m+1;		
		}
		return -1;
	}

	
	
}


class BinarySearchImplementation {
	
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
	
		int result = BinarySearch.search(arr,key);
		
		if(result == -1)
			System.out.println("The element is not present in list");
		else
			System.out.print("The element is present");

	}
	
}


/*
Enter the number of Elements
5
Enter the Elements
5 4 3 2 1 
Enter the Element to be searched :4
The element is present

Enter the number of Elements
3
Enter the Elements
1 2 3
Enter the Element to be searched :4
The element is not present in list



*/
