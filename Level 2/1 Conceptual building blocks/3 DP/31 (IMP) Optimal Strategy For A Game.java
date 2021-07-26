import java.io.*;
import java.util.*;

class Main {

	public static void optimalStrategy(int[] A) {
		int n = A.length;
		int[][] dp = new int[n][n];
		
		for(int g = 0; g < n; g++){
		    for(int i = 0, j = g; j < n; i++, j++){
		        if(g == 0){
		            dp[i][j] = A[i];
		        } else if(g == 1){
		            dp[i][j] = Math.max(A[i], A[j]);
		        } else{
		            dp[i][j] = Math.max(A[i] + Math.min(dp[i + 1][j - 1], dp[i + 2][j]), A[j] + Math.min(dp[i][j - 2], dp[i + 1][j - 1]));
		        }
		    }
		}
		
		System.out.println(dp[0][n - 1]);
	}
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int a[] = new int[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = scn.nextInt();
		}
		optimalStrategy(a);
	}

}