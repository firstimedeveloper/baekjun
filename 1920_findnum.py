def solution():
    def partition(arr, left, right):
        pivot = arr[right]
        i = left - 1
        for j in range(left, right):
            if arr[j] <= pivot:
                i += 1
                arr[i], arr[j] = arr[j], arr[i]
            j += 1
        arr[i+1], arr[right] = arr[right], arr[i+1]
        return i + 1
        
    def qsort(arr, left, right):
        if left < right:
            pivot = partition(arr, left, right)
            qsort(arr, left, pivot - 1)
            qsort(arr, pivot + 1, right)




    n = int(input())
    a = list(map(int, input().split()))
    qsort(a, 0, n - 1)
    m = int(input())
    find = list(map(int, input().split()))
    def binary_search(val):
        left = 0
        right = n
        while left < right:
            mid = left + (right - left) // 2
            if val == a[mid]:
                return True
            if val < a[mid]:
                right = mid
            else:
                left = mid + 1
        return False

    for i in find:
        if (binary_search(i)):
            print("1")
        else:
            print("0")
            
solution()






