#include <stdio.h>
#include <stdlib.h>
int visited[100];
int n;
void create_graph(int(*)[100]);
void dfs(int(*)[100], int);
int strong_connect(int(*)[100]);
int weak_connect(int(*)[100]);
void remove_edge(int (*)[100], int(*)[100]);
int main()
{
    int source;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    int graph[100][100],disconnected[100][100];
    create_graph(graph);
    int result = strong_connect(graph);
    if (result)
        printf("Strongly Connected!\n");
    else
    {
        for (int i=0;i<=100;i++)
        {
            for (int j=0;j<=100;j++)
                disconnected[i][j]=0;
        }
        remove_edge(graph,disconnected);
        if (weak_connect(disconnected))
            printf("Weakly Connected");
        else
            printf("Not Connected.");
    }
}
void create_graph(int (*graph)[100])
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
void dfs(int (*graph)[100],int v)
{
    printf("%d->",v);
    visited[v]=1;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0 && graph[v][i]==1)
            dfs(graph, i); 
    }
}
int strong_connect(int(*graph)[100])
{
    for(int i = 1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            visited[j]=0;
        dfs(graph, i);
        printf("\n");
        for(int j=1;j<=n;j++)
        {
            if(visited[j]==0)
                return 0;
        }
    }
    return 1;
}
void remove_edge(int (*a)[100], int(*b)[100])
{
    for (int i=1;i<=100;i++)
    {
        for (int j=1;j<=100;j++)
        {
            if(a[i][j]==1)
            {
                b[i][j]=1;
                b[j][i]=1;
            }
        }
    }
    printf("created\n");
}
int weak_connect(int (*a)[100])
{
    for(int i = 1;i<=n;i++)
        visited[i]=0;
    dfs(a, 1);
    for(int j=1;j<=n;j++)
    {
        if(visited[j]==0)
            return 0;
    }
    return 1;
}