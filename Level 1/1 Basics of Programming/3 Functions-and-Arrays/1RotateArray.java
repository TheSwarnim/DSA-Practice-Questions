import java.io.*;
import java.util.*;

/**
 * reverse(P1 + P2) = P2 + P1
 * rev(P1), rev(P2)
 * rev(P)
 * 
 * ie
 * part 1 ko alag sa reverse karo,
 * part2 ko alag sa reverse karo, 
 * fir pura array ko reverse karo
 */

public class Main{
  public static void display(int[] a){
    StringBuilder sb = new StringBuilder();

    for(int val: a){
      sb.append(val + " ");
    }
    System.out.println(sb);
  }

  public static void rotate(int[] a, int k){
    // write your code here
    k = k%a.length;
    if(k<0) k = k+a.length;
    
    // rev(part 1)
    reverse(a, 0, a.length - k - 1);
    
    // rev(part 2)
    reverse(a, a.length - k, a.length-1);
    
    // rev(arr)
    reverse(a, 0, a.length-1);

  }

  private static void reverse(int[] a, int l, int r){
      while(l<r){
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        l++;
        r--;
      }
  }

public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    int[] a = new int[n];
    for(int i = 0; i < n; i++){
       a[i] = Integer.parseInt(br.readLine());
    }
    int k = Integer.parseInt(br.readLine());

    rotate(a, k);
    display(a);
 }

}