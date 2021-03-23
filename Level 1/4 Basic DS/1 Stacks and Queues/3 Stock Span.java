import java.io.*;
import java.util.*;

public class Main{
  public static void display(int[] a){
    StringBuilder sb = new StringBuilder();

    for(int val: a){
      sb.append(val + "\n");
    }
    System.out.println(sb);
  }

public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    int[] a = new int[n];
    for(int i = 0; i < n; i++){
       a[i] = Integer.parseInt(br.readLine());
    }

    int[] span = solve(a);
    display(span);
 }

  public static int[] solve(int[] arr){
    // solve
    
    int n = arr.length;
    Stack<Integer> stack = new Stack<Integer>();

    int[] ans = new int[n];

    stack.push(0);
    ans[0] = 1;

    for (int i = 1; i < n; i++) {
      while(stack.size()>0 && arr[i]>arr[stack.peek()]){
        stack.pop();
      }

      // System.out.println("size: "+stack.size());
      if(stack.size()==0){
        ans[i] = i+1;
      }else{
        ans[i] = i-stack.peek();
      }
      
      stack.push(i);
    }
    
    return ans;
  }

}