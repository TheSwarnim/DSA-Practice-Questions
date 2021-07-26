import java.util.*;

public class Main {

	public static int solution(int[] arr) {
		int maxCnt = 0;
		for (int i = 0; i < arr.length - 1; i++) {
			int max = arr[i];
			int min = arr[i];
			int cnt = 1;

			var list = new ArrayList<Integer>();
			list.add(arr[i]);
			for(int j = i + 1; j < arr.length; j++) {
				if(list.contains(arr[j])) {
					break;
				}
				
				max = Math.max(max, arr[j]);
				min = Math.min(min, arr[j]);
				list.add(arr[j]);
				// System.out.println(max + " " + min + " " + (max - min) + " " + i + " " + j + " " + (j - i + 1));
				if(max - min == j - i) {
					cnt = j - i + 1;
				}
			}

			maxCnt = Math.max(maxCnt, cnt);
		}

		return maxCnt;
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
