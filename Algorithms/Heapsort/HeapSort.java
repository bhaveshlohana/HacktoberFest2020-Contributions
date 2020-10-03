import java.util.Scanner;

/**
 * 
 *		
 *	Time Complexity:- O(nlogn)
 *							
 *
 *	Space Complexity:- O(logn)
 *		
 */

public class HeapSort {
	
	public static void sortArray(int A[]) {
		int n =A.length;

		build_MAX_HEAP(A, n);      // takes logn
		
		for(int i = n-1;i>1;i--)   // executed roughly n times
		{
			int temp = A[i];
			A[i] = A[1];
			A[1]=temp;	
			swap(A, i, 1);

			n--;
			MAX_HEAPIFY(A, 1,n);   //logn
		}
		
		
	}

	private static void build_MAX_HEAP(int[] A, int n) {
		for(int i = (n-1)/2;i>0;i-- ){
			MAX_HEAPIFY(A,i,n);
		}
	}
	
	private static void MAX_HEAPIFY(int[] a, int i,int len) {
		int l = 2*i;
		int r = 2*i + 1;
		int largest=0;
		
		if(l < len && a[i]< a[l])
				largest=l;
			else largest= i;
			
		if(r < len && a[largest] < a[r])
			largest=r;
		
		if(largest != i)
		{
			swap(a, i, largest);
			MAX_HEAPIFY(a, largest,len);
		}	
	}

	private static void swap(int[] a, int i, int largest) {
		int temp = a[i];
		a[i] = a[largest];
		a[largest]=temp;
	}
}

class HeapSortImplementation{

	public static void main(String[] args) {

		Scanner s=new Scanner(System.in);
		System.out.println("Enter the number of Elements");
		
		int n=s.nextInt();
		int arr[]=new int[n+1];
		
		System.out.println("Enter the Elements");
		for(int i=1;i<=n;i++)
			arr[i]=s.nextInt();
		
		System.out.print("The Array before Sorting :");
		printArray(arr);

		
		HeapSort.sortArray(arr);
		
		System.out.print("The Sorted Array :");
		printArray(arr);	
	}
	private static void printArray(int[] arr) {
		
		for(int i=1; i<arr.length;i++)
			System.out.print(arr[i]+" ");
		System.out.println();
	}
}



/*
Enter the number of Elements
10
Enter the Elements
10 9 8 7 6 5 4 3 2 1 
The Array before Sorting :10 9 8 7 6 5 4 3 2 1 
The Sorted Array :1 2 3 4 5 6 7 8 9 10 


*/