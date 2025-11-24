import java.util.Scanner;

public class exp0402 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int[] arr = new int[n];
        System.out.println("Enter elements of array:");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int sum = arr[0];
        int temp = arr[0];
        for (int i = 1; i < n; i++) {
            temp = Math.max(temp + arr[i], arr[i]);
            sum = Math.max(sum, temp);
        }

        System.out.println("Maximum contiguous subarray sum: " + sum);
        sc.close();
    }
}
