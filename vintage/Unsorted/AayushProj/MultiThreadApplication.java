import java.util.Random;

public class MultiThreadApplication {


    static class Mailbox {
        volatile int evenSlot = 0;
        volatile int oddSlot  = 0;
    }


    static class RandomNumberGenerator extends Thread {
        private final Mailbox box;
        private final Random rnd = new Random();

        RandomNumberGenerator(Mailbox box) { this.box = box; }

        @Override public void run() {
            try {
                while (true) {
                    int n = rnd.nextInt(100) + 1; 
                    System.out.println(Thread.currentThread().getName() + " generated: " + n);

                    if ((n & 1) == 0) {
                        while (box.evenSlot != 0) { Thread.yield(); Thread.sleep(1); }
                        box.evenSlot = n;  
                    } else {
                        while (box.oddSlot != 0) { Thread.yield(); Thread.sleep(1); }
                        box.oddSlot = n;  
                    }

                    Thread.sleep(1000); 
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }

    static class SquareThread extends Thread {
        private final Mailbox box;
        SquareThread(Mailbox box) { this.box = box; }

        @Override public void run() {
            try {
                while (true) {
                    int v = box.evenSlot;   
                    if (v != 0) {
                        long sq = 1L * v * v;
                        System.out.println(getName() + " " + v + "^2 = " + sq);
                        box.evenSlot = 0;   
                    } else {
                        Thread.yield();
                        Thread.sleep(1);
                    }
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }

    static class CubeThread extends Thread {
        private final Mailbox box;
        CubeThread(Mailbox box) { this.box = box; }

        @Override public void run() {
            try {
                while (true) {
                    int v = box.oddSlot;    
                    if (v != 0) {
                        long cu = 1L * v * v * v;
                        System.out.println(getName() + " " + v + "^3 = " + cu);
                        box.oddSlot = 0;    
                    } else {
                        Thread.yield();
                        Thread.sleep(1);
                    }
                }
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Mailbox box = new Mailbox();

        Thread gen  = new RandomNumberGenerator(box);
        Thread sq   = new SquareThread(box);
        Thread cube = new CubeThread(box);

        gen.setName("rng");
        sq.setName("square");
        cube.setName("cube");

        gen.setPriority(6);   
        sq.setPriority(5);
        cube.setPriority(5);

        sq.start();
        cube.start();
        gen.start();

        Thread.sleep(3000);
        System.out.println("MAIN rng alive? " + gen.isAlive()
                            + ", square alive? " + sq.isAlive()
                            + ", cube alive? " + cube.isAlive());
    }
}
