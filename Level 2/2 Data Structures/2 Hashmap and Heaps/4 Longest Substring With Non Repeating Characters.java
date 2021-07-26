import java.util.*;

public class Main {

	public static int solution(String str) {
		int cnt = 0;
		int i = -1;
		int j = -1;
		int ans = -1;
		HashMap<Character, Integer> map = new HashMap<Character, Integer>();

		while(true){
			boolean f1 = false;
			boolean f2 = false;
			while(i < str.length() - 1){
				f1 = true;

				i++;
				char c = str.charAt(i);
				map.put(c, map.getOrDefault(c, 0) + 1);
				
				if(map.get(c) == 1){
					cnt++;
					ans = Math.max(ans, cnt);
				} else {
					break;
				}

				// System.out.println(cnt);
			}	
			
			while(j < i){
				f2 = true;

				j++;
				char c = str.charAt(j);

				if(map.get(c) == 1){
					cnt--;
					map.remove(c);
				} else {
					map.put(c, map.get(c) - 1);
					break;
				}

				// System.out.println(cnt);
			}

			if(!f1 && !f2){
				break;
			}
		}

		return ans;
	}
	
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		System.out.println(solution(str));
		
		scn.close();
	}

}
