import java.util.*;

public class Main {

    public static String solution(int n, int d) {
        StringBuilder ans = new StringBuilder();
        int rem = 0;

        ans.append(Integer.toString(n / d));
        rem = n % d;

        if(rem == 0) {
            return ans.toString();
        } else {
            var map = new HashMap<Integer, Integer>();
            ans.append(".");
            int idx = ans.length();

            while(true) {
                if(rem == 0) {
                    break;
                }

                n = rem * 10;
                rem = n % d;
                
                if(map.containsKey(n)) {
                    idx = map.get(n);
                    ans.insert(idx, "(");
                    ans.append(")");
                    break;
                } else {
                    ans.append(Integer.toString(n / d));
                    map.put(n, idx);                    
                    idx++;
                }
            }
            return ans.toString();
        }
    }
    
    public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int num = scn.nextInt();
		int den = scn.nextInt();
		System.out.println(solution(num , den));

        scn.close();
	}

}
