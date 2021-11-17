from collections import deque
import sys
input = sys.stdin.readline

def is_valid(box, pos, m, n):
    x, y = pos
    if x >= m or x < 0 or y >= n or y < 0:
        return False
    if box[y][x] == -1:
        return False
    return True

def get_neighbors(box, pos, m, n):
    neighbors = []
    offset = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    for i in offset:
        #temp = tuple(map(lambda x, y: x + y, i, pos))
        dx, dy = i
        x, y = pos
        temp = (x + dx, y + dy)
        if is_valid(box, temp, m, n):
            neighbors.append(temp)
    return neighbors

m, n = map(int, input().rstrip().split())

#box = []
#for i in range(n):
#    box.append(map(int, input().rstrip().split()))
box = [list(map(int, input().rstrip().split())) for _ in range(n)]

"""
changed = True
days = 0
while (changed):
    changed = False
    visited = set()
    print("Day:", days)
    for i in range(n):
        for j in range(m):
            if (j, i) in visited:
                continue
            if box[i][j] == 1:
                neigh = get_neighbors(box, (j, i), m, n)
                for val in neigh:
                    x, y = val
                    if box[y][x] == 1:
                        continue
                    if val not in visited:
                        box[y][x] += 1
                        visited.add(val)
                        changed = True
    for i in range(n):
        print(box[i])
    print("")
    days += 1

for i in range(n):
    for j in range(m):
        if box[i][j] == 0:
            print(-1)
            sys.exit(0)
print(days-1)
"""

days = 0

queue = deque(())
for i in range(n):
    for j in range(m):
        if box[i][j] == 1:
            queue.append((i, j))

print(box)
print(queue)

offset = [(1, 0), (-1, 0), (0, 1), (0, -1)]
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
while queue:
    pos = queue.popleft()
    x, y = pos
    for i in range(4):
        nx, ny = dx[i] + x, dy[i] + y
        if 0 <= nx < n and 0 <= ny < m and box[nx][ny] == 0:
            box[nx][ny] = box[x][y] + 1
            queue.append((nx,ny))
print(box)

for i in range(n):
    for j in range(m):
        if box[i][j] == 0:
            print(-1)
            sys.exit(0)
    days = max(days, max(box[i]))

print(days - 1)
        

