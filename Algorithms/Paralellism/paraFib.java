package Algorithms.Paralellism;

import java.util.Scanner;

class paraFib {

    public int input(int n) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter the number of terms: ");
        n = scanner.nextInt();
        scanner.close();
        return n;
    }

    public int fib(int n) {
        if (n < 2) return n;
        else {
            final int[] x = new int[1];
            final int[] y = new int[1];

            Thread t1 = new Thread(() -> {
                x[0] = fib(n - 1);
            });

            Thread t2 = new Thread(() -> {
                y[0] = fib(n - 2);
            });

            t1.start();   
            t2.start();

            try {
                t1.join();
                t2.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            return x[0] + y[0];
        }
    }

    public static void main(String[] args) {
        paraFib pf = new paraFib();
        int n = 0;
        n = pf.input(n);
        System.out.println("Calculating Fibonacci series for " + n + " terms...");
        for (int i = 0; i <=n; i++) {
            System.out.println(pf.fib(i));
        }
    }
}
