import java.util.*;

public class Main {

	public static int solution(String str) {
		int i = -1;
		int j = -1;
		HashMap<Character, Integer> map = new HashMap<Character, Integer>();
		int ans = 0;

		while(true){
			boolean f1 = false;
			boolean f2 = false;
			
			while(i < str.length() - 1){
				f1 = true;
				
				i++;
				char ch = str.charAt(i);
				
				map.put(ch, map.getOrDefault(ch, 0) + 1);

				if(map.get(ch) == 2){
					break;
				} else{
					ans += i - j;
				}
			}

			while(j < i){
				f2 = true;
				
				j++;
				char ch = str.charAt(j);
				
				if(map.get(ch) == 2){
					map.put(ch, 1);
					ans += i - j;
					break;
				} else{
					map.remove(ch);
				}
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
