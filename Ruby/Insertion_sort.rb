def insertion_sort(arr)
    0.upto(arr.length-1) do |i|
        j = i
        toInsert = arr[i]

        while j>0 && arr[j-1] > toInsert
            arr[j] = arr[j-1]
            j -= 1
        end

        arr[j] = toInsert
    end

    return arr
end


if __FILE__ == $0
    arr = 10.times.map { |x| (Random.rand() * 100).to_i + x }
    puts("Array is #{arr}")
    puts("Sorted Array is #{insertion_sort(arr)}")
end
