/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    static int binarySearch(int arr[],int key)
    {
        
        int lo=0;
        int hi=arr.length-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(arr[mid]==key)
            return mid;
            else if(arr[mid]<key)
            lo=mid+1;
            else
            hi=mid-1;
        }
        return -1;
    }
    
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		BufferedReader buf=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(buf.readLine());
		int arr[]=new int[n];
		String st[]=(buf.readLine()).split(" ");
			//For Binary search array must be in sorted order
		for(int j=0;j<n;j++)
		arr[j]=Integer.parseInt(st[j]);
		
        
		//Calling Binary Search
		int key=2;
		int index2=binarySearch(arr,key);
		
		
		//-1 indicates not present in array 
		if(index2==-1)
		System.out.println(key+" Not present in array");
		else
		System.out.println("Index of no="+key+" obtained from Binary Search = "+index2);

	}
}
