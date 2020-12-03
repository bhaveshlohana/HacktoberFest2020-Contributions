#include <stdio.h>
#include <stdlib.h>
int visited[100];
int graph[100][100];
int q[100];
int n;
int top = -1;
int empty();
void create_graph();
void bfs(int);
void enqueue(int);
int dequeue();
int main()
{
    int source;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    create_graph();
    printf("Enter starting position : ");
    scanf("%d", &source);
    bfs(source);
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
void bfs(int v)
{
    printf("%d->",v);
    visited[v]=1;
    enqueue(v);
    int temp;
    while(!empty())
    {
        temp = dequeue();
        for(int i=1;i<=n;i++)
        {
            if(graph[temp][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                printf("%d->", i);
                enqueue(i);
            }
        }
    }
}
void enqueue(int n)
{
    top+=1;
    q[top] = n;
}
int dequeue()
{
    int temp = q[0];
    for(int i = 0;i<top;i++)
    {
        q[i] = q[i+1];
    }
    top-=1;
    return temp;
}
int empty()
{
    if (top==-1)
        return 1;
    else
        return 0;
}