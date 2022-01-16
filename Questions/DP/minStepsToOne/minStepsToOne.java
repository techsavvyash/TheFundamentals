import java.util.Scanner;


public class minStepsToOne {
  private static int min(int a, int b) {
    return (a>b) ? b : a;
  }
  private static int minSteps(int n) {
    int dp[] = new int[n+1] ;

    for(int i =0 ; i<n; i++) {
      dp[i] = -1 ;
    }
    dp[1] = 0 ;

    for(int i = 2; i <= n;i++) {
      int op1 = (i%2 != 0) ? Integer.MAX_VALUE : dp[i/2] ;
      int op2 = (i%3 != 0) ? Integer.MAX_VALUE : dp[i/3] ;
      int op3 = dp[i-1] ;
      dp[i] = min(op1, min(op2, op3)) + 1 ;
    }

    return dp[n] ;

  }

  public static void main(String args[]) {
    Scanner inp = new Scanner(System.in) ;
    System.out.println("Enter the number: ") ;
    int n = inp.nextInt() ;
    System.out.println("Steps: " + minSteps(n)) ;
  }
}
