from random import randint


def is_sorted(arr):
    for x in range(len(arr)-1):
        if arr[x] > arr[x+1]:
            return False
    return True


def selection_sort(arr):
    minimum = 0
    length = len(arr)

    for i in range(length-1):
        minimum = i

        for j in range(i+1, length):
            if arr[minimum] > arr[j]:
                minimum = j

        arr[i], arr[minimum] = arr[minimum], arr[i]

    return arr


if __name__ == '__main__':
    arr = [randint(0, 100) for _ in range(10)]
    print(f'Array {arr}. Sorted? {is_sorted(arr)}')
    arr = selection_sort(arr)
    print(f'Array {arr}. Sorted? {is_sorted(arr)}')

