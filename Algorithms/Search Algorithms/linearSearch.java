import java.util.Scanner;

class linearSearch { 
    // This function returns index of element x in arr[] 
    static int search(int arr[], int n, int x) 
    { 
        for (int i = 0; i < n; i++) { 
            // Return the index of the element if the element 
            // is found 
            if (arr[i] == x) 
                return i; 
        } 
  
        // return -1 if the element is not found 
        return -1; 
    } 
  
    public static void main(String[] args) 
    { 
    	Scanner sc= new Scanner(System.in);
    	System.out.print("Enter the number of elements to be inserted in an array:");
    	int num= sc.nextInt();
    	int[] arr = new int[num];
    	System.out.println("Enter the elements to be inserted:");
    	for(int i=0;i<num;i++) {
    		arr[i] = sc.nextInt(); 
    	}
        int len = arr.length; 
        System.out.print("Enter the integer to be searched in an array:"); 
        int x = sc.nextInt(); 
  
        int index = search(arr, len, x); 
        if (index == -1) 
            System.out.println("Element is not present in the array"); 
        else
            System.out.println("Element found at position " + index); 
    } 
}
