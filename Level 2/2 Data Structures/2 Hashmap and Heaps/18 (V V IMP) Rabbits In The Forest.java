import java.util.*;

public class Main {

    public static int solution(int[] arr) {
        var map = new HashMap<Integer, Integer>();
        int ans = 0;
        for(int i : arr) {
            map.put(i, map.getOrDefault(i, 0) + 1);
        }

        for(var k : map.keySet()) {
            int gs = k + 1;
            int reportees = map.get(k);

            int ng = (int)Math.ceil(reportees * 1.0 / gs * 1.0);
            ans += ng * gs;
        }

        return ans;
    }
    
    public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int n = scn.nextInt();
		int[] arr = new int[n];
		for(int i = 0 ; i < n; i++){
			arr[i] = scn.nextInt();
		}
		System.out.println(solution(arr));

        scn.close();
	}

}
