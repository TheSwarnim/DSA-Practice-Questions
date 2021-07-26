import java.util.*;

public class Main {

    public static int solution(int[] arr) {
		int ans = 0;
		int zero = 0;
		int one = 0;
		int two = 0;

		var map = new HashMap<String, Integer>();
		map.put("0#0", 1);
	
		for (int i = 0; i < arr.length; i++) {
			if(arr[i] == 0){
				zero++;
			} else if(arr[i] == 1){
				one++;
			} else if(arr[i] == 2){
				two++;
			}

			String key = Integer.toString(two - one) + "#" + Integer.toString(one - zero);

			map.put(key, map.getOrDefault(key, 0) + 1);
			ans += map.get(key) - 1;
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
        System.out.println(solution(arr));

		scn.close();
    }

}
