from collections import deque
import sys
input = sys.stdin.readline
# moves
# (x, y)
dx = [1, 2, 1, 2, -1, -2, -1, -2]
dy = [2, 1, -2, -1, 2, 1, -2, -1]

def find_dist(length, s, e):
	visited = [[0] * length for _ in range(length)]
	coord, _ = s
	x, y = coord
	visited[x][y] = 1
	if s == e:
		return 0
	queue = deque()
	queue.append(s)
	while queue:
		coord, count = queue.popleft()
		count += 1
		for i in range(8):
			new_coord = (coord[0] + dx[i], coord[1] + dy[i])
			x, y = new_coord
			if new_coord == e[0]:
				return count
			if 0 <= x < length and 0 <= y < length and not visited[x][y]:
				queue.append((new_coord, count))
				visited[x][y] = 1





num_scenarios = int(input())
for _ in range(num_scenarios):
	board_len = int(input())
	start = tuple(map(int, input().split()))
	end = tuple(map(int, input().split()))
	print(find_dist(board_len, (start,0), (end, 0)))

