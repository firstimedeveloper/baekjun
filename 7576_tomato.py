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
        temp = tuple(map(lambda x, y: x + y, i, pos))
        if is_valid(box, temp, m, n):
            neighbors.append(temp)
    return neighbors

m, n = map(int, input().rstrip().split())
print(m, n)
print(type(m))

box = []
for i in range(n):
    box.append(map(int, input().rstrip().split()))

print(box)
print(get_neighbors(box, (5, 3), m, n))
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
            exit(0)
print(days-1)
