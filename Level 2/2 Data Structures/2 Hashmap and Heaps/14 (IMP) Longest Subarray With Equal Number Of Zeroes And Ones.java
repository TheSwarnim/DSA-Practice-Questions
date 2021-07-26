import java.util.*;

public class Main {

    public static int solution(int[] arr) {
		int sum = 0;
		int ans = 0;
		
		var m = new HashMap<Integer, Integer>();
		m.put(0, -1);

		for (int i = 0; i < arr.length; i++) {
			if(arr[i] == 0){
				sum += -1;
			} else{
				sum += 1;
			}
			if(m.containsKey(sum)){
				int idx = m.get(sum);
				int len = i - idx;
				if(len > ans){
					ans = len;
				}
			} else{
				m.put(sum, i);
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
        System.out.println(solution(arr));

		scn.close();
    }

}
