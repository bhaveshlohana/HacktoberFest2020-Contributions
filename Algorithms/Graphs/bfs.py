from graph_directed import Graph
from graph_directed import Node
from graph_directed import Color

q = [] #queue for BFS

def enqueue(n):
    global q
    q = [n]+q

def dequeue():
    global q
    temp = q[len(q)-1]
    del(q[len(q)-1])
    return temp

def bfs(g):
    s = g.heads[0]

    for i in range(0, g.number_of_vertices):
        g.heads[i].color = Color.White
    s.color = Color.Gray

    enqueue(s)

    while(len(q)>0):
        u = dequeue()
        temp = u.head
        while(temp != None):
            if(g.heads[temp.index_of_item].color == Color.White):
                g.heads[temp.index_of_item].color = Color.Gray
                enqueue(g.heads[temp.index_of_item])
            temp = temp.next
        u.color = Color.Black
        print(u.data)

if __name__ == '__main__':
    g = Graph(7)

    g.add_edge(1, 2)
    g.add_edge(1, 5)
    g.add_edge(1, 3)
    g.add_edge(2, 6)
    g.add_edge(2, 4)
    g.add_edge(5, 4)
    g.add_edge(3, 4)
    g.add_edge(3, 7)

    bfs(g)
