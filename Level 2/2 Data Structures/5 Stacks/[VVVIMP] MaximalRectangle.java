import java.util.*;

class MaximalRectangle{
    int largestRectangleArea(int[] arr){
        Stack<Integer> st = new Stack<>();
        st.push(-1);
        
        int maxArea = 0;
        for(int i = 0; i <= arr.length; i++){
            int val = i == arr.length ? 0 : arr[i];
            while(st.peek() != -1 && arr[st.peek()] >= val){
                int rm = i;
                int h = arr[st.pop()];
                int lm = st.peek();
                maxArea = Math.max(maxArea, h * (rm - lm - 1));
            }
            st.push(i);
        }
        
        return maxArea;
    }
}