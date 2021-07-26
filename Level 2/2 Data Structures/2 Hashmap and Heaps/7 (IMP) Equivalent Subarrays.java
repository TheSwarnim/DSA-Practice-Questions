import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] arr = new int[n];
        for(int i = 0 ; i  < n; i++){
            arr[i] = scn.nextInt();
        }

		scn.close();
		//write your code here
		System.out.println(countEquivalentSubArrays(arr));
	}

	public static void removeInMap(HashMap<Integer, Integer> map, int val){
		if(map.get(val) == 1){
			map.remove(val);
		} else {
			map.put(val, map.get(val) - 1);
		}
	}

	public static int countEquivalentSubArrays(int[] arr) {
		int ans = 0;
		var set = new HashSet<Integer>();
		for(int i : arr) {
			set.add(i);
		}

		int unique = set.size();

		var map = new HashMap<Integer, Integer>();
		int i = -1, j = -1;

		while(true) {
			boolean f1 = false, f2 = false;
			while(i < arr.length - 1) {
				f1 = true;
				i++;

				map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);

				if(map.size() == unique){
					ans += arr.length - i;
					break;
				}
			}

			while(j < i){
				f2 = true;
				j++;

				removeInMap(map, arr[j]);
				
				if(map.size() < unique){
					break;
				} else if(map.size() == unique){
					ans += arr.length - i;
				}
			}

			if(!f1 && !f2){
				break;
			}
		}

		return ans;
	}
}
