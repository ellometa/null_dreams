def merge(arr, left, pivot, right):
    n1 = pivot - left + 1
    n2 = right - pivot

    L = [0] * n1
    R = [0] * n2

    for i in range(0, n1):
        L[i] = arr[left + i]

    for j in range(0, n2):
        R[j] = arr[pivot + 1 + j]

    i = 0
    j = 0
    k = left

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i = i + 1
        else:
            arr[k] = R[j]
            j = j + 1
        k = k + 1

    while i < n1:
        arr[k] = L[i]
        i = i + 1
        k = k + 1

    while j < n2:
        arr[k] = R[j]
        j = j + 1
        k = k + 1
    for x in arr:
        print(x, end=" ")
    print("pivot", arr[pivot])
    print()

def sort(arr, left, right):
    if left < right:
        pivot = (left + right) // 2

        sort(arr, left, pivot)
        sort(arr, pivot + 1, right)

        merge(arr, left, pivot, right)

if __name__ == "__main__":
    my_numbers = [12, 11, 13, 5, 6, 7]
    
    print("before sorting:")
    for x in my_numbers:
        print(x, end=" ")
    print()

    sort(my_numbers, 0, len(my_numbers) - 1)

    print("after sorting:")
    for x in my_numbers:
        print(x, end=" ")
    print()
