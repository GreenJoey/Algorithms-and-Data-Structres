def is_sorted?(arr)
    len = arr.length

    0.upto(len-2) do |x|
        if arr[x] > arr[x+1]
            return false
        end
    end

    return true
end


def bubble_sort(arr)
    len = arr.length
    done = false

    while !done
        done = true
        0.upto(len-2) do |x|
            if arr[x] > arr[x+1]
                arr[x], arr[x+1] = arr[x+1], arr[x]
                done = false
            end
        end
        len -= 1
    end

    return arr
end


if __FILE__ == $0
    arr = 10.times.map { |x| (Random.rand() * 100).to_i + x }
    puts "Array #{arr}. Sorted? #{is_sorted?(arr)}"
    arr = bubble_sort(arr)
    puts "Array #{arr}. Sorted? #{is_sorted?(arr)}"
end
