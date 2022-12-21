start, end = map(int, input().split(" "))

ret = float("inf")

def recur(i, n):
	global ret
	global start
	global end
	if n == end:
		ret = min(ret, i + 1)
		return
	if n > end:
		return
	recur(i + 1, n * 2)
	recur(i + 1, 10 * n + 1)


recur(0, start)
if ret == float("inf"):
	ret = -1
print(ret)
