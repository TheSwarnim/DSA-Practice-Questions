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
  }

  public static void solution(int[] arr){
    int xor = 0;

    for (int i = 0; i < arr.length; i++) {
        xor ^= arr[i];
    }

    int rsbm = xor & -xor;

    int x = 0;
    int y = 0;
    for(int val : arr){
        if((val & rsbm) == 0){
            x ^= val;
        } else {
            y ^= val;
        }
    }

    if(x > y){
        int temp = x;
        x = y;
        y = temp;
    }

    System.out.println(x + "\n" + y);
  }

}