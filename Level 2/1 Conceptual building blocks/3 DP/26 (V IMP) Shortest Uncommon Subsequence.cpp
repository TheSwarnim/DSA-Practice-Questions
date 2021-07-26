import java.io.*;
import java.util.*;

public class Main {

    static int max = (int)1e3 + 5;
	public static int solution(String s1, String s2) {
		

		int res =  shortestSeq(s1.toCharArray(), s2.toCharArray(), s1.length(), s2.length());
		return res < max ? res : -1;
	}
	
	private static int shortestSeq(char[] s, char[] t, int m, int n){
        if(m == 0){
            return max;
        }
        
        if(n <= 0){
            return 1;
        }
        
        int k;
        for(k = 0; k < n; k++){
            if(s[0] == t[k]) break;
        }
        
        if(k == n){
            return 1;
        }
        
        return Math.min(shortestSeq(Arrays.copyOfRange(s, 1, s.length), t, m - 1, n), 1 + shortestSeq(Arrays.copyOfRange(s, 1, s.length), Arrays.copyOfRange(t, k + 1, t.length), m - 1, n - k - 1));
	}
	
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String s1 = scn.next();
		String s2 = scn.next();
		System.out.println(solution(s1, s2));
	}

}