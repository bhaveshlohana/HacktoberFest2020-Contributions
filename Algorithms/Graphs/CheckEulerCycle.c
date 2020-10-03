#include <stdio.h>
#include <stdlib.h>
int visited[100];
int graph[100][100];
int n;
void create_graph();
void dfs(int);
int main()
{
    int source;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    create_graph();
    if (check())
        printf("Euler");
    else
        printf("Not Euler");
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
int check()
{
    int count;
    for(int i=1;i<=n;i++)
    {
        count = 0;
        for(int j=1;j<=n;j++)
        {
            if(graph[i][j]==1)
                count++;
        }
        if((count%2)!=0)
            return 0;
    }
    return 1;
}