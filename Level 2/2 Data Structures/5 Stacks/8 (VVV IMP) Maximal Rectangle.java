import java.io.*;
import java.util.*;

class Main8 {

    public static int maximalRectangle(int[][] ar) {                int m = ar.length, n = ar[0].length;
        int height[] = ar[0];
        
        int area = largestRectangleArea(height);
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                if(ar[i][j] == 0){
                    height[j] = 0;
                } else{
                    height[j]+=ar[i][j];
                }
            }
            
            area = Math.max(area, largestRectangleArea(height));
        }
        
        return area;
    }
    
    static int largestRectangleArea(int[] arr){
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

    public static void main(String[] args) throws Exception {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        int row = Integer.parseInt(read.readLine());
        int col = Integer.parseInt(read.readLine());
        
        int bmat[][] = new int[row][col];

        for(int i=0;i<row;i++){
            String s = read.readLine();
            for(int j=0;j<col;j++){
                bmat[i][j] = s.charAt(j)-'0';
            }
        }

        int result = maximalRectangle(bmat);
        System.out.println(result);
        
    }
}
