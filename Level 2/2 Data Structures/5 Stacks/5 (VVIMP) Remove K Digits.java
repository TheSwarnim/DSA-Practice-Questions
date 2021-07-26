import java.io.*;
import java.util.*;

class Main5 {

    public static void main(String[] args) throws Exception {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        String num = read.readLine();
        int k = Integer.parseInt(read.readLine());

        // write your code here
        System.out.println(removeKdigits(num, k));
    }
    
    public static String removeKdigits(String num, int k) {
        int n = num.length();
        if(k==n)        
            return "0";
        
        Stack<Character> st = new Stack<>();
        
        for(int i = 0; i < n; i++){
            char c = num.charAt(i);
            while(k > 0 && st.size() > 0 && st.peek() > c){
                k--;
                st.pop();
            }
            st.push(c);
        }
        
        while(k > 0){
            st.pop();
        }        
        
        StringBuilder sb = new StringBuilder();
        for(char c : st) sb.append(c);
        
        while(sb.length() > 1 && sb.charAt(0) == '0'){
            sb.deleteCharAt(0);
        }
        
        return sb.toString();
    }
}