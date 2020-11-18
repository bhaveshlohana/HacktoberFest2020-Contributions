## Edmonds–Karp algorithm
### Introduction
Finding the maximum flow for a network was first solved by the Ford-Fulkerson algorithm. A network is often abstractly defined as a graph, G, that has a set of vertices, V, connected by a set of edges, E. There is a source, s, and a sink, t, which represent where the flow is coming from and where it is going to. Finding the maximum flow through a network was solved via the max-flow min-cut theorem, which then was used to create the Ford-Fulkerson algorithm.

**Edmonds-Karp** is identical to Ford-Fulkerson except for one very important trait. The search order of augmenting paths is well defined. As a refresher from the Ford-Fulkerson wiki, augmenting paths, along with residual graphs, are the two important concepts to understand when finding the max flow of a network.

**Edmonds-Karp differs from Ford-Fulkerson in that it chooses the next augmenting path using breadth-first search (bfs). So, if there are multiple augmenting paths to choose from, Edmonds-Karp will be sure to choose the shortest augmenting path from the source to the sink.**

Edmonds-Karp improves the runtime of Ford-Fulkerson, which is O(|E|.f*), to O(|V|.|E|^2). This improvement is important because it makes the runtime of Edmonds-Karp independent of the maximum flow of the network, f*.

### Algorithm Pseudo-Code
inputs
    C[n x n] : Capacity Matrix
    E[n x n] : Adjacency Matrix
    s : source
    t : sink
output
    f : maximum flow
Edmonds-Karp:
    f = 0                // Flow is initially 0
    F = [n x n]       // residual capacity array
    while true:
        m, P = Breadth-First-Search(C, E, s, t, F)
        if m = 0:
            break
        f = f + m
        v = t
        while v != s:
            u = P[v]
            F[u, v] = F[u, v] - m       //This is reducing the residual capacity of the augmenting path
            F[v, u] = F[v, u] + m        //This is increasing the residual capacity of the reverse edges 
            v = u
    return f

### Complexity
Edmonds-Karp makes some important improvement on the Ford-Fulkerson algorithm. Ford-Fulkerson simply states that the flow increases by at least 1 in every iteration. Each iteration takes O(∣E∣) time. So, all Ford-Fulkerson can promise is that the maximum flow is found in O(|E|.f*), where f* is the maximum flow itself.

Edmonds-Karp removes the dependency on maximum flow for complexity, making it much better for graphs that have a large maximum flow,  Edmonds-Karp runs each iteration in O(∣E∣) time and that there are at most ∣V∣⋅∣E∣ iterations, Edmonds-Karp is bounded by 
O(|V|.|E^2|).

### Helpful Links
- [The Edmonds-Karp Max-Flow Algorithm](https://www.cs.cornell.edu/courses/cs4820/2012sp/handouts/edmondskarp.pdf)
- [Maximum flow - Ford-Fulkerson and Edmonds-Karp](https://cp-algorithms.com/graph/edmonds_karp.html)
- [Advanced Algorithms and Complexity](https://www.coursera.org/lecture/advanced-algorithms-and-complexity/the-edmonds-karp-algorithm-JLA96)
- [Edmonds-Karp Algorithm](https://brilliant.org/wiki/edmonds-karp-algorithm/)
- [Maximum Flows, Minimum Cuts, Residual Graphs, The Edmonds-Karp Algorithm](http://web.eecs.utk.edu/~jplank/plank/classes/cs302/Notes/Netflow1/)
- [EDMONDS-KARP ALGORITHM](https://dkim7240.wixsite.com/edmondskarp/what-is-edmonds-karp-algorithm)