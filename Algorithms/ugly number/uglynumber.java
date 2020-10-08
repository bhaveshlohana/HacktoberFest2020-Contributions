import java.util.*;

class UglyNumber {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
		    int n = sc.nextInt();
		    System.out.println(ugly(n));
		}
    }
    
	public static int ugly(int n){
	    int[] uglynum = new int[n];
	    int i2 = 0, i3 = 0, i5 = 0;
	    int nm2 = 2, nm3 = 3, nm5 = 5;
	    int num = 1;
	    
	    uglynum[0] = 1;
	    for(int i = 1; i<n; i++){
	        num = Math.min( nm2, Math.min( nm3, nm5 ));
	        
	        uglynum[i] = num;
	        if( num == nm2 ){
	            i2 = i2+1;
	            nm2 = uglynum[i2]*2;
	        }
	        if( num == nm3 ){
	            i3 = i3+1;
	            nm3 = uglynum[i3]*3;
	        }
	        if( num == nm5 ){
	            i5 = i5+1;
	            nm5 = uglynum[i5]*5;
	        }
	    }
	    return num;
	}
}