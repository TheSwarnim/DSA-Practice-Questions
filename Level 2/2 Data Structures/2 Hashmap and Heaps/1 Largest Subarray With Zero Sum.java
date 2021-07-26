import java.util.*;

public class Main {
	
	public static int solution(int[] arr) {
        Map<Integer, Integer> prefixSum = new HashMap<Integer, Integer>();
		
		int max = 0;
		int sum = 0;
		int i = -1;
		prefixSum.put(sum, i);
		while (i < arr.length - 1) {
			i++;
			sum += arr[i];
			if(!prefixSum.containsKey(sum)) {
				prefixSum.put(sum, i);
			} else {
				max = Math.max(max, (i) - prefixSum.get(sum));
			}
		}

		return max;
	}

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int[] arr = new int[scn.nextInt()];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = scn.nextInt();
		}
		System.out.println(solution(arr));

        scn.close();
	}

}
