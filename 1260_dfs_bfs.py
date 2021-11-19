from collections import defaultdict
import sys
input = sys.stdin.readline

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
    
    def addEdge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def DFS_util(self, v, visited):
        visited.add(v)
        print(v, end=' ')

        for neighbor in sorted(self.graph[v]):
            if neighbor not in visited:
                self.DFS_util(neighbor, visited)

    def DFS(self, v):
        visited = set()
        self.DFS_util(v, visited)

    def BFS(self, v):
        visited = [False] * (max(self.graph) + 1)

        queue = []
        queue.append(v)
        visited[v] = True
        while queue:
            v = queue.pop(0)
            print(v, end=' ')
            
            for i in sorted(self.graph[v]):
                if visited[i] == False:
                    queue.append(i)
                    visited[i] = True

n, m, v = map(int, input().rstrip().split())
g = Graph()
for i in range(m):
    a, b = map(int, input().rstrip().split())
    g.addEdge(a, b)
g.DFS(v)
print("")
g.BFS(v)
