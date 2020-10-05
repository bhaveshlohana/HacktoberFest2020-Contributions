
import java.util.*;
import java.lang.*;

class SieveofEratosthenes {
	static boolean[] primenum = new boolean[1000007];
	public static void main (String[] args) {
		prime(1000000);
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
		    int n = sc.nextInt();
		    System.out.println(primenum[n]);
		}
	}
	
	public static void prime(int n){
	    
	    for(int i = 0; i<n; i++){
	        primenum[i] = true;
	    }
	    primenum[0]=primenum[1]=false;
	    for(int i = 2; i*i <= n; i++){
	        if( primenum[i] == true ){
	            for(int j = i*i; j<=n; j+= i){
	                primenum[j] = false;
	            }
	        }
	    }
	    
	    
 	}
}
