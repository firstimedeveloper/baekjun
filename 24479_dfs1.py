from collections import defaultdict

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


n, m, start = map(int, input().split())

graph = defaultdict(list)

for i in range(m):
	a, b = map(int, input().split())
	add_edge(graph, a, b)
dfs(graph, start)
