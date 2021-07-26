import java.util.*;

public class Main {

    public static int solution(int[] arr, int k) {
		int sum = 0;
		int ans= 0;
		int rem = 0;

		var map = new HashMap<Integer, Integer>();
		map.put(0, -1);

		for(int i = 0; i < arr.length; i++) {
			sum += arr[i];
			rem = sum % k;

			if(rem < 0){
				rem += k;
			}

			if(map.containsKey(rem)){
				int idx = map.get(rem);
				int len = i - idx;
				if(len > ans){
					ans = len;
				}
			} else {
				map.put(rem, i);
			}
		}

        return ans;
    }
    
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scn.nextInt();
        }
        int k = scn.nextInt();
        System.out.println(solution(arr, k));

		scn.close();
    }
}
