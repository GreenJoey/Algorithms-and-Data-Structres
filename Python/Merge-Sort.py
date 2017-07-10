"""
Conceptually, a merge sort works as follows:

Divide the unsorted list into n sublists, each containing 1 element (a list of 1 element is considered sorted).

Repeatedly merge sublists to produce new sorted sublists until there is only 1 sublist remaining. This will be the sorted list.
"""


def merge(arr, low, high, mid):
    n1 = mid - low + 1
    n2 = high - mid

    left = [0]*n1  # Creating a array of size n1
    right = [0]*n2  # Creating another array of size n2

    for i in range(n1):
        left[i] = arr[low+i]
    for j in range(n2):
        right[j] = arr[mid+1+j]

    i = 0  # Initial index of first subarry
    j = 0  # Initial index of second subarray
    k = low  # Initial index of merged subarray

    while i < n1 and j < n2:
        if left[i] <= right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1

    # Copy the rest of the elements
    while i<n1:
        arr[k] = left[i]
        i += 1
        k += 1

    while j<n2:
        arr[k] = right[j]
        j += 1
        k += 1


def sort(arr, low, high):
    if low < high:
        mid = (high + low)//2

        # Sort the first half first
        sort(arr, low, mid)

        # Sort the last half now
        sort(arr, mid+1, high)

        merge(arr, low, high, mid)


if __name__ == '__main__':
    arr = [7, 5, 4, 3, 1, 6, 9, 2, 8]
    length = 9

    print(arr)
    sort(arr, 0, length-1)
    print(arr)

