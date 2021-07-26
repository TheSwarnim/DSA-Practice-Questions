import java.io.*;
import java.util.*;

class Main {

	public static int solution(String s, String t, int si, int ti) {
	    int n = s.length(), m = t.length();
		int[][] dp = new int[m + 1][n + 1];
	    for(int i = m; i >= 0; i--){
	        for(int j = n; j >= 0; j--){
	            if(i == m){
	                dp[i][j] = 1;
	            } else if(j == n){
	                dp[i][j] = 0;
	            } else{
	                if(t.charAt(i) == s.charAt(j)){
	                    dp[i][j] = dp[i][j + 1] + dp[i + 1][j + 1];
	                } else{
	                    dp[i][j] = dp[i][j + 1];
	                }
	            }
	        }
	    }
	    
	    return dp[0][0];
	}
	
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String s1 = scn.next();
		String s2 = scn.next();
		
		System.out.println(solution(s1, s2, 0, 0));
	}

}