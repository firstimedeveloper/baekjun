from collections import deque
import sys

input = sys.stdin.readline
m, n, h = map(int, input().rstrip().split())
board = [[[int(x) for x in input().rstrip().split()] for _ in range(n)] for _ in range(h)]
queue = deque(())
dx = [1, -1, 0, 0, 0, 0]
dy = [0, 0, 1, -1, 0, 0]
dz = [0, 0, 0, 0, 1, -1]
for i in range(h):
    for j in range(n):
        for k in range(m):
            if board[i][j][k] == 1:
                queue.append((i, j, k))
res = 0
while queue:
    x, y, z = queue.popleft()
    for i in range(6):
        nx, ny, nz = x + dx[i], y + dy[i], z + dz[i]
        if 0 <= nx < h and 0 <= ny < n and 0 <= nz < m and board[nx][ny][nz] == 0:
            board[nx][ny][nz] = board[x][y][z] + 1
            queue.append((nx, ny, nz))

for i in board:
    for j in i:
        for k in j:
            if k == 0:
                print(-1)
                sys.exit(0)
        res = max(res, max(j))
print(res - 1)
