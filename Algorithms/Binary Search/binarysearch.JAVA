
import java.util.*;
public class implement_bs {
static int bs(int a[],int n,int k) {
	int l=0;
	int h=n-1;
    while(l<=h) {
    	int m=l+(h-l)/2;
    	if(a[m]>k) {
    		h=m-1;
    	}
    	else if(a[m]<k)
    		l=m+1;
    	else
    		return m;
    }
	return -1;
}
public static void main(String args[]) {
	Scanner sc=new Scanner(System.in);
	int n=sc.nextInt();
	int a[]=new int[n];
	for(int i=0;i<n;i++) {
		a[i]=sc.nextInt();
		
	}
	int k=sc.nextInt();
	Arrays.parallelSort(a);
			
	System.out.println(bs(a,n,k));
}
}
