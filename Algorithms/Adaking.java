import java.util.*;

class ADAKING {
    public static void main(String[] args)
    {
        Scanner sc  = new Scanner(System.in);
        int N = sc.nextInt();
        for(int k=1;k<=N;k++)
        {
            int K = sc.nextInt();
            char[][] chess = new char[8][8];

            for(int i=0;i<8;i++)
            {
                for(int j=0;j<8;j++)
                {
                    chess[i][j]='.';
                }
            }
            
            int row = K/8;
            int column = K%8;

            if(row!=8)
            {
                for(int i =column;i<8;i++)
                {
                    chess[row][i]='X';
                }
            }

            if((row+1)<8)
            {
                for(int j=0;j<8;j++)
                {
                    chess[row+1][j]='X';
                }
            }
            
            chess[0][0]='O';

            for(int i=0;i<8;i++)
            {
                for(int j=0;j<8;j++)
                {
                    System.out.print(chess[i][j]);
                }
                System.out.println();
            }
        }

        sc.close();
    }  
}
