import java.io.*;
import java.util.*;

public class Main {

  public static void main(String[] args){
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    int[] arr = new int[n];
    for(int i = 0 ; i < n; i++){
      arr[i] = scn.nextInt();
    }
    solution(arr);

    scn.close();
  }

  public static void solution(int[] arr){
    int xor = 0;

    for (int i = 0; i < arr.length; i++) {
        xor ^= arr[i];
        xor ^= (i+1);
    }

    int rsbm = xor & -xor;
    int x = 0;
    int y = 0;
    for (int i = 0; i < arr.length; i++) {
        if((arr[i] & rsbm) == 0){
            x ^= arr[i];
        } else {
            y ^= arr[i];
        }

        if((((i + 1) & rsbm)) == 0){
            x ^= (i+1);
        } else {
            y ^= (i+1);
        }
    }

    for(int val : arr){
        if(val == x){
            System.out.println("Missing Number -> " + y);
            System.out.println("Repeating Number -> " + x);
            
            return;
        } else if(val == y){
            System.out.println("Missing Number -> " + x);
            System.out.println("Repeating Number -> " + y);

            return;
        }
    }
  }

}