import java.io.*;
import java.util.*;


public class Main {

	public static void solution(int[] arr){
		int cnt =0;

        for (int i = 0; i < arr.length; i++) {
            int val = arr[i];

            for (int k = i + 1; k < arr.length; k++) {
                val = val ^ arr[k];
                if(val == 0){
                    cnt += (k - i);
                }
            }
        }

        System.out.println(cnt);
    }
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
        int[] arr = new int[n];
        for(int i = 0 ; i < arr.length; i++){
            arr[i] = scn.nextInt();
        }
        solution(arr);
        scn.close();
    }
}