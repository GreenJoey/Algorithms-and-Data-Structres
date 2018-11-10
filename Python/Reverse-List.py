import random


def reverse(arr, length):
    # A exhaustive method of reversing the entire array using
    # only O(1) space and O(n) time complexity, although
    # it needs to traverse only half the length of array

    last = length - 1  # Index of the last element

    # Traverse only half the half the entire array
    for pos in range(length // 2) :
        # The position with which we need to swap the current position
        # can easily calculated by subtracting the current index 
        # from the possible last index of the array
        arr[pos], arr[last - pos] = arr[last - pos], arr[pos]

    return arr


if __name__ == '__main__':
    try:
        while True:
            length = random.randint(0, 5)
            arr = [random.randint(0, 100) for _ in range(length)]
            print(f"Original array {arr}")
            print(f"Reversed array {reverse(arr, length)}")
    except KeyboardInterrupt:
        pass

