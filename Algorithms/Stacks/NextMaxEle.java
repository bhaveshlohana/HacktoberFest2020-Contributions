package stack;

import java.util.*;

class NextMaxEle {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
		    int n = sc.nextInt();
		    int[] arr = new int[n];
		    for(int i = 0; i<n; i++){
		        arr[i] = sc.nextInt();
		    }
		    nextLargerEle(arr, n);
		    System.out.println();
		}
	}
	
	public static void nextLargerEle(int[] arr, int n){
	    Stack<Integer> s = new Stack<Integer>();
	    s.push(arr[0]);
	    int ele, next;
	    
	    for(int i = 1; i<n; i++){
	        next = arr[i];
	        if( !s.isEmpty() ){
	            ele = s.pop();
	            while(ele < next){
	                System.out.println(ele + " -> " + next);
	                if( s.isEmpty() ){
	                    break;
	                }
	                ele = s.pop();
	            }
	            if( ele > next ){
	                s.push(ele);
	            }
	        }
	        s.push(next);
	    }
	    while (s.isEmpty() == false) { 
            ele = s.pop(); 
            next = -1; 
            System.out.println(ele + " -> " + next); 
        } 
	}
}