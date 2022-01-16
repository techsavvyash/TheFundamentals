import java.util.Scanner;

public class fibonacci {
    private static int[] dp = new int[100000];
    public static int fiboTopDown(int n) {
        if(n == 0 || n == 1) {
            return dp[n] = n ;
        }

        if(dp[n] != -1) {
            return dp[n] ;
        }

        return dp[n] = fiboTopDown(n-1) + fiboTopDown(n-2) ;
    }

    public static int fiboBtmUp(int n) {
        if(n == 0 || n == 1) {
            return n ;
        }

        int a = 0, b = 1, c = a + b ;

        for(int i = 2;i <= n; i++) {
            c = (a+b) ;
            a = b ; b = c ;
        }

        return c ;
    }
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        int n = inp.nextInt() ;
        for(int i = 0; i < n; i++) {
            dp[i] = -1 ;
        }

        System.out.println("Bottom Up: " + fiboBtmUp(n));
        System.out.println("Top Down: " + fiboTopDown(n)) ;
    }
}