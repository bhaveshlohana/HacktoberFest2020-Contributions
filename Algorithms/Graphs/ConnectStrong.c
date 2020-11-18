#include <stdio.h>
#include <stdlib.h>
int visited[100];
int graph[100][100];
int n;
void create_graph();
void dfs(int);
int checkconnection();
int main()
{
    int source;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    create_graph();
    printf("Enter starting position : ");
    scanf("%d", &source);
    int result = checkconnection();
    if (result)
        printf("\nGraph is strongly connected!\n");
    else
        printf("\nGraph is weakly connected!\n");
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
    printf("%d->",v);
    visited[v]=1;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0 && graph[v][i]==1)
            dfs(i); 
    }
}
int checkconnection()
{
    for(int i = 1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            visited[j]=0;
        }
        dfs(i);
        printf("\n");
        for(int j=1;j<=n;j++)
        {
            if(visited[j]==0)
                return 0;
        }
    }
    return 1;
}