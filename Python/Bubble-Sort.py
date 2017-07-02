from random import randint


def is_sorted(arr):
    for x in range(len(arr)-2):
        if arr[x] > arr[x+1]:
            return False

    return True


def bubble_sort(arr):
    done = False
    length = len(arr)

    while not done:
        done = True
        for x in range(length-1):
            if arr[x] > arr[x+1]:
                arr[x], arr[x+1] = arr[x+1], arr[x]
                done = False

    return arr


if __name__ == '__main__':
    arr = [randint(1, 100) for _ in range(10)]
    print(f"Array: {arr}. Sorted: {is_sorted(arr)}")
    arr = bubble_sort(arr)
    print(f"Array: {arr}. Sorted: {is_sorted(arr)}")
