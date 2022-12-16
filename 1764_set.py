import sys
input = sys.stdin.readline

n, m = map(int, input().rstrip().split())
a = set()
b = set()
for i in range(n):
    temp = input().rstrip()
    a.add(temp)

for i in range(m):
    temp = input().rstrip()
    b.add(temp)

res = a.intersection(b)
print(len(res))
for i in sorted(res):
    print(i)
