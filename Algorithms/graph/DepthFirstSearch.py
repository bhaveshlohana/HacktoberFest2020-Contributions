from collections import defaultdict

class Graph:

    def __init__(self):
        # default dictionary to store graph
        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)

    def DFSUtil(self, v, visited):

        visited[v] = True
        print(v, end = ' ')

        for i in self.graph[v]:
            if visited[i] == False:
                self.DFSUtil(i, visited)

    # The function to do DFS traversal
    def DFS(self, v):

        # Mark all the vertices as not visited
        visited = [False] * (max(self.graph)+1)
        self.DFSUtil(v, visited)

# Driver code

# Create a graph given
# in the above diagram
g = Graph()
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 3)

print("Following is DFS from (starting from vertex 1)")
g.DFS(1)
