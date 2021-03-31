import java.io.*;
import java.util.*;

public class Main {
  public static int powerOf2(int n){
    int i = 1;
    
    while(i * 2 <= n){
        i *= 2;
    }

    return i;
  }

  public static int solution(int n){
    int hp2 = powerOf2(n);
    int l = n - hp2;

    return 2 * l + 1;
  }
  
  public static void main(String[] args){
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    System.out.println(solution(n));

    scn.close();
  }
}