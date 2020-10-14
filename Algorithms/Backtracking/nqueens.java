class Solution {
    static List<List<String>> ans;
    public List<List<String>> solveNQueens(int n) {
        ans=new ArrayList<>();
        char[][] board=new char[n][n];
        for(char[] c: board){
            Arrays.fill(c,'.');
        }
        build(0,board,n);
        return ans;
        
    }
    
    
    public static void build(int col,char[][] board,int n){
        if(col>=n){
            List<String> li=new ArrayList<>();
            for(char c[]: board){
                String s=new String(c);
                li.add(s);
            }
            ans.add(li);
           // System.out.println("............");
            return;
            
        }
        
        for(int i=0;i<n;i++){
            if(isval(i,col,board,n)){
                board[i][col]='Q';
                build(col+1,board,n);
                    
                
                board[i][col]='.';
                
            }
            
            
            
        }
        
        
     
        
    }
    
    
    
    public static boolean isval(int row,int col,char[][] board,int n){
        
        //row left
        for(int i=0;i<col;i++){
            if(board[row][i]=='Q') return false;
        }
        
        
        
        //col up left
          for(int i=row,j=col;i>=0&&j>=0;i--,j--){
            if(board[i][j]=='Q') return false;
        }
        
        //col down left
          for(int i=row,j=col;i<n&&j>=0;i++,j--){
            if(board[i][j]=='Q') return false;
        }
        
        return true;
        
    }
    
    
    
    
    
    
    
    
    
}
