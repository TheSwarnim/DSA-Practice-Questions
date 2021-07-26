import java.io.*;
import java.util.*;

class Main3 {
    public static int scoreOfParentheses(String s) {
        Stack<Integer> st = new Stack<>();
        for(char ch : s.toCharArray()){
            if(ch == '('){
                st.push(-1);
            } else{
                int val = 0;
                while(st.peek() != -1){
                    val += (st.pop());
                }

                st.pop();
                if(val == 0){
                    st.push(1);
                } else{
                    st.push(val * 2);
                }
            }
            // System.out.println(st);
        }

        int val = 0;
        while(st.size() > 0){
            val += st.pop();
        }

        return val;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        int score = scoreOfParentheses(read.readLine());
        System.out.println(score);
        
    }
}
