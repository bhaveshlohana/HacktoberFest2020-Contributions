import java.util.*; 
  
public class GolombSequence 
{       
    public static void printGolomb(int n) 
    { 
        int dp[] = new int[n + 1]; 
        dp[1] = 1; 
        System.out.print(dp[1] + " "); 

        for (int i = 2; i <= n; i++)  
        { 
            dp[i] = 1 + dp[i - dp[dp[i - 1]]]; 
              
        System.out.print(dp[i] + " "); 
        } 
    } 
          
    public static void main (String[] args) 
    { 
	Scanner in = new Scanner(System.in);
        int n = in.nextInt();  
          
        printGolomb(n); 
    } 
}