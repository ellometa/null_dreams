package myPack;
    
public class Trigonometry {
    private static double radians(double x) { return (x * 3.1415) / 180.0; }
    private static double power(double x, int y) {
        double res = 1;
        for (int i = 0; i < y; i++) res *= x;
        return res;
    }
    private static double fact(int x) {
        double f = 1;
        for (int i = 1; i <= x; i++) f *= i;
        return f;
    }
    private static double abs(double v) { return v < 0 ? -v : v; }

    public static double sine(double degree) {
        double rad = radians(degree), ans = 0; int sign = 1;
        for (int i = 0; i < 15; i++) {
            int p = 2 * i + 1;
            ans += sign * (power(rad, p) / fact(p));
            sign *= -1;
        }
        return ans;
    }

    public static double cos(double degree) {
        double rad = radians(degree), ans = 0; int sign = 1;
        for (int i = 0; i < 15; i++) {
            int p = 2 * i;
            ans += sign * (power(rad, p) / fact(p));
            sign *= -1;
        }
        return ans;
    }

    public static double tan(double degree) {
        double c = cos(degree);
        double s = sine(degree);
        if (abs(c) < 1e-9) throw new ArithmeticException("tan undefined at " + degree);
        return s / c;
        }

    public static double cot(double degree) {
        double s = sine(degree);
        double c = cos(degree);
        if (abs(s) < 1e-9) throw new ArithmeticException("cot undefined at " + degree);
        return c / s;
    }

    public static double sec(double degree) {
        double c = cos(degree);
        if (abs(c) < 1e-9) throw new ArithmeticException("sec undefined at " + degree);
        return 1.0 / c;
    }

    public static double cosec(double degree) {
        double s = sine(degree);
        if (abs(s) < 1e-9) throw new ArithmeticException("cosec undefined at " + degree);
        return 1.0 / s;
    }
}
