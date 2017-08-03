from random import randint

def insertion_sort(arr: list):
    for i in range(len(arr)):
        j = i

        toInsert = arr[i]

        while j>0 and arr[j-1] > toInsert:
            arr[j] = arr[j-1]
            j -= 1

        arr[j] = toInsert

    return arr


if __name__ == '__main__':
    arr = [randint(0, 100) for _ in range(10)]
    print("Initial array is {}".format(arr))
    print("Sorted array is {}".format(insertion_sort(arr)))

