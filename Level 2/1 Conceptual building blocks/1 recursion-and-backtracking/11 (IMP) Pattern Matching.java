import java.util.*;

public class Main {

	public static void solution(String str, String pattern, HashMap<Character,String> map, String op){
		// BASE CASE
		if(str.isEmpty() || pattern.isEmpty()){
			HashSet<Character> alreadyPrinted = new HashSet<Character>();
			if(str.isEmpty() && pattern.isEmpty()){
				for (int i = 0; i < op.length(); i++) {
					char ch = op.charAt(i);
					if(alreadyPrinted.contains(ch) == false){
						System.out.print(ch + " -> " + map.get(ch) + ", ");
					}
					alreadyPrinted.add(ch);
				}
				System.out.println(".");
			}

			return;
		}

		char ch = pattern.charAt(0);
		if(map.containsKey(ch)){
			String val = map.get(ch);
			int x = val.length();

			if(str.length() >= x && str.substring(0, x).equals(val)){
				// System.out.println(x + "->" + str.substring(0, x) + "--" + str.substring(x));
				solution(str.substring(x), pattern.substring(1), map, op);
			}
		} else {
			String val = "";
			
			for (int i = 0; i < str.length(); i++) {
				val += str.charAt(i);
				map.put(ch, val);

				solution(str.substring(i + 1), pattern.substring(1), map, op);
//  + ch + "->" + val + ", "
				map.remove(ch);
			}
		}
		// System.out.println(op);
	}

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		String pattern = scn.next();
		HashMap<Character,String> map = new HashMap<>();
		solution(str,pattern,map,pattern);

		scn.close();
	}
}