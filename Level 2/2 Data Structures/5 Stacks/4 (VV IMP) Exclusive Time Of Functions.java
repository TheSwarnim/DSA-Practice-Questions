import java.io.*;
import java.util.*;

class Main4 {

    public static void main(String[] args) throws Exception {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        List<String> li = new ArrayList<>();
        int n = Integer.parseInt(read.readLine());
        int log = Integer.parseInt(read.readLine());
        
        for(int i = 0; i < log; i++){
            li.add(read.readLine());
        }
        
        int[] ans = getAns(n, li);
        for(int x : ans){
            System.out.println(x);
        }
    }
    
    public static int[] getAns(int n, List<String> logs){
        int[] ans = new int[n];
        Stack<int[]> stack = new Stack<>();
        
        for(String log : logs){
            String[] p = log.split(":");
            int id = Integer.parseInt(p[0]);
            int time = Integer.parseInt(p[2]);
            
            if(p[1].equals("start")){
                stack.push(new int[]{id, time, 0});
            } else{
                int[] rem = stack.pop();
                int burst_time = time - rem[1] - rem[2] + 1;
                ans[id] += burst_time;
                
                if(stack.size() > 0){
                    stack.peek()[2] += time - rem[1] + 1;
                }
            }
        }
        
        return ans;
    }
}
