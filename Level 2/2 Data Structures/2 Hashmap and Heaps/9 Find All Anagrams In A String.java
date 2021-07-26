import java.util.*;

public class Main {
	public static void findAnagrams(String s, String p) {
        var m1 = new HashMap<Character, Integer>();
        var m2 = new HashMap<Character, Integer>();
		int ans = 0;
		var list = new ArrayList<Integer>();
		int j = -1;

		for(char ch : p.toCharArray()) {
			m2.put(ch, m2.getOrDefault(ch, 0) + 1);
		}

		for (int i = 0; i < s.length(); i++) {
			if(i < p.length() - 1) {
				char c = s.charAt(i);
				m1.put(c, m1.getOrDefault(c, 0) + 1);
			} else {
				char c_curr = s.charAt(i);
				char c_prev = s.charAt(i - p.length() + 1);
				m1.put(c_curr, m1.getOrDefault(c_curr, 0) + 1);

				if(m1.entrySet().equals(m2.entrySet())){
					ans++;
					list.add(i - p.length() + 1);
				}
				
				if(m1.get(c_prev) == 1){
					m1.remove(c_prev);
				} else {
					m1.put(c_prev, m1.get(c_prev) - 1);
				}
			}
		}

		System.out.println(ans);
		for (Integer in : list) {
			System.out.print(in + " ");
		}
	}

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String s = scn.next();
		String p = scn.next();
		findAnagrams(s, p);

		scn.close();
	}

}
