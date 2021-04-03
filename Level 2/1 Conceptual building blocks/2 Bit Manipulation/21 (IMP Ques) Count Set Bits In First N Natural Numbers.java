import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args){
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    System.out.println(solution(n));

	scn.close();
  }

  public static int solution(int n){
	if(n == 0){
		return 0;
	}
	  
	int x =  (int) (Math.log(n)/Math.log(2));

	int b2x = x * (1 << (x - 1));
	int msb2xton = n - (1 << x) + 1;
	int res = n - (1 << x);
	int ans = b2x + msb2xton + solution(res);
	return ans;
  }
}