import sys
input = sys.stdin.readline
n, c = map(int, input().split())
houses = [int(input()) for _ in range(n)]
houses.sort()

def possible(threshold):
	prev_house = houses[0]
	count = 1
	for i in range(len(houses)):
		if prev_house + threshold <= houses[i]:
			count += 1
			prev_house = houses[i]
	if count >= c:
		return False
	else:
		return True
left = 1
right = houses[-1] - houses[0]
if c == 2:
	print(right)
else:
	while left < right:
		mid = left + (right - left) // 2
		if possible(mid):
			right = mid
		else:
			left = mid + 1
	print(left - 1)

