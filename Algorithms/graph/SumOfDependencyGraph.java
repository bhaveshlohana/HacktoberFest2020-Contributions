package Graph;


import java.util.*;

class Graph{
    private static LinkedList<Integer> adj[];

    public Graph(int v){
        adj = new LinkedList[v];
        for(int i = 0; i<v; i++){
            adj[i] = new LinkedList<Integer>();
        }
    }

    public static void addEdge(int s, int desc){
        adj[s].add(desc);
    }
    
    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();
        while(t-- > 0){
            int v = sc.nextInt();
            int e = sc.nextInt();
    
            Graph g = new Graph(v);
    
            for(int i = 0; i<e; i++){
                int s = sc.nextInt();
                int d = sc.nextInt();
    
                g.addEdge(s, d);
            }
            
            int count = 0;
            for(int i = 0; i<adj.length; i++){
                count += adj[i].size();
            }

            System.out.println(count);
        }
        
    }
}