import java.util.Scanner;

public class SieveOfEratosthenes {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
		int n=s.nextInt();
		boolean prime[]= new boolean[n+1];
		for(int i=0;i<=n;i++)
		{
			prime[i]=true;
		}
		for(int p=2;p*p<=n;p++)
		{
			
			if(prime[p]==true)
			{
				for(int i=p*p;i<=n;i=i+p)
				{
					prime[i]=false;
				}
				
			}
			
		}
		for(int i=2;i<=n;i++)
		{
			if(prime[i]==true)
			{
				System.out.println(i+" ");
			}
			
		}
		
		
		
		

	}

}
