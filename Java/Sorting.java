import java.util.Arrays;


class Sorting {
    /**
     * Bubble Sort algorithm to sort an array
     * int[] arr: An array of integers
     */
    public void bubbleSort(int[] arr) {
        // Flag to check if any swaps in the arrays has been made.
        // If no swaps are made then the array is sorted and iterations are no more needed
        boolean swapped = true;
        int temp;

        System.out.println(Arrays.toString(arr));

        // Loop until swaps are made, i.e., loop until the array is not completely sorted
        while (swapped) {
            swapped = false;

            // Iterate over the array and find element pairs which are out of order
            for (int i=0; i < arr.length - 1; ++i) {
                // When such a pair has been found, swap them to bring them in order
                if (arr[i] > arr[i+1]) {
                    swapped = true;

                    temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                }
            }

            System.out.println(Arrays.toString(arr));
        }

        System.out.println(Arrays.toString(arr));
    }

    /**
     * Selection Sort algorithm to sort an array
     * int[] arr: An array of integers
     */
    public void selectionSort(int[] arr) {
        int key;
        int temp;

        System.out.println(Arrays.toString(arr));

        // Iterate over the array and select an key position.
        // Here we will place the smallest element in the unsorted of the array
        for (int pos=0; pos < arr.length; ++pos) {
            key = pos;

            // Iterate over the unsorted portion of the array to find the smallest element
            for (int j=pos; j < arr.length; ++j) {

                // If a smaller element is found, then note it place
                if (arr[j] < arr[key])
                    key = j;
            }

            // Swap the smaller element from the `key` position to the current `pos` position
            temp = arr[key];
            arr[key] = arr[pos];
            arr[pos] = temp;

            System.out.println(Arrays.toString(arr));
        }

        System.out.println(Arrays.toString(arr));
    }
    
    /**
     * Insertion Sort algorithm to sort an array
     * int[] arr: An array of integers
    **/
    public void insertionSort(int[] arr) {
        int toInsert;
        int temp;
        int j;

        System.out.println(Arrays.toString(arr));

        // Iterate over the array and select an element to sort it in it right place
        for (int i=1; i < arr.length; ++i) {
            toInsert = arr[i];

            // Start from current position and go back to the beginning of the array
            // until the selected element is greater than the elements.
            // Basically move the larger elements to the right of the selected element
            for (j=i; j > 0 && arr[j-1] > toInsert;) {
                arr[j] = arr[j-1];
                --j;
            }

            // Insert the selected element here.
            // The elements to the left of it are smaller than it and is sorted.
            // The elements to the right of it are larger than it and is probably unsorted
            arr[j] = toInsert;

            System.out.println(Arrays.toString(arr));
        }

        System.out.println(Arrays.toString(arr));
    }
    
    /**
     * This function takes last element as pivot,
     * places the pivot element in the correct at its correct
     * position in sorted array, and places all
     * smaller to left of pivot and all greater elements
     * to right of pivot
     **/
     
    private int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int pos = low - 1;  // index of smaller element
        int temp;

        for (int i=low; i < high; ++i) {
        
            // If current element is smaller than or
            // equal to pivot
            if (arr[i] <= pivot) {
            
                // swap arr[i] and arr[j]
                temp = arr[++pos];
                arr[pos] = arr[i];
                arr[i] = temp;
            }
        }
        
        // swap arr[i+1] and arr[high] or pivot
        temp = arr[++pos];
        arr[pos] = arr[high];
        arr[high] = temp;

        return pos;
    }
    
    /**
     * The main function that implements QuickSort
     * arr[] = Array to be sorted
     * low   = Starting index
     * high  = Ending index
     **/
     
    public void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            // pi is partitioning index, arr[pi] is
            // now at right place
            int part = partition(arr, low, high);

            System.out.println(Arrays.toString(arr));

            // Recursively sort elements before
            // partition and after partition
            quickSort(arr, low, part-1);
            quickSort(arr, part+1, high);
        }
    }

    public static void main(String[] args) {
        Sorting ob = new Sorting();

        int[] arr = {25, 57, 48, 37, 12, 92, 86, 33};
        
        System.out.println("---------------------------------------------------- Bubble Sort ----------------------------------------------------------------------------------\n");
        ob.bubbleSort(arr.clone());

        System.out.println("---------------------------------------------------- Selection Sort -------------------------------------------------------------------------------\n");
        ob.selectionSort(arr.clone());

        System.out.println("---------------------------------------------------- Insertion Sort --------------------------------------------------------------------------------\n");
        ob.insertionSort(arr.clone());

        System.out.println("---------------------------------------------------- Quick Sort ------------------------------------------------------------------------------------\n");
        System.out.println(Arrays.toString(arr));
        ob.quickSort(arr.clone(), 0, arr.length-1); 
    }
}
