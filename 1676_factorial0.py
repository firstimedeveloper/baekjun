import sys
input = sys.stdin.readline

def factorial(n):
    total = 1
    for i in range(1, n+1):
        total *= i

    return total

def find_zero(str):
    count = 0
    for c in reversed(str):
        if c != '0':
            break
        count += 1
    return count


total = 1
n = int(input().rstrip())
print(find_zero(str(factorial(n))))


