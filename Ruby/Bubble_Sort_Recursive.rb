def is_sorted?(arr)
    len = arr.length

    0.upto(len-2) do |x|
        if arr[x] > arr[x+1]
            return false
        end
    end

    return true
end


def bubble_sort(arr, len)
    if len <= 1
        return arr
    end

    0.upto(len -2 ) do |x|
        if arr[x] > arr[x+1]
            arr[x], arr[x+1] = arr[x+1], arr[x]
        end
    end

    arr = bubble_sort(arr, len-1)

    return arr
end


if __FILE__ == $0
    arr = 10.times.map { |x| (Random.rand() * 100).to_i + x }
    puts "Array #{arr}. Sorted? #{is_sorted?(arr)}"
    arr = bubble_sort(arr, arr.length)
    puts "Array #{arr}. Sorted? #{is_sorted?(arr)}"
end
