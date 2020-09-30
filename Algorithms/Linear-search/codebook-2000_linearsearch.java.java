/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
    static int linearSearch(int arr[],int key)
    {
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]==key)
            return i;
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
		for(int j=0;j<n;j++)
		arr[j]=Integer.parseInt(st[j]);
		
		//Calling Linear Search
		int key=2;
		int index1=linearSearch(arr,key);
		
		
		if(index1==-1)
			System.out.print(key+" Not present in array");
		else
		System.out.println("Index of no="+key+" obtained from Linear Search = "+index1);

	}
}
