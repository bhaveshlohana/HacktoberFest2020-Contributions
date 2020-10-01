import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

/*
 * 
 * Bucket Sort is used to Sort elements which are uniformly distributed across a range i.e 0.0 -1.0
 * 
 * Algorithm:-
		function bucketSort(arr[], n)
		1) Create n empty buckets (Or lists).
		2) Do following for every array element arr[i].
			a) Insert arr[i] into bucket[n*array[i]]
		3) Sort individual buckets using insertion sort.
		4) Concatenate all sorted buckets.
 * 
 * 
 * 
 * 
 * 
 * Best Case :- elements are uniformly distributed 
 * 				Time complexity :- O(n)
 * 				Space complexity :- O(n+k)  where k is size of bucket
 * 
 * 
 * Worst Case :- Time complexity :- O(n^2)
 * 				 Space complexity :- O(n+k)
 * 
 */


public class BucketSort {
	
	public static void bucketSort(double[] arr, int n) {

		HashMap<Integer, ArrayList<Double>> buckets = new HashMap<Integer, ArrayList<Double>>(10);
				
		
		for (double element :arr) {
			int index = (int) (element*10);
			
			ArrayList<Double> list; 
			
			if(buckets.get(index) == null) {
				list = new ArrayList<Double>();
			}
			else
				list = buckets.get(index);
			
			list.add(element);
			buckets.put(index,list);
		}
		
		for(int i=0;i<10;i++) {
			if(buckets.get(i)!=null) 
				Collections.sort(buckets.get(i));
		}
		
		int index = 0; 
	    for (Integer i : buckets.keySet()) 
			if(buckets.get(i)!=null) 
		        for (int j = 0; j < buckets.get(i).size(); j++) 
		          arr[index++] = (buckets.get(i)).get(j); 
		
	}
}

class BucketSortImplementation{
	
	public static void main(String[] args) {
		
		double arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434}; 
	    int n = arr.length;
	    
	    BucketSort.bucketSort(arr, n); 
	  
	    System.out.println("Sorted array is");
	    
	    for (int i=0; i<n; i++) 
	       System.out.println(arr[i]+" "); 
	}

	
}

/* Output
Sorted array is
0.1234 
0.3434 
0.565 
0.656 
0.665 
0.897 
 * 
 */


