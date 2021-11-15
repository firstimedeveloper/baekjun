import sys
input = sys.stdin.readline
lst = []
col = {}

total, n = map(int, input().split())
for i in range(total):
    temp = input().rstrip()
    lst.append(temp)
    col[temp] = i + 1

for _ in range(n):
    temp = input().rstrip()
    if temp.isdigit():
        print(lst[int(temp)-1])
    else:
        print(col[temp])

