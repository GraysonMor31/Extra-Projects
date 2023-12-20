package Algorithms.Paralellism;

public class paraHanoi {
    public void hanoi(int n, char from, char to, char aux) {
        if (n == 1) {
            System.out.println("Move disk 1 from rod " + from + " to rod " + to);
            return;
        } else {

            final int[] x = new int[1];

            Thread t1 = new Thread(() -> {
                hanoi(n - 1, from, aux, to);
            });

            Thread t2 = new Thread(() -> {
                x[0] = n;
            });

            Thread t3 = new Thread(() -> {
                hanoi(n - 1, aux, to, from);
            });

            t1.start();
            t2.start();
            t3.start();

            try {
                t1.join();
                t2.join();
                t3.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            System.out.println("Move disk " + n + " from rod " + from + " to rod " + to);
        }
    }

    public static void main(String[] args) {
        paraHanoi ph = new paraHanoi();
        int n = 4;
        ph.hanoi(n, 'A', 'C', 'B');
    }
}
