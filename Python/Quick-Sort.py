from random import randint


def partition(arr, low, high):

    # pivot (Element to be placed at right position)
    pivot = arr[high]

    i = (low - 1)  # Index of small element

    for j in range(low, high):
        # If current element is smaller than
        # or equal to pivot
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i+1], arr[high] = arr[high], arr[i+1]
    print(arr)
    return i+1


def sort(arr, low, high):
    if low < high:
        # pi is partitioning index, arr[p] is now
        # at right place
        pi = partition(arr, low, high)
        sort(arr, low, pi-1)
        sort(arr, pi+1, high)


def main():
    arr = [5, 8, 1, 3, 7, 9, 2]  # [randint(0, 100) for _ in range(10)]
    length = 7  # 10
    print(arr)
    sort(arr, 0, length-1)
    print(arr)


if __name__ == '__main__':
    main()
