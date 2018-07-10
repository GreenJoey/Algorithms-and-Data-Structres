import java.util.Scanner;


class Test {
  private static int[] arr;
  private static int n;


  private static void rotate(int d) {
    int[] rem = new int[d];

    for (int pos=0; pos < d; ++pos)
      rem[pos] = arr[pos];

    for (int pos=d; pos < n; ++pos)
      arr[pos - d] = arr[pos];

    int i = 0;
    for (int pos = n - d; pos < n; ++pos)
      arr[pos] = rem[i++];
  }

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int length = sc.nextInt();

    arr = new int[length];
    n = length;

    for (int pos=0; pos < length; ++pos)
      arr[pos] = sc.nextInt();

    rotate(2);

    for (int v: arr)
      System.out.print(v + " ");

    System.out.println("");
  }
}
