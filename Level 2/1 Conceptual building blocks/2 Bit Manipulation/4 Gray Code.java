import java.util.*;

public class Main {

    public static List<Integer> grayCode(int n) {
        if(n==0){
            List<Integer> res = new ArrayList<Integer>();
            res.add(0);
            return res;
        }
        
        List<Integer> ans = new ArrayList<Integer>();
        ans.add(0);
        ans.add(1);

        for(int idx = 2; idx <= n; idx++){
            List<Integer> arr = new ArrayList<Integer>();

            for (int i = 0; i < ans.size(); i++) {
                arr.add(ans.get(i));
            }

            for(int i = ans.size()-1; i >= 0; i--){
                int val = ans.get(i) | 1<<(idx-1);
                arr.add(val);
            }

            ans = arr;
        }

        return ans;
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        List<Integer> ans=grayCode(scn.nextInt());
        Collections.sort(ans);
        System.out.println(ans);

        scn.close();
    }
}