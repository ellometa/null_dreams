import java.util.Scanner;

public class exp0104 {
    double radius;

    void setRadius(double r) {
        radius = r;
    }

    double area() {
        return Math.PI * radius * radius;
    }

    double circumference() {
        return 2 * Math.PI * radius;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        exp0104 c = new exp0104();

        System.out.print("Enter radius: ");
        double r = sc.nextDouble();
        c.setRadius(r);

        System.out.println("Area = " + c.area());
        System.out.println("Circumference = " + c.circumference());

        sc.close();
    }
}
