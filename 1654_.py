
def feasible(mid, n, arr):
	total = 0
	for i in arr:
		total += i // mid
	if total < n:
		return False
	# print(mid, total)
	return True

k, n = map(int, input().split(" "))
arr = [0] * k
for i in range(k):
	arr[i] = int(input())
# print(arr)

l = 1
r = max(arr)
while l <= r:
	mid = l + (r - l) // 2
	if feasible(mid, n, arr):
		l = mid + 1
	else:
		r = mid - 1

print(r)



