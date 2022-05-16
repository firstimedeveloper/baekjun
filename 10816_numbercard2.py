import sys
def solution():
    n = int(sys.stdin.readline().rstrip())
    cards = list(map(int, sys.stdin.readline().rstrip().split()))
    cards.sort()
    m = int(sys.stdin.readline().rstrip())
    nums = list(map(int, sys.stdin.readline().rstrip().split()))

    def binary_search(val):
        left = 0
        right = n
        while left < right:
            mid = left + (right - left) // 2
            if cards[mid] == val:
                return mid
            if val < cards[mid]:
                right = mid
            else:
                left = mid + 1
        return None

    def bs_first(val, middle):
        left = 0
        right = middle + 1
        while left < right:
            mid = left + (right - left) // 2
            if val == cards[mid]:
                if (mid == 0 or cards[mid-1] < val):
                    return mid
                else:
                    right = mid
            else:
                left = mid + 1
        return middle

    def bs_last(val, middle):
        left = middle
        right = n
        while left < right:
            mid = left + (right - left) // 2
            if val == cards[mid]:
                if (mid == n-1 or cards[mid+1] > val):
                    return mid
                left = mid + 1
            else:
                right = mid
        return middle

    for i in nums:
        bs = binary_search(i)
        if bs == None:
            print(0, end=" ")
        else:
            first = bs_first(i, bs)
            last = bs_last(i, bs)
            answer = last - first + 1
            print(answer, end=" ")

solution()
