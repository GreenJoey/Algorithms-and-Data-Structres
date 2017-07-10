def merge(arr, low, high, mid)
    # n1 is the right side of array
    n1 = mid - low + 1
    # n2 is the left side of array
    n2 = high - mid

    # Temporary arrays
    left = [0]*n1
    right = [0]*n2

    0.upto(n1-1) do |i|
        left[i] = arr[low+i]
    end

    0.upto(n2-1) do |j|
        right[j] = arr[mid+1+j]
    end

    i = 0  # Starting index of the left array
    j = 0  # Starting index of the right array
    k = low  # Current pointer for the merged array

    # While both the index pointers in left and right sub-array
    while i<n1 && j<n2
        # If the current element in the left array or right array
        if left[i] <= right[j]
            arr[k] = left[i]
            # Increment the position index of the left array
            i += 1
        else
            arr[k] = right[j]
            # Increment the position index of the right array
            j += 1
        end
        k += 1  # Increment the index pointer in the merged array
    end

    # Copy any remaining portions of the temporary arrays.
    # This portion is already sorted.
    while i<n1
        arr[k] = left[i]
        i += 1
        k += 1
    end

    while j<n2
        arr[k] = right[j]
        j += 1
        k += 1
    end
end


def sort(arr, left, right)
    if left < right
        # Get the middle index
        mid = (left+right)/2

        # Sort the left side of the array
        sort(arr, left, mid)
        # Sort the right side of the array
        sort(arr, mid+1, right)

        # Merge the current array using the midddle index
        merge(arr, left, right, mid)
    end
end


if __FILE__ == $0
    arr = [7, 5, 4, 3, 1, 6, 9, 2, 8]
    length = arr.length

    $stdout.puts("[#{arr.join(", ")}]")
    sort(arr, 0, length-1)
    $stdout.puts("[#{arr.join(", ")}]")
end
