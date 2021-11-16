import sys
input = sys.stdin.readline

min = 500001
n_str = input().rstrip()
n = int(n_str) # channel to go to
n_len = len(n_str)
m = int(input().rstrip()) # no of broken buttons
broken = list(map(int, input().rstrip().split()))
print(broken)
current = 100



