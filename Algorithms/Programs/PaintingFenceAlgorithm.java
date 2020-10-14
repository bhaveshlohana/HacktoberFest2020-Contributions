import java.util.*;
public class PaintingFenceAlgorithm
{
    static long countWays(int n, int k)
    {
        long total = k,same = 0,diff = k;
        int mod = 1000000007;
 
        for(int i = 2; i <= n; i++) 
        {
            same = diff;
            diff = (int)total * (k - 1);
            diff = diff % mod;
            total = (same + diff) % mod;
        }
        return total;
    }
 
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        System.out.println(countWays(n, k));
    }
}