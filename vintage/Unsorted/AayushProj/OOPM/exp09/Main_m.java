import myPackage.myMath;
import java.util.Scanner;

public class Main_m {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of terms: ");
        int n = sc.nextInt();

        System.out.print("Enter the value to be found: ");
        double x = sc.nextDouble();

        double ans = 0;
        int sign = 1;

        for (int i = 0; i < n; i++) {
            int power = 2 * i;
            ans += sign * (myMath.power(x, power) / myMath.fact(power));
            sign *= -1;
        }

        System.out.println("cos(" + x + ") = " + ans);
        sc.close();
    }
}
