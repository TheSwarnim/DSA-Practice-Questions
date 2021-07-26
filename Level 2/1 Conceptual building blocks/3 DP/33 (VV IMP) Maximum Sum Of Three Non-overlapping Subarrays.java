import java.io.*;
import java.util.*;

class Main {

	public static void solution(int[] arr, int k){
	    int n = arr.length, left[] = new int[n], right[] = new int[n], pSum[] = new int[n];;
	    int s1 = 0, s2 = 0;
	    for(int i = 0, j = n - 1; i < n; i++, j--){
	        pSum[i] = i == 0 ? arr[i] : arr[i] + pSum[i - 1];
	        
	        if(i < k){
	            s1 += arr[i];
	            left[i] = s1;
	        } else{
	            s1 += arr[i] - arr[i - k];
	            left[i] = Math.max(left[i - 1], s1);
	        }
	        
	        if(j >= n - k){
	            s2 += arr[j];
	            right[j] = s2;
	        } else{
	            s2 += arr[j] - arr[j + k];
	            right[j] = Math.max(right[j + 1], s2);
	        }
	    }
	    
	    int max = 0, mIdx = -1, lSum = -1, rSum = -1;
	    for(int i = k; i <= n - 2 * k; i++){
	        int val = left[i - 1] + right[i + k] + pSum[i + k - 1] - pSum[i - 1];
	        if(max < val){
	            max = val;
	            mIdx = i;
	            lSum = left[i - 1];
	            rSum = right[i + k];
	        }
	    }
	    
	    System.out.print(max + " ");
	    
	    for(int i = k - 1; i < mIdx; i++){
	        if(pSum[i] - (i - k < 0 ? 0 : pSum[i - k]) == lSum){
	            System.out.print((i - k + 1) + " ");
	            break;
	        }
	    }
	    
	    System.out.print(mIdx + " ");
	    
	    for(int i = mIdx + 2 * k - 1; i < n; i++){
	        if(pSum[i] - pSum[i - k] == rSum){
	            System.out.println((i - k + 1));
	            break;
	        }
	    }
	}
	
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int[] arr = new int[n];
		for(int i = 0 ; i < arr.length; i++){
			arr[i] = scn.nextInt();
		}
		int k = scn.nextInt();
		solution(arr,k);
	}

}