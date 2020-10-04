#include <stdio.h>
#include <stdlib.h>
int visited[100];
int path[100];
int graph[100][100];
int n;
int length = 0;
void create_graph();
void dfs(int);
int findpath(int,int);
int main()
{
    int source, destination;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    create_graph();
    printf("Enter starting position and last position: ");
    scanf("%d %d", &source, &destination);
    for (int i=1;i<=n;i++)
        visited[i]=0;
    if(findpath(source,destination))
    {
        printf("Path Found!\n");
        for(int i=1;i<=length;i++)
            printf("%d->",path[i]);
        printf("\n");
    }
    else
    {
        printf("No path found.\n");
    }
    
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
int findpath(int source,int destination)
{
    visited[source] = 1;
    for(int i = 1;i<=n;i++)
    {
        if (graph[source][i]==1 && visited[i]==0)
        {
            length+=1;
            path[length] = i;
            if (i==destination || findpath(i,destination))
                return 1;
        }
    }
    length--;
    return 0;
}