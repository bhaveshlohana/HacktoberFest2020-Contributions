import java.util.*; 
  
public class DilannoyNumber 
{
    static int dealnnoy(int n, int m) 
    { 
        int dp[][]=new int[m + 1][n + 1]; 
       
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = 1; 
        }
        for (int i = 0; i < m; i++) 
        {
            dp[0][i] = 1;   
        }
       
        for (int i = 1; i <= m; i++)  
        {
            for (int j = 1; j <= n; j++)  
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i][j - 1]; 
            }
        }
       
        return dp[m][n]; 
    } 
    
    public static void main(String args[]) 
    { 
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt(); 
        System.out.println(dealnnoy(n, m)); 
          
    } 
}