def merge(arr, left, right, mid)
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
    length = 9

    $stdout.puts(arr.join(", "))
    sort(arr, 0, length-1)
    $stdout.puts(arr.join(", "))
end
