import java.util.*;

public class Main {

	public static String solution(String s1, String s2){
		HashMap<Character, Integer> s1freq = new HashMap<Character, Integer>();
		HashMap<Character, Integer> s2freq = new HashMap<Character, Integer>();
		
		for(char ch : s2.toCharArray()){
			s2freq.put(ch, s2freq.getOrDefault(ch, 0) + 1);
		}

		String ans = "";
		int mct = 0;
		int dmct = s2.length();
		int i = -1;
		int j = -1;
			
		while(true){
			boolean f1 = false;
			boolean f2 = false;
			// acquire
			while(i < s1.length() - 1 && mct < dmct){
				i++;
				char ch = s1.charAt(i);
				s1freq.put(ch, s1freq.getOrDefault(ch, 0) + 1);

				if(s1freq.getOrDefault(ch, 0) <= s2freq.getOrDefault(ch, 0)){
					mct++;
				}
				f1 = true;
			}

			// release and collect answer
			while(j < i && mct == dmct){
				String pans = s1.substring(j + 1, i + 1);
				if(ans.length() == 0 || pans.length() < ans.length()){
					ans = pans;
				}
				
				j++;
				char ch = s1.charAt(j);
				if(s1freq.get(ch) == 1){
					s1freq.remove(ch);
				} else {
					s1freq.put(ch, s1freq.get(ch) - 1);
				}

				if(s1freq.getOrDefault(ch, 0) < s2freq.getOrDefault(ch, 0)){
					mct--;
				}

				f2 = true;
			}

			if(!f1 && !f2){
				break;
			}
		}

		return ans;
	}

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String s1 = scn.next();
		String s2 = scn.next();
		System.out.println(solution(s1,s2));

		scn.close();
	}

}
