import java.io.*;
import java.util.*;

class Main6 {
    public static String removeDuplicateLetters(String s) {
        int n = s.length();
        int[] last = new int[26], seen = new int[26];
        
        for(int i = 0; i < n; i++){
            last[s.charAt(i) - 'a'] = i;
        }
        
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i < n; i++){
            int c = s.charAt(i) - 'a';
            
            if(seen[c]++ > 0) continue;
            
            while(st.size() > 0 && st.peek() > c && i < last[st.peek()]){
                seen[st.pop()] = 0;
            }
            
            st.push(c);
        }
        
        StringBuilder sb = new StringBuilder();
        for(int x : st) sb.append((char)(x + 'a'));
        
        return sb.toString();
    }

    public static void main(String[] args) throws Exception {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        String result = removeDuplicateLetters(read.readLine());
        System.out.println(result);
        
    }
}
