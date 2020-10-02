package defaultt;
import java.util.*;
public class Graph {
	
	public static void printDFSHelper(int edges[][],int sv,boolean visited[])
	{
		System.out.println(sv);
		visited[sv]=true;
		int n=edges.length;
		for(int i=0;i<n;i++)
		{
			if(edges[sv][i]==1 && !visited[i])  //if already visited dont go to that vertex
			{
				printDFSHelper(edges,i,visited);
			}
		}
	}
	public static void DFS(int edges[][])
	{
		boolean visited[]=new boolean[edges.length];
		for(int i=0;i<visited.length;i++) //loop over visited array
		{
			if(!visited[i])    //to take in the vertices which were not visited that is disconnected graphs
				//that is two differently connected components are taken into consideration
			{
				printDFSHelper(edges,i,visited);
			}
		}
		
	}
	public static void main(String[] args)
	{
		int n;
		int e;
		Scanner s=new Scanner(System.in);
		n=s.nextInt();
		e=s.nextInt();
		int edges[][]=new int[n][n];
		//wherever there is edge we keep 1
		for(int i=0;i<e;i++)
		{
			int fv=s.nextInt();  //final vertex
			int sv=s.nextInt();  //starting vertex
			edges[fv][sv]=1;
			edges[sv][fv]=1;
		}
		System.out.println("BFS");
		DFS(edges);
		System.out.println("BFS");
		printBFS(edges);
	}

}
