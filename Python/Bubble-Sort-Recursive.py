from random import randint

def is_sorted(arr):
    length = len(arr)

    for x in range(length-1):
        if arr[x] > arr[x+1]:
            return False

    return True


def bubble_sort(arr, length):
    if length <= 1:
        return arr

    for x in range(len(arr)-1):
        if arr[x] > arr[x+1]:
            arr[x], arr[x+1] = arr[x+1], arr[x]

    arr = bubble_sort(arr, length-1)

    return arr


if __name__ == '__main__':
    arr = [randint(0, 100) for _ in range(10)]
    print(f'Array: {arr}. Sorted? {is_sorted(arr)}')
    arr = bubble_sort(arr, len(arr))
    print(f'Array: {arr}. Sorted? {is_sorted(arr)}')
