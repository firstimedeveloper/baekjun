import collections, queue

def solution(n, edges, start):
    graph = collections.defaultdict(list)
    for u, v, w in edges:
        graph[u].append((v, w))

    paths = dict()
    q = queue.PriorityQueue()
    q.put((0, start))
    while q:
        w, v = q.get()
        if v not in paths:
            paths[v] = w
            for vi, wi in graph[v]:
                q.put((w + wi, vi))
    return paths



V, E = map(int, input().split())
start = int(input())
edges = []
for _ in range(E):
    u, v, w = map(int, input().split())
    edges.append((u, v, w))
for i in edges:
    print(i)
paths = solution(V, edges, start)
print(paths)
