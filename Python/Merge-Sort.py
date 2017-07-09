"""
Conceptually, a merge sort works as follows:

Divide the unsorted list into n sublists, each containing 1 element (a list of 1 element is considered sorted).

Repeatedly merge sublists to produce new sorted sublists until there is only 1 sublist remaining. This will be the sorted list.
"""


def merge(arr, low, high, mid):
    pass


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

    sort(arr, 0, length)
    print(arr)

