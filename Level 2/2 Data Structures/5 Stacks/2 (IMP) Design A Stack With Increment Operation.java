import java.io.*;
import java.util.*;

class Main2 {
    public static class CustomStack {
    
        int value[];
        int increment[];
        int idx;
        int n;
        
        public CustomStack(int maxSize) {
            value = new int[maxSize];
            increment = new int[maxSize];
            idx=-1;
            n = maxSize;
        }
        
        public void push(int x) {
            if(idx + 1 == n) return;
            idx++;
            value[idx] = x;
            increment[idx] = 0;
        }
        
        public int pop() {
            if(idx == -1){
                return -1;
            }
            
            int x = value[idx];
            int inc = increment[idx];
            idx--;
            if(idx >= 0){
                increment[idx] += inc;
            }
            return x + inc;
        }
        
        public void increment(int k, int val) {
            if(idx == -1) return;
            int index = Math.min(idx, k - 1);
            increment[index] += val;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));

        int maxsize = Integer.parseInt(read.readLine());

        CustomStack cs = new CustomStack(maxsize);
        
        while(true){
            String task[] = read.readLine().split(" ");
            if(task[0].equals("push")){
                cs.push(Integer.parseInt(task[1]));
            }else if(task[0].equals("pop")){
                System.out.println(cs.pop());
            }else if(task[0].equals("increment")){
                cs.increment(Integer.parseInt(task[1]), Integer.parseInt(task[2]));
            }else{
                break;
            }
        }
        System.out.println("exit");
    }
}