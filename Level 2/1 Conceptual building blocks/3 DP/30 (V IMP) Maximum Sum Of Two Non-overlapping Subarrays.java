import java.io.*;
import java.util.*;

class Main {

	public static int solution(int[] arr, int x, int y){
	    int n = arr.length;
	    int[] dp1 = new int[n];
	    int[] dp2 = new int[n];
	    
	    int s1 = 0, s2= 0;
	    for(int i = 0, j = n - 1; i < n && j >= 0; i++, j--){
	        if(i < x){
	            s1 += arr[i];
	            dp1[i] = s1;
	        } else{
	            s1 += arr[i] - arr[i - x];
	            dp1[i] = Math.max(s1, dp1[i - 1]);
	        }
	        
	        if(j >= n - y){
	            s2 += arr[j];
	            dp2[j] = s2;
	        } else{
	            s2 += arr[j] - arr[j + y];
	            dp2[j] = Math.max(s2, dp2[j + 1]);
	        }
	    }
	    
	    int ans= 0;
	    for(int i = x - 1; i < n - y; i++){
	        ans = Math.max(ans, dp1[i] + dp2[i + 1]);
	    }
	    
	    s1 = 0;
	    s2= 0;
	    for(int i = 0, j = n - 1; i < n && j >= 0; i++, j--){
	        if(i < y){
	            s1 += arr[i];
	            dp1[i] = s1;
	        } else{
	            s1 += arr[i] - arr[i - y];
	            dp1[i] = Math.max(s1, dp1[i - 1]);
	        }
	        
	        if(j >= n - x){
	            s2 += arr[j];
	            dp2[j] = s2;
	        } else{
	            s2 += arr[j] - arr[j + x];
	            dp2[j] = Math.max(s2, dp2[j + 1]);
	        }
	    }
	    
	    for(int i = y - 1; i < n - x; i++){
	        ans = Math.max(ans, dp1[i] + dp2[i + 1]);
	    }
	    
	    return ans;
	}
	
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int[] arr = new int[n];
		for(int i = 0 ; i < arr.length; i++){
			arr[i] = scn.nextInt();
		}
		int x = scn.nextInt();
		int y = scn.nextInt();
		System.out.println(solution(arr,x,y));
	}

}