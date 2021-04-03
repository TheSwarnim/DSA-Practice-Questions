import java.util.*;

public class Main {

    public static void solve(String str){
        int n = str.length();

        for (int i = 0; i < (1 << n); i++) {
            StringBuilder sb = new StringBuilder();
            int cnt = 0;

            for (int j = 0; j < n; j++) {
                char ch = str.charAt(j);
                int bit = n - 1 - j;

                if((i & (1 << bit)) == 0){
                    if(cnt == 0){
                        sb.append(ch);
                    } else {
                        sb.append(cnt);
                        sb.append(ch);
                        cnt = 0;
                    }
                } else {
                    cnt++;
                }
            }

            if(cnt != 0){
                sb.append(cnt);
            }

            System.out.println(sb);
        }
    }
    
	public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String str = scn.nextLine();
        solve(str);
        scn.close();
    }
}