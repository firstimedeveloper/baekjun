def solution():
	n = int(input())
	A = list(map(int, input().split()))

	def possible(max):
		count = 1
		prev = A[0]
		for i in range(1,n):
			if A[i] > prev:
				count += 1
				prev = i
		return count > max


	left = 0
	right = n
	while left < right:
		mid = left + (right - left) // 2
		if possible(mid):
			right = mid
		else:
			left = mid + 1
	print(left)


solution()
