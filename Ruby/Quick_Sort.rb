def partition(arr, low, high)
    pivot = arr[high]
    i = low-1

    low.upto(high-1) do |j|
        if arr[j] <= pivot
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
        end
    end

    arr[i+1], arr[high] = arr[high], arr[i+1]
    return i+1
end


def sort(arr, low, high)
    if low < high
        pi = partition(arr, low, high)

        sort(arr, low, pi-1)
        sort(arr, pi+1, high)
    end
end


def main()
    arr = 10.times.map { |x| (Random.rand()*10).to_i + x }
    len = 10

    puts arr.join(" ")
    sort(arr, 0, len-1)
    puts arr.join(" ")
end


if __FILE__ == $0
    main()
end
