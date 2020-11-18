#include <stdio.h>
#include <stdlib.h>
int visited[100];
int graph[100][100];
int n;
int ctr;
void create_graph();
void dfs(int);
int components();
int main()
{
    int source;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    create_graph();
    //printf("Enter starting position : ");
    //scanf("%d", &source);
    printf("Components : %d", components());
}
void create_graph()
{
    int i,j;
    while (1)
    {
        printf("Enter source and destination vertex : ");
        scanf("%d %d", &i,&j);
        if(i==0 && j==0)
            break;
        else
            graph[i][j] = 1;
    }
}
void dfs(int v)
{
    visited[v]=ctr;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0 && graph[v][i]==1)
            dfs(i); 
    }
}
int components()
{
    ctr = 0;
    for (int i=1;i<=n;i++)
        visited[i]=0;
    for (int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            ctr++;
            dfs(i);
        }
    }
    return ctr;
}