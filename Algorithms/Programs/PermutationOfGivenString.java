import java.util.*;

class PermutationOfGivenString {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
		    String str = sc.next();
		    int n = str.length();
		    permute( str, 0 , n-1 );
		    System.out.println();
		}
		sc.close();
	}
	public static void permute(String str, int l, int r){
	    if( l == r ){
	        System.out.print(str + " ");
	    }else{
	        for(int i = l; i<=r; i++){
	            str = swap( str, l, i );
	            permute(str, l+1, r);
	            str = swap(str, l, i);
	        }    
	    }
	}
	public static String swap( String a, int i, int j ){
	    char temp;
	    char[] ca = a.toCharArray();
	    temp = ca[i];
	    ca[i] = ca[j];
	    ca[j] = temp;
	    return String.valueOf(ca);
	}
}