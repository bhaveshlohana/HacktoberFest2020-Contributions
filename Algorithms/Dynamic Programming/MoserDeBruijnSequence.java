import java.util.*;

public class MoserDeBruijnSequence  
{ 
    static int gen(int n) 
    {  
        int []S = new int [n + 1]; 
      
        S[0] = 0; 
        if(n != 0) 
            S[1] = 1; 
      
        for (int i = 2; i <= n; i++) 
        {  
            if (i % 2 == 0) 
            S[i] = 4 * S[i / 2]; 
            else
            S[i] = 4 * S[i/2] + 1; 
        } 
          
        return S[n]; 
    } 
  
    static void moserDeBruijn(int n) 
    { 
        for (int i = 0; i < n; i++) 
            System.out.print(gen(i)+" "); 
    } 
      
    public static void main(String[] args) 
    { 
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        System.out.println("First " + n + " terms of " + "Moser-de Bruijn Sequence : "); 
        moserDeBruijn(n); 
    } 
}