import java.util.Scanner;


class Factorial {
    private static long[] memory;

    private static long factorial(long n) {
    	if (memory[(int)n-1] == 0)
    		memory[(int)n-1] = n * factorial(n-1);

    	return memory[(int)n-1];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter n: ");
        long n = sc.nextLong();
        memory = new long[100];
        memory[0] = 1;

        long startTime = System.nanoTime();
        System.out.println(factorial(n-1));
        long elpasedTime = System.nanoTime() - startTime;
        System.out.println("Factorial of " + (n-1) + " calculated in " + elpasedTime + " nanoseconds with no table");

        startTime = System.nanoTime();
        System.out.println(factorial(n+1));
        elpasedTime = System.nanoTime() - startTime;
        System.out.println("Factorial of " + (n+1) + " calculated in " + elpasedTime + " nanoseconds using memorization table");
    }
}
