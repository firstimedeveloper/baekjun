import collections, queue, sys
input = sys.stdin.readline

def solution(E, start):
    graph = collections.defaultdict(list)
    for _ in range(E):
        u, v, w = map(int, input().split())
        graph[u].append((v, w))

    paths = dict()
    q = queue.PriorityQueue()
    q.put((0, start))
    while not q.empty():
        w, v = q.get()
        if v not in paths:
            paths[v] = w
            for vi, wi in graph[v]:
                q.put((w + wi, vi))
    return paths



V, E = map(int, input().split())
start = int(input())
paths = solution(E, start)
for i in range(1, V+1):
    if i in paths:
        print(paths[i])
    else:
        print("INF")
