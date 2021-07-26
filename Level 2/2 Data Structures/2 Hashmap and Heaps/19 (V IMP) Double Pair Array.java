import java.util.*;

public class Main {

    public static boolean solution(int[] arr) {
        var count = new TreeMap<Integer, Integer>();
        for (int a : arr) {
            count.put(a, count.getOrDefault(a, 0) + 1);
        }

        for(int x : count.keySet()){
            if(count.get(x) == 0){
                continue;
            }
            int want = x < 0 ? x / 2 : x * 2;
            if (x < 0 && x % 2 != 0 || count.get(x) > count.getOrDefault(want, 0))
                return false;
            count.put(want, count.get(want) - count.get(x));
        }
        
        return true;
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
