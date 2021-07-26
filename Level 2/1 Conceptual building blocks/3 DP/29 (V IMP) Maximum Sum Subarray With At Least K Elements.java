import java.io.*;
import java.util.*;

class Main {

  public static int solution(int[] arr, int k) {
    int n = arr.length, curr = 0, sum = 0, maxVal = Integer.MIN_VALUE;
    int[] kadans = new int[n];
    for(int i = 0; i < n; i++){
        if(curr > 0) curr += arr[i];
        else curr = arr[i];
        kadans[i] = curr;
    }
    
    // System.out.println(Arrays.toString(kadans));
    for(int i = 0; i < k; i++){
        sum += arr[i];
    }
    maxVal = sum;
    for(int i = k; i < n; i++){
        sum += arr[i] - arr[i - k];
        maxVal = Math.max(maxVal, sum);
        maxVal = Math.max(maxVal, sum + kadans[i - k]);
    }
    
    return maxVal;
  }

  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    int[] arr = new int[n];
    for (int i = 0; i < arr.length; i++) {
      arr[i] = scn.nextInt();
    }
    int k = scn.nextInt();
    System.out.println(solution(arr, k));
  }
}