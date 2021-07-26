import java.util.*;

public class Main {

	public static int solution(int[] arr, int k){
        int ans = 0;

		int j = -1;
		int cnt = 0;
		for(int i = 0; i < arr.length; i++){
			if(arr[i] == 0){
				cnt++;
			}

			while(cnt > k){
				j++;
				if(arr[j] == 0){
					cnt--;
				}
			}

			int len = i - j;
			if(len > ans){
				ans = len;
			}
		}

		return ans;
    }
    
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] arr = new int[n];
        for(int i = 0 ; i  < n; i++){
            arr[i] = scn.nextInt();
        }
        int k = scn.nextInt();
        System.out.println(solution(arr,k));

		scn.close();
	}

}
