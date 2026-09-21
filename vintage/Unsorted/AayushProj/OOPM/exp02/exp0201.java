// import java.util.*;
class exp0201 {

    public static void main(String[] args) {
        for (int i = 1; i <= 1000; i++) {
        if (isk(i)) {
            System.out.println(i);
        }
        }
    }

    public static boolean isk(int n){
        if (n==1) return true;
        int sq = n*n;
        int d = c(n);
        int div =(int) Math.pow(10, d);
        int left =sq/div;
        int right =sq%div;
        return (right !=0) && (left +right ==n);
    }

    public static int c(int n){
        int count =0;
        while (n>0){
        n /=10;
        count++;
        }
        return count;
    }
}
