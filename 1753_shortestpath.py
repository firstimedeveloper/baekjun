from collections import defaultdict
import sys
input = sys.stdin.readline()

class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
        
    def addEdge(self, u, v, w):
        self.graph[u].append(v, w)

    def dijkstra(self, start):
        unvisited = set()


g = Graph()
v, e = map(int, input().rstrip().split())
start = int(input().rstip())

for i in range(e):
    u, v, w = map(int, input().rstrip().split())
    g.addEdge(u, v, w)
