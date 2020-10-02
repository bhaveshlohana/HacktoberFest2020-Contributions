
import java.util.*;
import java.lang.*;

class SieveofEratosthenes {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
		    int n = sc.nextInt();
		    prime(n);
		}
	}
	
	public static void prime(int n){
	    boolean[] primenum = new boolean[n+1];
	    for(int i = 0; i<n; i++){
	        primenum[i] = true;
	    }
	    
	    for(int i = 2; i*i <= n; i++){
	        if( primenum[i] == true ){
	            for(int j = i*i; j<=n; j+= i){
	                primenum[j] = false;
	            }
	        }
	    }
	    
	    for(int i = 2; i <= n; i++){
	        if( primenum[i] ){
	            System.out.print(i + " ");
	        }
	    }
	    System.out.println();
 	}
}
