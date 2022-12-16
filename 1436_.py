n = int(input())

num = 666
i = 0
while i < n:
	if '666' in str(num):
		i += 1
		if i == n:
			print(num)
			break
	num += 1
