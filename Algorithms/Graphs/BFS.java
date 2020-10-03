package defaultt;
import java.util.*;
public class Graph {
	
	public static void printBFSHelper(int edges[][],int sv,boolean visited[])
	{
		Queue<Integer> q=new LinkedList<>();
		q.add(sv);
		visited[sv]=true;
		int n=edges.length;
		while(!q.isEmpty())
		{
			int front;
			try
			{
				front=q.poll();	
			}
			catch (Exception e)
			{
				return ;
			}
			System.out.println(front);
			for(int i=0;i<n;i++)
			{
				if(edges[front][i]==1 && !visited[i])
				{
					q.add(i);
					visited[i]=true;
				}
			}
		}
		
	}
	public static void printBFS(int edges[][])
	{
		boolean visited[]=new boolean[edges.length];
		for(int i=0;i<edges.length;i++)
		{
			if(!visited[i])
			printBFSHelper(edges,i,visited);
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
		printBFS(edges);
	}

}
