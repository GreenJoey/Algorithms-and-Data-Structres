def is_sorted?(arr)
    len = arr.length()

    0.upto(len-2) do |x|
        if arr[x] > arr[x+1]
            return false
        end
    end

    return true
end


def selection_sort(arr)
    len = arr.length

    0.upto(len-2) do |i|
        min = i
        (i+1).upto(len-1) do |j|
            if arr[min] > arr[j]
                min = j
            end
        end
        arr[i], arr[min] = arr[min], arr[i]
    end

    return arr
end


if __FILE__ == $0
    arr = 10.times.map { |x| (Random.rand() * 100).to_i + x }
    puts "Array #{arr}. Sorted? #{is_sorted?(arr)}"
    arr = selection_sort(arr)
    puts "Array #{arr}. Sorted? #{is_sorted?(arr)}"
end
