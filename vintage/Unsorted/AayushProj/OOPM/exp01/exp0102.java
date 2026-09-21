// Non Static Method
import java.util.Scanner;

public class exp0102 {
    public int gcd(int a, int b){
        if (b == 0){
            return a;
        }
        return gcd(b, a % b);
    }

    public void calc() {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter x: ");
        int n1 = sc.nextInt();
        System.out.print("Enter y: ");
        int n2 = sc.nextInt();
        int gcdV = gcd(n1, n2);
        int lcm = (n1 * n2) / gcdV;

        System.out.println("GCD of " + n1 + " and " + n2 + " = " + gcdV);
        System.out.println("LCM of " + n1 + " and " + n2 + " = " + lcm);
        sc.close();
    }

    public static void main(String[] args){
        exp0102 g = new exp0102();
        g.calc();
    }
}
