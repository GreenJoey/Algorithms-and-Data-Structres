import java.util.Scanner;
import java.util.Arrays;


class MergeSort {
    private static int[] merge(int[] arr, int start, int mid, int end) {
        int j = start;
        int i = mid + 1;
        int tmp;

        while (i <= mid && j <= end) {
        }
    }

    private static int[] sort(int[] arr, int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            arr = sort(arr, start, mid);
            arr = sort(arr, mid+1, end);
            arr = merge(arr, start, mid, end);
        }
        return arr;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int length = sc.nextInt();
        int[] arr = new int[length];
        
        for(int pos=0; pos < length; ++pos)
            arr[pos] = sc.nextInt();

        System.out.println(Arrays.toString(arr));

        arr = sort(arr, 0, length-1);

        System.out.println(Arrays.toString(arr));
    }
}
