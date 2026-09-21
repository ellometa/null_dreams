// Two Classes
import java.util.Scanner;

class GCD{
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }
}

class exp0101 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        GCD g1 = new GCD();
        System.out.print("Enter x: ");
        int a = s.nextInt();
        System.out.print("Enter y: ");
        int b = s.nextInt();
        System.out.println("GCD is: " + g1.gcd(a, b));
        System.out.println("LCM is: " + g1.lcm(a, b));
        s.close();
    }
}
