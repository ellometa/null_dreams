package myPackage;

public class myMath {
    public static double power(double x, int y) {
        double res = 1;
        for (int i = 0; i < y; i++) {
            res *= x;
        }
        return res;
    }

    public static double fact(int x) {
        double f = 1;
        for (int i = 1; i <= x; i++) {
            f *= i;
        }
        return f;
    }
}
