import myPack.Trigonometry;
import java.util.Scanner;

public class Main_m {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter angle in degrees (0, 30, 60, 90): ");
        double val = sc.nextDouble();

        System.out.println("sin(" + val + ") = " + Trigonometry.sine(val));
        System.out.println("cos(" + val + ") = " + Trigonometry.cos(val));
        
        try {
            System.out.println("tan(" + val + ") = " + Trigonometry.tan(val));
        } catch (ArithmeticException e) {
            System.out.println("tan(" + val + ") = undefined");
        }
        
        try {
            System.out.println("cot(" + val + ") = " + Trigonometry.cot(val));
        } catch (ArithmeticException e) {
            System.out.println("cot(" + val + ") = undefined");
        }
        
        try {
            System.out.println("sec(" + val + ") = " + Trigonometry.sec(val));
        } catch (ArithmeticException e) {
            System.out.println("sec(" + val + ") = undefined");
        }
        
        try {
            System.out.println("cosec(" + val + ") = " + Trigonometry.cosec(val));
        } catch (ArithmeticException e) {
            System.out.println("cosec(" + val + ") = undefined");
        }
        sc.close();
    }
}


