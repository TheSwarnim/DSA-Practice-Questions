import java.io.*;
import java.util.*;

class Main {

  public static long solution(int[] arr, int k, long sum) {
    int n = arr.length;
    
    int max = Integer.MIN_VALUE, curr = 0;
    for(int idx= 0; idx < 2 * n; idx++){
        int i = idx % n;
        curr += arr[i];
        max = Math.max(max, curr);
        
        if(k == 1 && i == n - 1){
            return max;
        }
        if(curr < 0) curr = 0;
    }
    
    if(sum < 0){
        return max;
    } else{
        return max + (k - 2) * sum;
    }
  }

  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    int[] arr = new int[n];
    long sum = 0;
    for (int i = 0; i < arr.length; i++) {
      arr[i] = scn.nextInt();
      sum += arr[i];
    }
    int k = scn.nextInt();
    System.out.println(solution(arr, k, sum));
  }

}