#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef long long ll;

struct Node {
  ll vertex;
  struct Node* next;
};

struct Graph {
  ll vertices;
  struct Node** adjacencyList;
};

void dfs_recur(struct Graph* graph, ll vertex,ll visited[]) {
  struct Node* adjList = graph->adjacencyList[vertex];
  struct Node* temp = adjList;

  visited[vertex] = 1;
  printf("%lld , ", vertex);

  while (temp != NULL) {
      if(temp==NULL)break;
    ll connectedVertex = temp->vertex;
    if (visited[connectedVertex] == 0) {
      dfs_recur(graph, connectedVertex,visited);
    }
    temp = temp->next;
  }
}

struct Node* createNode(ll v){
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createGraph(ll vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->vertices = vertices;
  graph->adjacencyList = malloc(vertices * sizeof(struct Node*));
  for (ll i = 0; i < vertices; i++)
    graph->adjacencyList[i] = NULL;
  return graph;
}

void add(struct Graph* graph, ll start, ll ends) {
  struct Node* newNode = createNode(ends);
  newNode->next = graph->adjacencyList[start];
  graph->adjacencyList[start] = newNode;
  newNode = createNode(start);
  newNode->next = graph->adjacencyList[ends];
  graph->adjacencyList[ends] = newNode;
}

void printGraph(struct Graph* graph) {
  for (ll v = 0; v < graph->vertices; v++) {
    struct Node* temp = graph->adjacencyList[v];
    printf("Adjacency list of %lld -----", v);
    while(temp)
      printf("- %lld ", temp->vertex),temp = temp->next;
    printf("\n");
  }
}

int main() {
    ll e,start,a,b,v;
    printf("Enter the number of edges and vertices respectively\n");
    scanf("%lld %lld",&e,&v);
    struct Graph* graph = createGraph(v);
    printf("Enter the two vertices for which a particular edge is connected\n");
    for (ll i=0;i<e;i++){
        scanf("%lld %lld",&a,&b);
        add(graph,a,b);
    }
    printGraph(graph);
    printf("Enter the vertex from which u want to start dfs\n");
    scanf("%lld",&start);
    ll visited[v];
        for (ll i=0;i<v;i++) visited[i]=0;
    printf("Visited ----> ");
    //for(ll i=0;i<v;i++) {printf("%lld",visited[i]);}
    dfs_recur(graph,start,visited);
    //for (ll i=0;i<v;i++) printf("%lld \t",visited[i]);
    for(ll i=0;i<v;i++) if (visited[i]==0) dfs_recur(graph,i,visited);
   return 0;
}
