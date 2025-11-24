import java.util.Scanner;

class Players {
    int[][] input(int n, Scanner sc) {
        int[][] players = new int[n][];
        for (int i = 0; i < n; i++) {
            System.out.print("enter number of matches for player " + (i + 1) + ": ");
            int m = sc.nextInt();
            players[i] = new int[m];
            System.out.println("enter runs for " + m + " matches:");
            for (int j = 0; j < m; j++) {
                players[i][j] = sc.nextInt();
            }
        }
        return players;
    }

    void display(int[][] players, int n) {
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int runs : players[i]) sum += runs;
            double avg = players[i].length == 0 ? 0.0 : (double) sum / players[i].length;
            System.out.println("player " + (i + 1) + ": total runs = " + sum + ", average = " + avg);
        }
    }
}

public class exp0401 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("enter number of players: ");
        int n = sc.nextInt();

        Players p = new Players();
        int[][] data = p.input(n, sc);
        p.display(data, n);

        sc.close();
    }
}
