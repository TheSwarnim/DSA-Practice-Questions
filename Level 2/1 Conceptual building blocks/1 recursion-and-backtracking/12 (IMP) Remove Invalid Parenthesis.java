import java.util.*;

public class Main {

	public static void solution(String str, int minRemoval, HashSet<String> ans) {
		if(minRemoval == 0) {
			if(isValid(str)){
				if(!ans.contains(str)){
					System.out.println(str);
					ans.add(str);
				}
			}

			return;
		}
		
		for (int i = 0; i < str.length(); i++) {
			String left = str.substring(0, i);
			String right = str.substring(i + 1);

			solution(left + right, minRemoval - 1, ans);
		}
	}

	public static boolean isValid(String str) {
		return getMin(str) == 0;
	}

	public static int getMin(String str){
		Stack<Character> st = new Stack<>();

		for (char ch : str.toCharArray()) {
			if(ch == '('){
				st.push(ch);
			} else if(ch == ')'){
				if(st.size() == 0){
					st.push(ch);
				} else if(st.peek() == ')'){
					st.push(ch);
				} else {
					st.pop();
				}
			}
		}

		return st.size();
	}

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		String str = scn.next();
		solution(str, getMin(str),new HashSet<>());

		scn.close();
	}
		
}