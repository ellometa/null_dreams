import java.util.Scanner;

public class exp0202{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a: ");
        int a = sc.nextInt();
        System.out.print("Enter b: ");
        int b = sc.nextInt();
        System.out.print("Enter c: ");
        int c = sc.nextInt();

        int l;
        if (a >= b && a >= c) l= a;
        else if (b >= a && b >= c) l= b;
        else l= c;
        System.out.println("Largest: " + l);
        sc.close();
    }
}
