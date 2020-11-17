package college;

public class binarySearch {

	public static void main(String[] args) {
		int ar[] = {1,2,5,8,12,27, 31,42};
		int element = 27;
		int ans = binarySearch(ar, 0, 7, element);
		if (ans!=-1)
				System.out.println("element found at "+ans);
		else
			System.out.println("not found");
	}
	
	static int binarySearch(int[] ar, int start, int end, int element) {
		if (start>end)
			return -1;
		int mid = (start + end)/2;
		if (element == ar[mid])
			return mid;
		else if(element > ar[mid]) 
			 return binarySearch(ar, mid+1, end, element);
		else if(element < ar[mid])
			return binarySearch(ar, start, mid-1, element);
		return mid;
		
	}

}
