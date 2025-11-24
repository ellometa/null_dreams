public class exp0403 {
    public static void main(String[] args) {
        int[][][] jagged = new int[2][][];

        jagged[0] = new int[3][];
        jagged[0][0] = new int[4];
        jagged[0][1] = new int[3];
        jagged[0][2] = new int[2];

        jagged[1] = new int[2][];
        jagged[1][0] = new int[3];
        jagged[1][1] = new int[4];

        int value = 1;
        for (int i = 0; i < jagged.length; i++) {
            for (int j = 0; j < jagged[i].length; j++) {
                for (int k = 0; k < jagged[i][j].length; k++) {
                    jagged[i][j][k] = value++;
                }
            }
        }

        for (int i = 0; i < jagged.length; i++) {
            System.out.println("2D Array " + (i + 1) + ":");
            for (int j = 0; j < jagged[i].length; j++) {
                for (int k = 0; k < jagged[i][j].length; k++) {
                    System.out.print(jagged[i][j][k] + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }
}
