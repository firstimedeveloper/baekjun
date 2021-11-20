from collections import deque
import sys
input = sys.stdin.readline

n_tc = int(input().rstrip())

for i in range(n_tc):
    prog = list(input().rstrip())
    n = int(input().rstrip())
    lst = []
    rev = 1
    if n == 0:
        temp = input().rstrip()
        lst = []
    else:
        temp = input().rstrip()
        lst = list(map(int, temp[1:-1].split(',')))
    try:
        for i in prog:
            if i == 'R':
                rev *= -1
            if i == 'D':
                if rev == 1:
                    lst.pop(0)
                else:
                    lst.pop()
    except:
        print("error")
        continue
    if rev == -1:
       lst.reverse()
    print('[', end='')
    for i in range(len(lst)):
        print(lst[i], end='')
        if i != len(lst) - 1:
            print(",", end='')
    i = 0
    print(']')

    


