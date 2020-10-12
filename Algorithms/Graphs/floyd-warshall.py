'''
Floyd Warshall Algorithm finds All-pair shortest path for an weighted directed graph
It uses idea that distance to any points(v) must be greater sum of connecting edge weight(u,v) and preceding distance to the point(u)
'''


V = 4
INT_MAX = 9999
def floydWarshall(graph): 
	dist = [row[:] for row in graph]
	for src in range(V):
		# Take each vertex as source of path
		for dest in range(V): 
			# Take each vertex as destination of path
			for iterator in range(V): 
				'''
				Optimising each vertex between src and dest
				If vertex k is on the shortest path from  
				i to j, then update the value of dist[i][j] 
				'''
				dist[dest][iterator] = min(dist[dest][iterator], dist[dest][src] + dist[src][iterator]) 
	printSolution(dist) 
  
  
# A utility function to print the solution 
def printSolution(dist): 
	print("Following matrix shows the shortest distances between every pair of vertices:")
	for row in range(V): 
		for col in range(V): 
			if(dist[row][col] >= INT_MAX): 
				print("%5s"%("INF"),end=" ") 
			else: 
				print("%5d"%(dist[row][col]),end=" ")
		print("\n")
  
  
  
# Driver graph to check function
""" 
            10
       (0)------->(3)
        |         /|\ 
      5 |          | 
        |          | 1 
       \|/         | 
       (1)------->(2) 
            3           
"""
graph = [[0, 5, INT_MAX, 10], 
         [INT_MAX, 0, 3, INT_MAX], 
         [INT_MAX, INT_MAX, 0, 1], 
         [INT_MAX, INT_MAX, INT_MAX, 0] 
        ] 
        
# Find and print the solution 
floydWarshall(graph)
