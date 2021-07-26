import java.util.*;

public class Main {
	public static void removeInMap(HashMap<Character, Integer>map, char c) {
		if(map.get(c) == 1) {
			map.remove(c);
		} else {
			map.put(c, map.get(c) - 1);
		}
	}

	public static int solutionfork1(String str){
		var map = new HashMap<Character, Integer>();
		int i = -1;
		int j = -1;
		int ttl = 0;

		while(true){
			boolean f1 = false, f2 = false;
			while(i < str.length() - 1){
				f1 = true;
				
				i++;

				char c = str.charAt(i);
				map.put(c, map.getOrDefault(c, 0) + 1);

				if(map.size() == 2){
					i--;
					removeInMap(map, c);
					break;
				}
			}

			while(j < i){
				f2 = true;

				ttl += i - j;

				j++;
				char ch = str.charAt(j);

				removeInMap(map, ch);

				if(map.size() == 0){
					break;
				}
			}

			if(!f1 && !f2){
				break;
			}
		}

		return ttl;
	}

	public static int solution(String str, int k){
		if(k == 1){
			return solutionfork1(str);
		}
		
		int ik = -1;
		int ikm1 = -1;
		int j = -1;
		int ans = 0;
		var mapk = new HashMap<Character, Integer>();
		var mapkm1 = new HashMap<Character, Integer>();

		while(true){
			boolean f1 = false, f2 = false, f3 = false;
			while(ik < str.length() - 1){
				f1 = true;
				ik++;
				char c = str.charAt(ik);

				mapk.put(c, mapk.getOrDefault(c, 0) + 1);

				if(mapk.size() == k + 1){
					ik--;
					removeInMap(mapk, c);
					break;
				}
			}

			while(ikm1 < str.length() - 1){
				f2 = true;
				ikm1++;
				char c = str.charAt(ikm1);

				mapkm1.put(c, mapkm1.getOrDefault(c, 0) + 1);

				if(mapkm1.size() == k){
					ikm1--;
					removeInMap(mapkm1, c);
					break;
				}
			}

			while(j < ikm1){
				f3 = true;
				
				ans += ik - ikm1;
				
				j++;
				char c = str.charAt(j);
				removeInMap(mapk, c);
				removeInMap(mapkm1, c);

				if(mapk.size() < k || mapkm1.size() < k - 1){
					break;
				}
			}

			if(!f1 && !f2 && !f3){
				break;
			}
		}

		return ans;
	}
	
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
        String str = scn.next();
        int k = scn.nextInt();
		System.out.println(solution(str,k));

		scn.close();
	}

}
