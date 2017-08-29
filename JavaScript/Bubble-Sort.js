function bubble_sort(arr) {
    for(var j=arr.length; j>=0; --j) {
        for(var i=0; i<j; ++i) {
            if(arr[i] > arr[i+1]) {
                var tmp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = tmp;
            }
        }
    }

    return arr;
}


var arr = [6, 4, 2, 1, 3, 5];
console.log(arr);
arr = bubble_sort(arr);
console.log(arr)
