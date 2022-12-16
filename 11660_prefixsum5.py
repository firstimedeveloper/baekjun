import sys
input = sys.stdin.readline

n, m = map(int, input().split())

arr = []
for _ in range(n):
    arr.append(list(map(int, input().split())))
print(arr)

arr_prefix = [[0] * m for _ in range(m)]
print(arr_prefix)
for i in range(m):
    for j in range(m):
        pass


